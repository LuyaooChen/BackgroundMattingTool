/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *src_label;
    QLabel *tar_label;
    QPushButton *open_pushButton;
    QPushButton *save_pushButton;
    QPushButton *openBG_pushButton;
    QLabel *bg_label;
    QLabel *cursorColor_label;
    QPushButton *setBGColor_pushButton;
    QPushButton *run_pushButton;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QFrame *line_11;
    QFrame *line_12;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        src_label = new QLabel(centralwidget);
        src_label->setObjectName(QString::fromUtf8("src_label"));
        src_label->setGeometry(QRect(60, 20, 430, 600));
        tar_label = new QLabel(centralwidget);
        tar_label->setObjectName(QString::fromUtf8("tar_label"));
        tar_label->setGeometry(QRect(780, 20, 430, 600));
        open_pushButton = new QPushButton(centralwidget);
        open_pushButton->setObjectName(QString::fromUtf8("open_pushButton"));
        open_pushButton->setGeometry(QRect(60, 640, 89, 24));
        save_pushButton = new QPushButton(centralwidget);
        save_pushButton->setObjectName(QString::fromUtf8("save_pushButton"));
        save_pushButton->setGeometry(QRect(960, 640, 89, 24));
        openBG_pushButton = new QPushButton(centralwidget);
        openBG_pushButton->setObjectName(QString::fromUtf8("openBG_pushButton"));
        openBG_pushButton->setGeometry(QRect(270, 630, 101, 24));
        bg_label = new QLabel(centralwidget);
        bg_label->setObjectName(QString::fromUtf8("bg_label"));
        bg_label->setGeometry(QRect(560, 380, 150, 210));
        cursorColor_label = new QLabel(centralwidget);
        cursorColor_label->setObjectName(QString::fromUtf8("cursorColor_label"));
        cursorColor_label->setGeometry(QRect(390, 680, 31, 31));
        setBGColor_pushButton = new QPushButton(centralwidget);
        setBGColor_pushButton->setObjectName(QString::fromUtf8("setBGColor_pushButton"));
        setBGColor_pushButton->setGeometry(QRect(270, 680, 101, 24));
        run_pushButton = new QPushButton(centralwidget);
        run_pushButton->setObjectName(QString::fromUtf8("run_pushButton"));
        run_pushButton->setGeometry(QRect(580, 300, 101, 24));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(60, 20, 430, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(60, 620, 430, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(490, 20, 3, 600));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(60, 20, 3, 600));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(780, 20, 430, 3));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(780, 20, 3, 600));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(780, 620, 430, 3));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(1210, 20, 3, 600));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(560, 380, 150, 3));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(centralwidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(560, 380, 3, 210));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);
        line_11 = new QFrame(centralwidget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(560, 590, 150, 3));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);
        line_12 = new QFrame(centralwidget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(710, 380, 3, 210));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(780, 640, 131, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 645, 21, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 680, 191, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 659, 21, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(560, 304, 21, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(760, 640, 21, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(940, 646, 21, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(310, 659, 21, 16));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\203\214\346\231\257\346\212\240\345\233\276\345\267\245\345\205\267", nullptr));
        src_label->setText(QCoreApplication::translate("MainWindow", "\345\216\237\345\233\276\345\203\217", nullptr));
        tar_label->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\345\220\216\347\232\204\345\233\276\345\203\217", nullptr));
        open_pushButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        save_pushButton->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        openBG_pushButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\350\203\214\346\231\257\345\233\276\347\211\207", nullptr));
        bg_label->setText(QCoreApplication::translate("MainWindow", "\350\203\214\346\231\257\345\233\276\347\211\207", nullptr));
        cursorColor_label->setText(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262", nullptr));
        setBGColor_pushButton->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262", nullptr));
        run_pushButton->setText(QCoreApplication::translate("MainWindow", "->\346\212\240\345\233\276->", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\350\223\235\345\272\225\346\270\220\345\217\230", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\347\201\260\345\272\225\346\270\220\345\217\230", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\347\272\242\345\272\225\346\270\220\345\217\230", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\347\231\275\345\272\225", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\351\200\217\346\230\216\350\203\214\346\231\257", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\344\270\255\351\200\211\346\213\251...", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\347\272\257\350\211\262\350\203\214\346\231\257...", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "1.", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "2.\351\274\240\346\240\207\347\202\271\345\207\273\345\233\276\347\211\207\345\217\257\351\200\211\346\213\251\351\242\234\350\211\262", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "3.", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "4.", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "5.", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "6.", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\210\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
