#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>
#include <QDeclarativeComponent>
#include <QDeclarativeEngine>
#include <QDeclarativeContext>
#include <QPushButton>
#include <QLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLibrary>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <QDebug>
using namespace std;

#define MAINCONTAINERWIDTH 0.5
#define windowIniX 100
#define windowIniY 100
#define windowIniWidth 800
#define windowIniHeight 600

MainWindow::MainWindow(CvCapture *cam, QWidget *parent) :
    QWidget(parent)
    //,
    //ui(new Ui::MainWindow)
{

    this->detect = false;
    /*   DLL LOAD   */
   // QLibrary mylib("FindImage"); // DLL file name to be loaded, including path
    QLibrary findImgDll;
    findImgDll.setFileName("D:/mar/demo_01/demo_01/release/FindImage.dll");
    bool okLoad = findImgDll.load(); // check load DLL file successful or not
    bool ok = findImgDll.isLoaded(); // check is DLL file loaded or not
    cout << ok << endl;
    cout << okLoad << endl;
    /*   \DLL LOAD   */
    if (okLoad)
    {
        qDebug() << "OK load";
      _findImage = (findImage) findImgDll.resolve("findImage");
    }else
    {
        qDebug() << "KO load";
       QMessageBox::information(NULL, "found", "found image");
   }


    /// create componentes
    this->navigation = new NavigationWidget();

    /// create the bookviewer widget
    this->bookViewer = new BookViewerWidget();

    /// connect events model
    QObject::connect(this->navigation, SIGNAL(buttonClicked()),
                         this, SLOT(teste()));
    QObject::connect(this->navigation, SIGNAL(videoButtonClicked()),
                         this, SLOT(startImageDetection()));//this, SLOT(loadVideoWidget()));
    QObject::connect(this->navigation, SIGNAL(oglButtonClicked()),
                         this, SLOT(startVideoDetection()));//this, SLOT(loadOglWidget()));

    QObject::connect(this->bookViewer, SIGNAL(closeBtClicked()),
                         this, SLOT(closeVideo()));

    //ui->setupUi(this);
    /// maximized app window
    this->setWindowState(Qt::WindowMaximized);

    /// custom app window size and position
    //this->setGeometry(windowIniX, windowIniY, windowIniWidth, windowIniHeight);

    /// setup the layout
    QGridLayout *layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setMargin(0);

    /// create the camera widget container
    QWidget *cameraWidgetContainer = new QWidget(this);
    cameraWidgetContainer->setSizePolicy(QSizePolicy::Minimum,
                                       QSizePolicy::Minimum);
    cameraWidgetContainer->setFixedSize(400, 400);
    cameraWidgetContainer->setStyleSheet("* { background-color: rgb(234, 231, 239) }");

    /// create the camera widget
    m_camera = cam;
    m_cvwidget = new QOpenCVWidget(cameraWidgetContainer);
    m_cvwidget->resize(400, 400);
    startTimer(100);  // 0.1-second timer


    QStringList fileNames;
         fileNames << videoPath;

    this->videoWidget = new VideoWidget(this->bookViewer->bookView);
    this->videoWidget->setGeometry(220,320,610,400);
    this->videoWidget->setFiles(fileNames);
    this->videoWidget->init();
    this->videoWidget->hide();

    this->glw = new GLWidget(this->bookViewer->bookView);
    this->glw->setGeometry(220,320,610,400);
    this->glw->hide();

    /// create the navigation container
    QWidget *navWidgetContainer = new QWidget(this);
    navWidgetContainer->setSizePolicy(QSizePolicy::Minimum,
                                       QSizePolicy::Expanding);
    navWidgetContainer->setStyleSheet("* { background-color: rgb(165, 152, 186) }");

    /// navigation widget
    this->navigation->setParent(navWidgetContainer);

    /// add widgets to the grid layout
    layout->addWidget(cameraWidgetContainer, 0, 0);
     //layout->addWidget(contentWidgetContainer, 0, 1, 0, 1);
    layout->addWidget(this->bookViewer->bookView, 0, 1, 0, 1);
    layout->addWidget(navWidgetContainer, 1, 0);
    setLayout(layout);

    this->resizeLayout();
}

void MainWindow::startVideoDetection()
{
    this->detect = true;
}

