#ifndef MODULE1_H
#define MODULE1_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class module1;
}

class module1 : public QWidget
{
    Q_OBJECT

public:
    explicit module1(QWidget *parent = nullptr);
    ~module1();
    void setBG();
    bool Cdecimal = false;
    int contadorOctalValue=0;
    int contadorValue = 0;

public slots:
    void on_backModuleS_clicked();
    void aniText(QLabel *label, QString text);
    void convertirDecimalABinario();
    void convertirBinarioADecimal();
    void calcularOperacionOctal();
    void actualizarResultado();
    void aumentarDecimal();
    void aumentarOctal();
    void actualizar();
    void titulo();
    void botones();

private slots:
    void on_nextPart_clicked();

private:
    QTimer* timer;
    Ui::module1 *ui;
};

#endif // MODULE1_H
