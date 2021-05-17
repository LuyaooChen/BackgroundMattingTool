QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += D:\opencv\build\include \
                            E:\Project\libtorch\include \
                            E:\Project\libtorch\include\torch\csrc\api\include

LIBS += \
    -LD:\opencv\build\x64\vc15\lib -lopencv_world3413 \
    -LE:\Project\libtorch\lib -ltorch -ltorch_cpu -lc10 -lasmjit -lclog -ldnnl -lgloo -lfbjni -lXNNPACK -lcaffe2_detectron_ops -lcaffe2_module_test_dynamic \
    -lcpuinfo -lfbgemm -llibprotobuf -llibprotobuf-lite -llibprotoc -lmkldnn -lpthreadpool -lpytorch_jni -lc10d

SOURCES += \
    bgmatting.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    bgmatting.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

#RC_ICONS = icon.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
