#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#include <QWidget>

class module2test;
namespace Ui {
class conjuntos;
}

class conjuntos : public QWidget
{
    Q_OBJECT

public:
    explicit conjuntos(QWidget *parent = nullptr);
    ~conjuntos();

public slots:
    static void reiniciar(conjuntos* instance);

private slots:
    void on_con1_clicked();
    void on_con2_clicked();
    void on_con3_clicked();
    void on_con4_clicked();
    void on_con5_clicked();
    void on_con6_clicked();
    void on_con7_clicked();
    void on_con8_clicked();

private:
    Ui::conjuntos *ui;
};

#endif // CONJUNTOS_H
