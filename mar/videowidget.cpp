#include "videowidget.h"
#include "ui_videowidget.h"


VideoWidget::VideoWidget(QWidget *parent) :
       // QWidget(parent),
     ui(new Ui::VideoWidget)
{

    this->setParent(parent);
    ui->setupUi(this);

}

bool VideoWidget::isPlaying()
{
    return this->playing;
}

void VideoWidget::init()
{
    m_AudioOutput = new Phonon::AudioOutput(Phonon::VideoCategory, this);
    m_videoW = new Phonon::VideoWidget(this);
    Phonon::Path path = Phonon::createPath(&m_MediaObject, m_AudioOutput);
    Phonon::createPath(&m_MediaObject,m_videoW);
    ui->gridLayout->addWidget(m_videoW);
    slider = new Phonon::SeekSlider(this);
    slider->setMediaObject(&m_MediaObject);
    //slider->setStyle();

    //connect(m_videoW,SIGNAL(clicked()),this,SLOT(on_button_fullscreen_clicked()) );

    ui->layout_slider->addWidget(slider);

    do_style();

    openFile();

    playing = false;
    on_fullscreen = false;
}

void VideoWidget::toogleVisibility()
{
    QWidget* widget = dynamic_cast<QWidget*>(this);
    if(widget->isVisible())
        widget->hide();
    else
        widget->show();
}
bool VideoWidget::isWidgetVisible()
{
    QWidget* widget = dynamic_cast<QWidget*>(this);
    if(widget->isVisible())
        return true;
    else
        return false;
}

void VideoWidget::setFiles(QStringList files)
{
    fileNames = files;
}

void VideoWidget::do_style()
{
    //info->setStyleSheet("border-image:url(:/images/screen.png) ; border-width:3px");
    ui->button_play->setIcon((style()->standardIcon(QStyle::SP_MediaPlay)));
    ui->button_play2->setIcon((style()->standardIcon(QStyle::SP_MediaPlay)));
    ui->button_fastf->setIcon((style()->standardIcon(QStyle::SP_MediaSeekForward)));
    ui->button_rev->setIcon((style()->standardIcon(QStyle::SP_MediaSeekBackward)));
    ui->button_fullscreen->setIcon((style()->standardIcon(QStyle::SP_MediaVolume)));
    ui->button_next->setIcon((style()->standardIcon(QStyle::SP_MediaSkipForward)));
    ui->button_prev->setIcon((style()->standardIcon(QStyle::SP_MediaSkipBackward)));



}
VideoWidget::~VideoWidget()
{
    delete m_AudioOutput;
    delete m_videoW;
    delete ui;
}

void VideoWidget::openFile()
{
    m_MediaObject.clearQueue();

    if (fileNames.size() > 0) {
        //QString fileName = fileNames[0];
     //   setFile(fileName);
        for (int i=0; i<fileNames.size(); i++)
        {
            queue.append(Phonon::MediaSource(fileNames[i]));
            m_MediaObject.enqueue(Phonon::MediaSource(fileNames[i]));
        }
    }
    //queue = m_MediaObject.queue();
    current_play=0;
    //m_MediaObject.enqueue(Phonon::MediaSource("C:\\Users\\Public\\Videos\\Sample Videos\\Wildlife.wmv"));

}

void VideoWidget::playpause()
{
    //change icons

    if(playing)
    {
        m_MediaObject.pause();
        ui->button_play->setIcon((style()->standardIcon(QStyle::SP_MediaPlay)));
        ui->button_play2->setIcon((style()->standardIcon(QStyle::SP_MediaPlay)));

    }
    else
    {
        m_MediaObject.play();
        ui->button_play->setIcon((style()->standardIcon(QStyle::SP_MediaPause)));
        ui->button_play2->setIcon((style()->standardIcon(QStyle::SP_MediaPause)));
    }

    playing=!playing;
}

void VideoWidget::on_button_play_clicked()
{

    playpause();
}





void VideoWidget::on_button_play2_clicked()
{
    playpause();
}

void VideoWidget::on_button_fullscreen_clicked()
{
    m_videoW->setFullScreen(true);
    on_fullscreen = true;
}

void VideoWidget::start()
{

}

void VideoWidget::on_button_fastf_clicked()
{
    m_MediaObject.setTickInterval(50);
   // m_MediaObject.seek(0);

}

void VideoWidget::on_button_next_clicked()
{
    change_video(true);
}

void VideoWidget::on_button_prev_clicked()
{
    change_video(false);
}

bool VideoWidget::change_video(bool next)
{
    if(next)//next video
    {
        if(queue.size()==0)return false; //only one video

        current_play++;

        current_play%=queue.size();

        m_MediaObject.setCurrentSource(queue[current_play]);

        m_MediaObject.play();
    }
    else// prev video
    {
        if(!playing)
        {
            current_play--;
            current_play%=queue.size();
            m_MediaObject.setCurrentSource(queue[current_play]);
            m_MediaObject.play();
            playpause();
        }
        else
        {
            m_MediaObject.seek(0);
            m_MediaObject.pause();
            playpause();
        }
    }
    return true;
}


