#include "mybutton.h"

MyButton::MyButton(QWidget* parent)
    : QPushButton(parent)
    , m_animation(nullptr)
    , m_init_geometry()
    , m_duration(200)
    , m_extension(300)
{
    m_animation = new QPropertyAnimation(this, "geometry", this);
    m_animation->setDuration(m_duration);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_init_geometry = geometry();
}

void MyButton::enterEvent(QEnterEvent *event)
{
    QPushButton::enterEvent(event);
    m_animation->stop();
    m_animation->setDuration(((m_init_geometry.width() + m_extension - width())/m_extension)*m_duration);
    m_animation->setStartValue(geometry());
    m_animation->setEndValue(QRectF(m_init_geometry.x(), m_init_geometry.y(), m_init_geometry.width() + m_extension, m_init_geometry.height()));
    m_animation->start();
}

void MyButton::leaveEvent(QEvent *event)
{
    QPushButton::leaveEvent(event);
    m_animation->stop();
    m_animation->setDuration(((width() - m_init_geometry.width())/m_extension)*m_duration);
    m_animation->setStartValue(geometry());
    m_animation->setEndValue(m_init_geometry);
    m_animation->start();
}

void MyButton::moveEvent(QMoveEvent *event)
{
    if(m_animation->state() == QPropertyAnimation::Running) return;
    QPushButton::moveEvent(event);
    m_init_geometry.setTopLeft(event->pos());
}

void MyButton::resizeEvent(QResizeEvent *event)
{
    if(m_animation->state() == QPropertyAnimation::Running) return;
    QPushButton::resizeEvent(event);
    m_init_geometry.setSize(event->size());
}
