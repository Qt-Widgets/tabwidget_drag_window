//main.cpp
#include "CMainWidget.h"
#include <QApplication>
//#include <QCleanlooksStyle>
#include <QTextEdit>
int main(int argc,char **argv)
{
    QApplication app(argc,argv);
//    QApplication::setStyle(new QCleanlooksStyle);
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    CMainWidget mainwindow;
    //Ìí¼Ó4¸ötabÒ³
    mainwindow.addWidTab(new QTextEdit,"eidt 1");
    mainwindow.addWidTab(new QTextEdit,"eidt 2");
    mainwindow.addWidTab(new QTextEdit,"eidt 3");
    mainwindow.addWidTab(new QTextEdit,"eidt 4");
    mainwindow.show();
    return app.exec();
}
