#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QMoveEvent>

class MyButton : public QPushButton
{
public:
    MyButton(QWidget* parent = nullptr);

    ~MyButton() = default;

protected:

    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent* event) override;
    void moveEvent(QMoveEvent *event) override;
    void resizeEvent(QResizeEvent* event) override;

private:

    QPropertyAnimation* m_animation;
    QRect m_init_geometry;
    double m_duration;
    double m_extension;
};
#endif // MYBUTTON_H
