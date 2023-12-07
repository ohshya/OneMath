#ifndef MODULE2_H
#define MODULE2_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

namespace Ui {
class module2;
}

class module2 : public QWidget
{
    Q_OBJECT

public:
    explicit module2(QWidget *parent = nullptr);
    ~module2();
    void setBG();
    void actualizar();
    void aniText(QLabel *label, QString text);

private slots:
    void on_backModuleS_clicked();
    void on_stack0_clicked();
    void on_stack1_clicked();
    void on_stack2_clicked();
    void on_stack3_clicked();
    void on_stack4_clicked();
    void on_nextPart_clicked();

private:
    QTimer* timer;
    Ui::module2 *ui;
};

#endif // MODULE2_H
