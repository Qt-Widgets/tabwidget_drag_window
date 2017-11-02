//CMainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTextEdit>
#include "CTabWidget.h"
#include "CTabBar.h"

class CMainWindow:public QMainWindow
{
    Q_OBJECT
public:
    CMainWindow(QWidget* = 0);
private:
    CTabWidget *tabWidget;
private slots:
    void slot_tabBarDoubleClicked();            //响应双击弹回的槽函数
    void slot_tabDrag(int index,QPoint point);  //响应拖动动作的槽函数
    void slot_closeTab(int);                    //关闭tab的槽函数
};

#endif // MAINWINDOW_H