void MainWindow::startImageDetection()
{
    this->detect = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::loadOglWidget()
{
    this->bookViewer->object->hide();
    this->bookViewer->objectAnima->show();
    this->resizeLayout();
    if(this->videoWidget->isPlaying())
    {
        this->videoWidget->playpause();
    }
    this->videoWidget->hide();
    this->glw->show();
    QObject *rect = this->bookViewer->object->findChild<QObject*>("overlay");
    if (rect)
        rect->setProperty("opacity", "0");
    QObject *overlay_bt = this->bookViewer->object->findChild<QObject*>("overlay_bt");
    if (overlay_bt)
        overlay_bt->setProperty("opacity", "0");
    QObject *overlay_text = this->bookViewer->object->findChild<QObject*>("overlay_text");
    if (overlay_text)
        overlay_text->setProperty("opacity", "0");

    QObject *rectAnima = this->bookViewer->objectAnima->findChild<QObject*>("overlay");
    if (rectAnima)
        rectAnima->setProperty("opacity", "0,9");
    QObject *overlay_btAnima = this->bookViewer->objectAnima->findChild<QObject*>("overlay_bt");
    if (overlay_btAnima)
        overlay_btAnima->setProperty("opacity", "0,9");
    QObject *overlay_textAnima = this->bookViewer->objectAnima->findChild<QObject*>("overlay_text");
    if (overlay_textAnima)
        overlay_textAnima->setProperty("opacity", "0,9");
}

void MainWindow::closeVideo()
{
    if(this->videoWidget->isPlaying())
    {
        this->videoWidget->playpause();
    }
    this->videoWidget->hide();
    this->glw->hide();

    QObject *rect = this->bookViewer->object->findChild<QObject*>("overlay");
    if (rect)
        rect->setProperty("opacity", "0");
    QObject *overlay_bt = this->bookViewer->object->findChild<QObject*>("overlay_bt");
    if (overlay_bt)
        overlay_bt->setProperty("opacity", "0");
    QObject *overlay_text = this->bookViewer->object->findChild<QObject*>("overlay_text");
    if (overlay_text)
        overlay_text->setProperty("opacity", "0");

    QObject *rectAnima = this->bookViewer->objectAnima->findChild<QObject*>("overlay");
    if (rectAnima)
        rectAnima->setProperty("opacity", "0");
    QObject *overlay_btAnima = this->bookViewer->objectAnima->findChild<QObject*>("overlay_bt");
    if (overlay_btAnima)
        overlay_btAnima->setProperty("opacity", "0");
    QObject *overlay_textAnima = this->bookViewer->objectAnima->findChild<QObject*>("overlay_text");
    if (overlay_textAnima)
        overlay_textAnima->setProperty("opacity", "0");
}

void MainWindow::loadVideoWidget()
{
    this->bookViewer->objectAnima->hide();
    this->bookViewer->object->show();
    this->glw->hide();
    this->videoWidget->playpause();
    this->videoWidget->show();
    QObject *rect = this->bookViewer->object->findChild<QObject*>("overlay");
    if (rect)
        rect->setProperty("opacity", "0,9");
    QObject *overlay_bt = this->bookViewer->object->findChild<QObject*>("overlay_bt");
    if (overlay_bt)
        overlay_bt->setProperty("opacity", "0,9");
    QObject *overlay_text = this->bookViewer->object->findChild<QObject*>("overlay_text");
    if (overlay_text)
        overlay_text->setProperty("opacity", "0,9");

    QObject *rectAnima = this->bookViewer->objectAnima->findChild<QObject*>("overlay");
    if (rectAnima)
        rectAnima->setProperty("opacity", "0");
    QObject *overlay_btAnima = this->bookViewer->objectAnima->findChild<QObject*>("overlay_bt");
    if (overlay_btAnima)
        overlay_btAnima->setProperty("opacity", "0");
    QObject *overlay_textAnima = this->bookViewer->objectAnima->findChild<QObject*>("overlay_text");
    if (overlay_textAnima)
        overlay_textAnima->setProperty("opacity", "0");
}

void MainWindow::teste()
{
    QMessageBox::information(NULL, "MainWindow::teste", "Invoking a MainWindow::teste");
}

void MainWindow::timerEvent(QTimerEvent*)
{
    IplImage *image=cvQueryFrame(m_camera);
    m_cvwidget->putImage(image);

    if(this->detect)
    {
        if(_findImage(image,"D:/mar/demo_01/demo_01/release/capalivro2.png"))
        {
            this->loadVideoWidget();
            this->detect = false;
        }
    }

}

void
MainWindow::resizeEvent(QResizeEvent *event)
{
    this->resizeLayout();
}


void
MainWindow::resizeLayout()
{
    int mainContainerWitdh = MAINCONTAINERWIDTH*this->width();
    int cameraContainerWitdh = (1 - MAINCONTAINERWIDTH)*this->width();
}
