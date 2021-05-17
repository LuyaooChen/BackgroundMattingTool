#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QPoint>
#include <QPixmap>
#include <QColor>
#include <QMessageBox>
#include <QColorDialog>
#include <QDebug>

std::string qstr2str(const QString qstr)
{
    QByteArray cdata = qstr.toLocal8Bit();
    return std::string(cdata);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srcFileName="C:\\";
    exeDir = QCoreApplication::applicationDirPath();
    qDebug()<<QString("loading model: ")+exeDir+"\\weights\\torchscript_mobilenetv2_fp32.pth";
    bgm.load(qstr2str(exeDir)+"\\weights\\torchscript_mobilenetv2_fp32.pth");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QPoint label_pos = ui->src_label->mapFrom(this, event->pos());
        int x=label_pos.x();
        int y=label_pos.y();
//        qDebug()<<"x"<<x<<" y"<<y;
        if(x<0||x>=qSrcImg.width()||y<0||y>=qSrcImg.height()) return;
        bgColor = qSrcImg.pixelColor(x, y);
        QPixmap pixmap(ui->cursorColor_label->size());
        pixmap.fill(bgColor);
        ui->cursorColor_label->setPixmap(pixmap);
    }
}

void MainWindow::on_open_pushButton_clicked()
{
    srcFileName = QFileDialog::getOpenFileName(this,
                                            tr("选择图片"),
                                            "C:\\",
                                            tr("图像文件 (*.png *.jpg *.bmp)"));
    srcImg=imread(qstr2str(srcFileName));
    qSrcImg = QImage(srcImg.data,srcImg.cols,srcImg.rows,srcImg.cols * 3, QImage::Format_BGR888);
    ui->src_label->setGeometry(60,20,430,600);
    qSrcImg = qSrcImg.scaled(ui->src_label->size(),Qt::KeepAspectRatio);
    ui->src_label->setPixmap(QPixmap::fromImage(qSrcImg));
    ui->src_label->adjustSize();
}


void MainWindow::on_save_pushButton_clicked()
{
    if (tarImg.empty()) return;
    QString tarFileName = QFileDialog::getSaveFileName(this,
                                                    tr("选择保存路径"),
                                                    srcFileName,
                                                    tr("JPG文件 (*.jpg);;PNG文件 (*.png)"));
    if (tarFileName.isEmpty()) return;
    imwrite(qstr2str(tarFileName), tarImg);
}


void MainWindow::on_openBG_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("选择图片"),
                                                    "C:\\",
                                                    tr("图像文件 (*.png *.jpg *.bmp)"));
    backgroundImg=imread(qstr2str(fileName));
    QImage tmp(backgroundImg.data,
                       backgroundImg.cols,
                       backgroundImg.rows,
                       backgroundImg.cols * 3,
                       QImage::Format_BGR888);
    ui->bg_label->setPixmap(QPixmap::fromImage(tmp.scaled(ui->bg_label->size(),Qt::KeepAspectRatio)));
}


void MainWindow::on_setBGColor_pushButton_clicked()
{
    if(srcImg.empty())
    {
        QMessageBox::information(this,"Error","请先打开要处理的图片.");
        return;
    }
    QImage tmp(srcImg.cols, srcImg.rows, QImage::Format_BGR888);
    tmp.fill(bgColor);
    ui->bg_label->setPixmap(QPixmap::fromImage(tmp.scaled(ui->bg_label->size(),Qt::KeepAspectRatio)));
    backgroundImg = Mat(srcImg.rows, srcImg.cols, CV_8UC3, tmp.bits(), tmp.bytesPerLine());
    backgroundImg = backgroundImg.clone();
}

