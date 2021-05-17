#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMouseEvent>
#include <QImage>
#include <QColor>
#include <opencv2/opencv.hpp>
#include "bgmatting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace cv;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_pushButton_clicked();

    void on_save_pushButton_clicked();

    void on_openBG_pushButton_clicked();

    void on_setBGColor_pushButton_clicked();

    void on_run_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QString srcFileName;
    Mat srcImg;
    QImage qSrcImg;
    Mat tarImg;
    Mat backgroundImg;
    QColor bgColor;
    torch::Tensor pha;
    Mat new_bg;
    QString exeDir;

    BgMatting bgm;

    void mousePressEvent(QMouseEvent *event) override;
    void callImgBlend(const QString& str);

};
#endif // MAINWINDOW_H
