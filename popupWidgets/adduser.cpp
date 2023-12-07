#include "adduser.h"
#include "ui_adduser.h"
#include "global.h"
#include "mainWidgets/profiles.h"
#include <QFile>
#include <QRegularExpressionValidator>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QPushButton>
#include <QDir>


AddUser::AddUser(QWidget *parent) :QDialog(parent),ui(new Ui::AddUser)
{
    ui->setupUi(this);
    this->setWindowTitle("Añadir perfil");
    this->setWindowFlags(this->windowFlags() &~Qt::WindowContextHelpButtonHint);
    connect(ui->aceptar, SIGNAL(pressed()), this, SLOT(aceptar()));
    QRegularExpression regex("^[A-Za-zÁÉÍÓÚáéíóúñÑ]+$");
    QValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->nombreText->setValidator(validator);
}

AddUser::~AddUser()
{
    delete ui;
}
void AddUser::on_pushButton_2_clicked()
{
    close();
}

void AddUser::aceptar()
{
    QString nuevoNombre = ui->nombreText->text().trimmed().toLower();;
    bool nombreExistente = false;
    for (const QVariant &item : global::listaPerfiles)
    {
        if (item.type() == QVariant::Map)
        {
            QVariantMap perfil = item.toMap();
            QString nombre = perfil["Nombre"].toString().trimmed().toLower();
            if (nombre == nuevoNombre)
            {
                nombreExistente = true;
                break;
            }
        }
    }

    if (ui->nombreText->text().isEmpty() || nombreExistente)
    {
        ui->nombreText->setStyleSheet("border-top: 5px solid red;");
    }

    else
    {
        QString newAvatar = QString(":/assets/iconos/user%1.png").arg(image);
        QString newProfile = ui->nombreText->text();
        QString carpetaPerfiles = QCoreApplication::applicationDirPath() + "/perfiles";
        QDir().mkpath(carpetaPerfiles);
        QString filePath = QString("%1/%2.json").arg(carpetaPerfiles, newProfile);

        QJsonObject jsonObject;
        jsonObject["imagen"] = newAvatar;
        jsonObject["m1_0"] = 0;
        jsonObject["m1_1"] = 0;
        jsonObject["m1_2"] = 0;
        jsonObject["m1_3"] = 0;
        jsonObject["m1points"] = 0;
        jsonObject["m2_0"] = 0;
        jsonObject["m2_1"] = 0;
        jsonObject["m2_2"] = 0;
        jsonObject["m2_3"] = 0;
        jsonObject["m2points"] = 0;
        jsonObject["m3_0"] = 0;
        jsonObject["m3_1"] = 0;
        jsonObject["m3_2"] = 0;
        jsonObject["m3_3"] = 0;
        jsonObject["m3points"] = 0;
        jsonObject["m4_0"] = 0;
        jsonObject["m4_1"] = 0;
        jsonObject["m4_2"] = 0;
        jsonObject["m4_3"] = 0;
        jsonObject["m4points"] = 0;

        QJsonDocument jsonDoc(jsonObject);
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream jsonStream(&file);
            jsonStream.setEncoding(QStringConverter::Utf8);
            jsonStream << jsonDoc.toJson();
            file.close();
        }

        QVariantMap perfil;
        perfil["Nombre"] =newProfile;
        perfil["Actual"] = true;
        QVariantList updatedList = global::listaPerfiles;

        for (int i = 0; i < updatedList.size(); ++i) {
            QVariantMap existingProfile = updatedList[i].toMap();
            if (existingProfile["Nombre"].toString() != global::currentProfile) {
                existingProfile["Actual"] = false;
            } else {
                existingProfile["Actual"] = true;
            }
            updatedList[i] = existingProfile;
        }

        updatedList.append(perfil);
        global::listaPerfiles = updatedList;

        profiles *p = new profiles;
        p->guardar();
        close();
    }
}

void AddUser::on_radioButton_clicked()
{
    image = 1;
}


void AddUser::on_radioButton_2_clicked()
{
    image = 2;
}


void AddUser::on_radioButton_3_clicked()
{
    image = 3;
}


void AddUser::on_radioButton_4_clicked()
{
    image = 4;
}

