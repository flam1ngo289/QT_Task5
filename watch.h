#ifndef WATCH_H
#define WATCH_H

#include <QObject>
#include <QTime>
#include <QTimer>

class watch : public QObject
{
public:
    explicit Watch(QObject *parent = nullptr);
        void start();
        void stop();
        QTime diff();
        void clear();
        ~Watch();
        QTime look_time();

    private:
        int cir_n = 1;
        QTimer *timer;
        QTime time_second = QTime(0,0,0,0);
        QTime old_circle = QTime(0,0,0,0);
        QTime new_circle = QTime(0,0,0,0);
        QTime diff_circle = QTime(0,0,0,0);
        const QTime null_time = QTime(0,0,0,0);

    public slots:
        void slotTimerAlarm();
    signals:
        void time_signal_start();
        void time_signal();
};

#endif // WATCH_H
