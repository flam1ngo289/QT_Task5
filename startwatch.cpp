#include "startwatch.h"

Startwatch::Startwatch(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &Startwatch::slotTimerAlarm);
}

Startwatch::~Startwatch() {}

QTime Startwatch::look_time()
{
    return time_second;
}

void Startwatch::slotTimerAlarm() {
    time_second = time_second.addMSecs(100);
    emit time_signal();
}

void Startwatch::start() {
    timer->start(100);
    emit void time_signal_start();
}

void Startwatch::stop() {
    timer->stop();
    emit void time_signal_start();
}

QTime Startwatch::diff() {
    old_circle = new_circle;
    int second = old_circle.msecsTo(time_second);
    new_circle = time_second;
    diff_circle = null_time;
    diff_circle = diff_circle.addMSecs(second);
    return diff_circle;
}

void Startwatch::clear() {
    time_second = null_time;
    old_circle = null_time;
    new_circle = null_time;
}
