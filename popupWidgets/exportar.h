#ifndef EXPORTAR_H
#define EXPORTAR_H

#include "mainWidgets/profiles.h"
#include <QDialog>

namespace Ui {
class Exportar;
}

class Exportar : public QDialog
{
    Q_OBJECT

public:
    explicit Exportar(QWidget *parent = nullptr);
    ~Exportar();

private slots:

    void on_allExport_clicked();

    void on_profileExport_clicked();

private:
    profiles* profilesInstance;
    Ui::Exportar *ui;
};

#endif // EXPORTAR_H
