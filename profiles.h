#ifndef PROFILES_H
#define PROFILES_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class profiles;
}

class profiles : public QWidget
{
    Q_OBJECT

public:
    explicit profiles(QWidget *parent = nullptr);
    ~profiles();
    void modelo();
    void guardar();
    void cargar();
    void cargarLista();
    void cargarPerfil();
    void cargarInfo();
    QString perText(int const &x);

signals:
    void perfilAgregado();

public slots:
    void on_profilesBToMain_clicked();
    void cambiarPerfil();

private slots:
    void on_pushButton_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

private:
    Ui::profiles *ui;

};

#endif // PROFILES_H