void MainWindow::on_run_pushButton_clicked()
{
    if (srcImg.empty())
    {
        QMessageBox::information(this, "Error", "请先打开要处理的图片.");
        return;
    }
    if (backgroundImg.empty())
    {
        QMessageBox::information(this, "Error", "请先设置原图背景图片.");
        return;
    }
    if(srcImg.rows!=backgroundImg.rows||srcImg.cols!=backgroundImg.cols)
    {
        QMessageBox::information(this, "Error", "原图和背景图尺寸不一致,请重新设置背景.");
        return;
    }

    const int rows = srcImg.rows;
    const int cols = srcImg.cols;
    Mat src_t, bg_t;
    if (rows % 4 != 0 || cols % 4 != 0) //网络输入尺寸必须是4的倍数
    {
        src_t = Mat((rows / 4 + 1) * 4, (cols / 4 + 1) * 4, CV_8UC3);
        Mat srcROI = src_t(Rect(0, 0, cols, rows));
        srcImg.copyTo(srcROI);

        bg_t = Mat((rows / 4 + 1) * 4, (cols / 4 + 1) * 4, CV_8UC3);
        Mat bgROI = bg_t(Rect(0, 0, cols, rows));
        backgroundImg.copyTo(bgROI);
    }
    else
    {
        src_t = srcImg;
        bg_t = backgroundImg;
    }

    const unsigned int img_size = rows * cols;
    bgm.setBackboneScale( sqrtf((1920*1080)/ (float)img_size) * 0.25);
    bgm.setRefineSamplePixels((float)img_size / (1920*1080) * 80000);

    pha = bgm.forward(src_t, bg_t);
    pha = pha.slice(0,0,srcImg.rows).slice(1,0,srcImg.cols);
    callImgBlend(ui->comboBox->currentText());

//    pha = pha(Rect(0, 0, cols, rows)).clone();
}

void MainWindow::callImgBlend(const QString &str)
{
    if(pha.sizes()[0]==0) return;
    if(str=="蓝底渐变")
    {
        new_bg = imread(qstr2str(exeDir)+"\\imgs\\blue.jpg");
        if(new_bg.empty()) return;
        cv::resize(new_bg, new_bg, Size(srcImg.cols, srcImg.rows));
        tarImg=bgm.imgBlend(new_bg, srcImg, pha);
    }
    else if(str=="灰底渐变")
    {
        new_bg = imread(qstr2str(exeDir)+"\\imgs\\gray.jpg");
        if(new_bg.empty()) return;
        cv::resize(new_bg, new_bg, Size(srcImg.cols, srcImg.rows));
        tarImg=bgm.imgBlend(new_bg, srcImg, pha);
    }
    else if(str=="红底渐变")
    {
        new_bg = imread(qstr2str(exeDir)+"\\imgs\\red.jpg");
        if(new_bg.empty()) return;
        cv::resize(new_bg, new_bg, Size(srcImg.cols, srcImg.rows));
        tarImg=bgm.imgBlend(new_bg, srcImg, pha);
    }
    else if(str=="白底")
    {
        QImage tmp(srcImg.cols, srcImg.rows, QImage::Format_BGR888);
        tmp.fill(QColorConstants::White);
        new_bg = Mat(srcImg.rows, srcImg.cols, CV_8UC3, tmp.bits(), tmp.bytesPerLine());
        tarImg=bgm.imgBlend(new_bg, srcImg, pha);
    }
    else if(str=="透明背景")
    {
        Mat pha_ = bgm.denormalize(pha,255);
//        pha_=pha*255;
//        pha_.convertTo(pha_, CV_8UC1);

        std::vector<Mat> channels;
        split(srcImg, channels);
        channels.push_back(pha_);
        merge(channels, tarImg);
    }
    else if(str=="从文件中选择...")
    {
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("选择图片"),
                                                        "C:\\",
                                                        tr("图像文件 (*.png *.jpg *.bmp)"));
        new_bg=imread(qstr2str(fileName));
        if(new_bg.empty()) return;
        cv::resize(new_bg, new_bg, Size(srcImg.cols, srcImg.rows));
        tarImg=bgm.imgBlend(new_bg, srcImg, pha);
    }
    else if(str=="选择纯色背景...")
    {
        QColor color_t = QColorDialog::getColor(Qt::white,this);
        QImage tmp(srcImg.cols, srcImg.rows, QImage::Format_BGR888);
        tmp.fill(color_t);
        new_bg = Mat(srcImg.rows, srcImg.cols, CV_8UC3, tmp.bits(), tmp.bytesPerLine());
        tarImg=bgm.imgBlend(new_bg, srcImg, pha);
    }

    if(tarImg.empty()) return;
    if(tarImg.channels()==3)
    {
        QImage tmp(tarImg.data, tarImg.cols, tarImg.rows, tarImg.cols * tarImg.channels(), QImage::Format_BGR888);
        ui->tar_label->setPixmap(QPixmap::fromImage(tmp.scaled(ui->tar_label->size(),Qt::KeepAspectRatio)));
    }
    else if(tarImg.channels()==4)
    {
        QImage tmp(tarImg.data, tarImg.cols, tarImg.rows, tarImg.cols * tarImg.channels(), QImage::Format_RGBA8888);
        tmp=tmp.rgbSwapped();
        ui->tar_label->setPixmap(QPixmap::fromImage(tmp.scaled(ui->tar_label->size(),Qt::KeepAspectRatio)));
    }
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    callImgBlend(arg1);
}

