#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <QWidget>
#include <QCheckBox>
#include <mainwindow.h>
#include <extendedWidgets/switch.h>

class MainWindow;
namespace Ui {
class configuracion;
}

class configuracion : public QWidget
{
    Q_OBJECT

public:
    explicit configuracion(QWidget *parent = nullptr);
    ~configuracion();

public slots:
    void on_configBToMain_clicked();
    void toggleControl(int state);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::configuracion *ui;
};

#endif // CONFIGURACION_H
