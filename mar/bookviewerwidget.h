#ifndef BOOKVIEWERWIDGET_H
#define BOOKVIEWERWIDGET_H
#include <QDeclarativeView>
#include <QMessageBox>
class QDeclarativeComponent;
class QGraphicsObject;
class QGraphicsView;

class BookViewerWidget : public QWidget
{
    Q_OBJECT

public:
        BookViewerWidget(QWidget* parent =0);
        ~BookViewerWidget();
        void start();
        void toogleVisibility();
        bool isWidgetVisible();

        QGraphicsView* bookView;
        QDeclarativeComponent* component;
        QGraphicsObject *object;
        QGraphicsObject *objectAnima;

        Q_INVOKABLE void QmlCloseBtClicked()
        {
            emit closeBtClicked();
        }
signals:
        void closeBtClicked();
};

#endif // BOOKVIEWERWIDGET_H
