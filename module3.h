#ifndef MODULE3_H
#define MODULE3_H

#include <QWidget>
#include <QTimer>
#include <QLabel>

namespace Ui {
class module3;
}

class module3 : public QWidget
{
    Q_OBJECT

public:
    explicit module3(QWidget *parent = nullptr);
    ~module3();
    void setBG();
    void actualizar();
    void aniText(QLabel *label, QString text);

private slots:
    void on_backModuleS_clicked();

    void on_anterior_clicked();

    void on_siguiente_clicked();

    void on_nextPart_clicked();

private:
    Ui::module3 *ui;
    QTimer* timer;
};

#endif // MODULE3_H
