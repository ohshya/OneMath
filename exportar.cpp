#include "exportar.h"
#include "ui_exportar.h"
#include "global.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <global.h>
#include <profiles.h>

Exportar::Exportar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exportar)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Exportar Perfiles");
    QStringList nombres;
    for (const QVariant &item : global::listaPerfiles) {
        if (item.type() == QVariant::Map) {
            QVariantMap perfil = item.toMap();
            if (perfil.contains("Nombre")) {
                QString nombre = perfil["Nombre"].toString();
                nombres << nombre;
            }
        }
    }
    ui->comboBox->addItems(nombres);
}

Exportar::~Exportar()
{
    delete ui;
}

void Exportar::on_allExport_clicked()
{
    QString destino = QFileDialog::getExistingDirectory(this, "Seleccionar destino para la exportación");
    QFile archivoJSON("perfiles.json");
    archivoJSON.copy(destino + "/perfiles.json");

    if (!destino.isEmpty()) {
        QDir carpetaPerfiles(QCoreApplication::applicationDirPath() + "/perfiles");
        if (carpetaPerfiles.exists()) {
            QString destinoPerfiles = destino + "/perfiles";
            QDir().mkpath(destinoPerfiles);

            QStringList archivos = carpetaPerfiles.entryList(QDir::Files);
            for (const QString &archivo : archivos) {
                QFile::copy(carpetaPerfiles.filePath(archivo), destinoPerfiles + "/" + archivo);
            }
        }
    }
    close();
}

void Exportar::on_profileExport_clicked()
{
    QString perfilSeleccionado = ui->comboBox->currentText();
    if (!perfilSeleccionado.isEmpty()) {
        QString destino = QFileDialog::getExistingDirectory(this, "Seleccionar destino para la exportación");

            if (!destino.isEmpty()) {
            QString perfilJsonPath = QCoreApplication::applicationDirPath() + "/perfiles/" + perfilSeleccionado + ".json";
            QFile::copy(perfilJsonPath, destino + "/" + perfilSeleccionado + ".json");
        }
    }
    close();
}
