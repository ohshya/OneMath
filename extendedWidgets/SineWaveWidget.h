#ifndef SINEWAVEWIDGET_H
#define SINEWAVEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

class SineWaveWidget : public QWidget
{
    Q_OBJECT

public:
    SineWaveWidget(QWidget *parent = nullptr);
    ~SineWaveWidget();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void update();

private:
    QTimer *timer;
    int xOffset;
};

#endif // SINEWAVEWIDGET_H
