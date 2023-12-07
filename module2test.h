#ifndef MODULE2TEST_H
#define MODULE2TEST_H

#include <QWidget>
#include <QTimer>
#include <QSet>
#include <QLabel>

class conjuntos;
namespace Ui {
class module2test;
}

class module2test : public QWidget
{
    Q_OBJECT

public:
    explicit module2test(QWidget *parent = nullptr);
    ~module2test();
    void progressB();
    void aniText(QLabel *label, QString text);
    QString okstyle = QString("#nextPart{ \
                            image: url(:/buttons/buttons/ok.png);   \
                            background: transparent;}               \
                            #nextPart:hover{                        \
                            image: url(:/buttons/buttons/okH.png);} \
                            #nextPart:pressed{                      \
                            image: url(:/buttons/buttons/okP.png);} \
                            #nextPart:disabled{                     \
                            image: url(:/buttons/buttons/okD.png);}");

    void update();
    QSet<int> listaRandoms;
    int numeroAleatorio = 0;
    void correcto();
    void incorrecto();

private slots:
    void on_backModuleS_clicked();
    void on_nextPart_clicked();
    void on_conjuntoA_clicked();
    void on_conjuntoB_clicked();
    void on_conjuntoC_clicked();
    void on_op1_clicked();
    void on_op2_clicked();
    void on_op3_clicked();
    void on_op4_clicked();
    void on_op5_clicked();
    void on_mostrar1_clicked();
    void on_mostrar2_clicked();
    void on_comprobar_clicked();

private:
    QTimer* timer;
    Ui::module2test *ui;
};

#endif // MODULE2TEST_H
