#ifndef NAVIGATIONWIDGET_H
#define NAVIGATIONWIDGET_H
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QMessageBox>

class NavigationWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY buttonClicked)

public:
    NavigationWidget();

    ~NavigationWidget();

    QDeclarativeView* view;

    QString text() const { return m_text; }

    void setText(QString text)
    {
      m_text = text;
      emit buttonClicked();
    }
    Q_INVOKABLE void QmlBtClicked(int bt)
    {
        switch(bt)
        {
        case 1:
            //this->setText(QString("asd"));
            emit videoButtonClicked();
            //QMessageBox::information(NULL, "MainWindow::teste", "case 1:emit videoButtonClicked");
            break;
        case 2:
            emit oglButtonClicked();
            break;
        case 3:
            emit buttonClicked();
            QMessageBox::information(NULL, "MainWindow::teste", "case 3:emit buttonClicked");
            break;
        }
    }

signals:
    void buttonClicked();
    void videoButtonClicked();
    void oglButtonClicked();

private:
  QString m_text;
};

#endif // NAVIGATIONWIDGET_H
