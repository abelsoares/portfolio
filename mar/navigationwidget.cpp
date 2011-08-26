#include "navigationwidget.h"

NavigationWidget::NavigationWidget()
{
     this->m_text = "my test text";
     this->setSizePolicy(QSizePolicy::Expanding,
                                   QSizePolicy::Expanding);

     view = new QDeclarativeView(this);
     view->setSizePolicy(QSizePolicy::Expanding,
                                    QSizePolicy::Expanding);

     QDeclarativeContext *context = view->rootContext();
     context->setContextProperty("sharedObject", this);

     view->setSource(QUrl::fromLocalFile("resources/qml/navigation.qml"));

     view->setStyleSheet("* { background-color: yellow }");
     view->setResizeMode(QDeclarativeView::SizeRootObjectToView	);
     view->show();
}


NavigationWidget::~NavigationWidget()
{
    delete view;
}
