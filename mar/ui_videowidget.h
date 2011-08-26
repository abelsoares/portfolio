/********************************************************************************
** Form generated from reading UI file 'videowidget.ui'
**
** Created: Wed 12. Jan 17:42:12 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWIDGET_H
#define UI_VIDEOWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
    QGridLayout *layout_slider;
    QPushButton *button_play2;
    QPushButton *button_fullscreen;
    QGridLayout *gridLayout_2;
    QPushButton *button_play;
    QPushButton *button_fastf;
    QPushButton *button_next;
    QPushButton *button_rev;
    QPushButton *button_prev;

    void setupUi(QWidget *VideoWidget)
    {
        if (VideoWidget->objectName().isEmpty())
            VideoWidget->setObjectName(QString::fromUtf8("VideoWidget"));
        VideoWidget->resize(718, 467);
        verticalLayout = new QVBoxLayout(VideoWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);

        verticalLayout->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        layout_slider = new QGridLayout();
        layout_slider->setObjectName(QString::fromUtf8("layout_slider"));

        gridLayout_3->addLayout(layout_slider, 0, 1, 1, 1);

        button_play2 = new QPushButton(VideoWidget);
        button_play2->setObjectName(QString::fromUtf8("button_play2"));

        gridLayout_3->addWidget(button_play2, 0, 0, 1, 1);

        button_fullscreen = new QPushButton(VideoWidget);
        button_fullscreen->setObjectName(QString::fromUtf8("button_fullscreen"));

        gridLayout_3->addWidget(button_fullscreen, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, -1, 0);
        button_play = new QPushButton(VideoWidget);
        button_play->setObjectName(QString::fromUtf8("button_play"));
        button_play->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(button_play, 0, 2, 1, 1);

        button_fastf = new QPushButton(VideoWidget);
        button_fastf->setObjectName(QString::fromUtf8("button_fastf"));

        gridLayout_2->addWidget(button_fastf, 0, 3, 1, 1);

        button_next = new QPushButton(VideoWidget);
        button_next->setObjectName(QString::fromUtf8("button_next"));

        gridLayout_2->addWidget(button_next, 0, 5, 1, 1);

        button_rev = new QPushButton(VideoWidget);
        button_rev->setObjectName(QString::fromUtf8("button_rev"));

        gridLayout_2->addWidget(button_rev, 0, 1, 1, 1);

        button_prev = new QPushButton(VideoWidget);
        button_prev->setObjectName(QString::fromUtf8("button_prev"));

        gridLayout_2->addWidget(button_prev, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(VideoWidget);

        QMetaObject::connectSlotsByName(VideoWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoWidget)
    {
        VideoWidget->setWindowTitle(QApplication::translate("VideoWidget", "Form", 0, QApplication::UnicodeUTF8));
        button_play2->setText(QString());
        button_fullscreen->setText(QString());
        button_play->setText(QString());
        button_fastf->setText(QString());
        button_next->setText(QString());
        button_rev->setText(QString());
        button_prev->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoWidget: public Ui_VideoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWIDGET_H
