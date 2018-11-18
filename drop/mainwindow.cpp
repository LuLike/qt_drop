#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmdbutton.h"
#include "cmdsplitter.h"

#include <QSplitter>
#include <QTabWidget>
#include <QWidget>
#include <QGraphicsView>
#include <QScrollArea>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->showFullScreen();
    //初始化窗口部件
    m_pTabWidget=new QTabWidget;
    m_pTabWidget->resize(QSize(800,800));
    m_pOverviewWidget=new QWidget;
    m_pOverviewWidget->resize(QSize(800,800));
    m_pMainView = new QGraphicsView;
    m_pMainView->resize(QSize(800,800));
    m_pScrollArea = new QScrollArea;
    m_pScrollArea->resize(QSize(800,800));
    //使用splitter将窗口分为4部分
    QSplitter *splitter=new QSplitter(Qt::Horizontal);
    splitter->setStyleSheet("QSplitter::handle{background-color:rgb(175,175,175)}");
    splitter->setStretchFactor(0,5);
    splitter->setStretchFactor(1,6);

    QSplitter *splitter1=new QSplitter(Qt::Vertical);
    splitter1->addWidget(m_pTabWidget);
    splitter1->addWidget(m_pOverviewWidget);
    splitter1->setStretchFactor(0,1);
    splitter1->setStretchFactor(1,1);
    splitter->addWidget(splitter1);

    QSplitter *splitter2=new QSplitter(Qt::Vertical);
    splitter2->addWidget(m_pMainView);
    splitter2->setStretchFactor(0,7);
    splitter2->setStretchFactor(1,3);
    splitter->addWidget(splitter2);

    CmdSplitter *cmdSplitter=new CmdSplitter(Qt::Horizontal,splitter2);
    cmdSplitter->addWidget(m_pScrollArea);

    //QMainWindow中使用QSplitter的注意事项
    //Note: Creating a main window without a central widget is not supported. You must
    //have a central widget even if it is just a placeholder.
    QWidget *centerWindow = new QWidget;
    this->setCentralWidget(centerWindow);
    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addWidget(splitter);
    centerWindow->setLayout(mainLayout);

    QWidget *cadWidget = new QWidget;
    m_pTabWidget->addTab(cadWidget,QIcon(),QString("CAD"));

    CmdButton *cmdBtn=new CmdButton;
    cmdBtn->setText(QString("cmd Button"));
    cmdBtn->resize(QSize(100,50));
    QVBoxLayout *ovLayout=new QVBoxLayout;
    ovLayout->addWidget(cmdBtn);
    m_pOverviewWidget->setLayout(ovLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
