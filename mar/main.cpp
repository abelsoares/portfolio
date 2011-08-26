#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <assert.h>
#include <QtGui/QApplication>
#include "mainwindow.h"
#include "QOpenCVWidget.h"
#include <QDebug>

//#define CAPTURE_AVI
int main(int argc, char *argv[])
{


#ifdef CAPTURE_AVI
    CvCapture * camera = cvCaptureFromAVI("D:\\Wildlife.wmv");
#else
    CvCapture * camera = cvCreateCameraCapture(0);
#endif

    QApplication app(argc, argv);
    MainWindow *mainWin = new MainWindow(camera);
    mainWin->setWindowTitle("Demo 0.1");
    mainWin->show();
    int retval = app.exec();

    cvReleaseCapture(&camera);
    return retval;
}
