#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <phonon>
#include <QFileDialog>
#include <QtGui>
#include <QDesktopServices>


namespace Ui {
    class VideoWidget;
}

class VideoWidget : public QWidget
{
    Q_OBJECT

public:
    VideoWidget(QWidget* parent =0);
    ~VideoWidget();

    QStringList fileNames;

    void init();

    void openFile();

    void playpause();
    bool isPlaying();
    void start();
    void setFiles(QStringList files);
    void toogleVisibility();
    bool isWidgetVisible();
    void do_style();
    bool change_video(bool next);

private:
    Ui::VideoWidget *ui;
    Phonon::SeekSlider *slider;
    Phonon::MediaObject m_MediaObject;
    Phonon::VideoWidget* m_videoW;
    Phonon::AudioOutput* m_AudioOutput;

    QList<Phonon::MediaSource> queue;

    bool playing;
    bool on_fullscreen;

    int current_play;

private slots:
    void on_button_prev_clicked();
    void on_button_next_clicked();
    void on_button_fastf_clicked();
    void on_button_fullscreen_clicked();
    void on_button_play2_clicked();
    void on_button_play_clicked();

};

#endif // VIDEOWIDGET_H
