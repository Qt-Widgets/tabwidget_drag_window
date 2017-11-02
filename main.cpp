//main.cpp
#include "CMainWindow.h"
#include <QApplication>
//#include <QCleanlooksStyle>

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
//    QApplication::setStyle(new QCleanlooksStyle);
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    CMainWindow mainwindow;
    mainwindow.show();
    return app.exec();
}
