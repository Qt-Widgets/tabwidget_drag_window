//CMainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "CTabWidget.h"
#include "CTabBar.h"
#include <QTabWidget>

class CMainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CMainWidget(QWidget* = 0);
    void addWidTab(QWidget* pWid, QString strTab);
private:
    CTabWidget *tabWidget;
private slots:
    void slot_tabBarDoubleClicked();            //响应双击弹回的槽函数
    void slot_tabDrag(int index, QPoint point);  //响应拖动动作的槽函数
    void slot_closeTab(int);                    //关闭tab的槽函数
};

#endif // MAINWINDOW_H
