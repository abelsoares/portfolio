#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include <QWidget>
#include <QVBoxLayout>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "QOpenCVWidget.h"
#include "bookviewerwidget.h"
#include "navigationwidget.h"

#include "glwidget.h"
#include "videowidget.h"

#define videoPath "NewtonLawsofMotion.mp4"

typedef int (*findImage)(IplImage* frame, const char* patt);

class QDeclarativeComponent;
class QGraphicsObject;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(CvCapture *cam, QWidget *parent = 0);
    ~MainWindow();
    findImage _findImage;
    bool detect;

public slots:
        void teste();
        void loadVideoWidget();
        void loadOglWidget();
        void closeVideo();
        void startVideoDetection();
        void startImageDetection();
private:
    Ui::MainWindow *ui;
    QOpenCVWidget *m_cvwidget;
    CvCapture *m_camera;
    void resizeLayout();

    /// conponents
    NavigationWidget* navigation;
    /// main container for widgets
    VideoWidget* videoWidget;
    BookViewerWidget* bookViewer;
    QGraphicsView* bookView;
    GLWidget* glw;
    QDeclarativeComponent* component;
    QGraphicsObject *object;
    QGraphicsObject *objectAnima;

protected:
    void timerEvent(QTimerEvent*);
    void resizeEvent(QResizeEvent *);

};

#endif // MAINWINDOW_H
