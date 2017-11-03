//CMainWindow.cpp
#include "CMainWidget.h"
#include "CTabWidget.h"
#include "CWidget.h"
#include <QtGui>
#include <QGridLayout>

CMainWidget::CMainWidget(QWidget *parent)
    : QWidget(parent)
{
    tabWidget = new CTabWidget(this);
    tabWidget->setMovable(true);
    tabWidget->setTabsClosable(true);
    tabWidget->setTabShape(QTabWidget::Rounded);

    connect(tabWidget->tabBar, &CTabBar::sig_tabDrag, this, &CMainWidget::slot_tabDrag);
    connect(tabWidget, &CTabWidget::tabCloseRequested, this, &CMainWidget::slot_closeTab);
    connect(tabWidget, &CTabWidget::currentChanged, tabWidget, &CTabWidget::setCurrentIndex);

    resize(800,600);
}

void CMainWidget::addWidTab(QWidget *pWid, QString strTab)
{
    tabWidget->addTab(pWid, strTab);
}

void CMainWidget::slot_tabDrag(int index,QPoint point)
{
    CWidget *widget = new CWidget;
    QWidget *draged = tabWidget->widget(index);
    QString windowName = tabWidget->tabText(index);
    tabWidget->removeTab(index);
    connect(widget,&CWidget::sig_doubleClickedTitleBar,this,&CMainWidget::slot_tabBarDoubleClicked);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(draged);
    widget->setLayout(layout);
    widget->resize(600,400);
    widget->move(point+pos()+tabWidget->pos());
    widget->setWindowTitle(windowName);
    widget->show();
    draged->show();
}

void CMainWidget::slot_tabBarDoubleClicked()
{
    CWidget *widget = qobject_cast<CWidget*>(sender());
    QObjectList list = widget->children();
    QWidget *edit = NULL;

    for(int i = 0;i<list.count();++i)
    {
        if(list[i]->inherits("QWidget"))
        {
            edit = qobject_cast<QWidget*>(list[i]);
            break;
        }
    }
    if(edit == NULL)
    {
        return ;
    }

    edit->setParent(tabWidget);
    tabWidget->addTab(edit,widget->windowTitle());
    widget->deleteLater();
}

void CMainWidget::slot_closeTab(int index)
{
    QWidget *draged = tabWidget->widget(index);
    tabWidget->removeTab(index);
    draged->deleteLater();
}
