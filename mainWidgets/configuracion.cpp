#include "mainWidgets/configuracion.h"
#include "ui_configuracion.h"
#include "mainwindow.h"
#include "popupWidgets/exportar.h"
#include "global.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

configuracion::configuracion(QWidget *parent) : QWidget(parent), ui(new Ui::configuracion)
{
    ui->setupUi(this);
    ui->switchT2->setChecked(global::switchControl ==1);
    connect(ui->switchT2, &Switch::stateChanged, this, &configuracion::toggleControl);
}

configuracion::~configuracion()
{
    delete ui;
}

void configuracion::on_configBToMain_clicked()
{
    if (auto *mainWin = qobject_cast<MainWindow*>(parent())) {
        mainWin->switchToMainWindow();
    }
}

void configuracion::toggleControl(int state)
{
    if (state == Qt::Checked)
    {
        global::switchControl = 1;
        global::prevProfile = global::currentProfile;
        global::currentProfile = "Acceso total";
        global::currentAvatar = ":/assets/iconos/user0.png";
    }
    else
    {
        global::switchControl = 0;
        global::currentProfile = global::prevProfile;

    }
}

void configuracion::on_pushButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Eliminar registros");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("¿Está seguro de que desea reiniciar los registros?<br>El procedimiento es permanente y no tiene recuperación.");
    msgBox.setStyleSheet("QLabel{qproperty-alignment: AlignCenter; }");
    msgBox.setFont(QFont("Sitka", 14));
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setTextInteractionFlags(Qt::TextSelectableByMouse);
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();

    if (ret == QMessageBox::Ok) {
        QFile jsonFile("perfiles.json");
        jsonFile.remove();
        QString carpetaPerfiles = QCoreApplication::applicationDirPath() + "/perfiles";
        QDir dir(carpetaPerfiles);
        dir.removeRecursively();

        global::listaPerfiles.clear();
        global::currentProfile.clear();
        global::currentAvatar.clear();
    }
}

void configuracion::on_pushButton_2_clicked()
{
    Exportar *exportarDialog = new Exportar(this);
    exportarDialog->exec();
}
