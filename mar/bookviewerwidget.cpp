#include "bookviewerwidget.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>
#include <QDeclarativeComponent>
#include <QDeclarativeEngine>
#include <QDeclarativeContext>

BookViewerWidget::BookViewerWidget(QWidget *parent)
{
    /// create the bookviewer widget
    QGraphicsScene* scene = new QGraphicsScene();
    //scene->setSceneRect(QRectF(0, 0, 200, 200));

    QDeclarativeEngine *engine = new QDeclarativeEngine;

    QDeclarativeContext *context = engine->rootContext();
    context->setContextProperty("textFromQt", QString("I love hybrid application!"));

    // expose it so QML can access it through name "bookViewerWidget"
    engine->rootContext()->setContextProperty("bookViewerWidget", this);

    this->component = new QDeclarativeComponent(engine, QUrl::fromLocalFile("resources/qml/leiNewton.qml"));
    this->object = qobject_cast<QGraphicsObject *>(component->create());

    this->component->loadUrl(QUrl::fromLocalFile("resources/qml/leiNewton2.qml"));
    this->objectAnima = qobject_cast<QGraphicsObject *>(component->create());
    this->objectAnima->hide();

    scene->addItem(object);
    scene->addItem(objectAnima);
    this->bookView = new QGraphicsView(scene);
}


BookViewerWidget::~BookViewerWidget()
{
    delete bookView;
}
