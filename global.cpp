#include "global.h"
#include <QCoreApplication>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

int global::switchControl = 0;
int global::indice;
int global::logo = 0;

int global::m1[4];
int global::m2[4];
int global::m3[4];
int global::m4[4];
int global::m1total;
int global::m2total;
int global::m3total;
int global::m4total;
int global::m1part = 0;
int global::m2part = 0;
int global::m3part = 0;
int global::m4part = 0;
int global::m1points = 0;
int global::m2points = 0;
int global::m3points = 0;
int global::m4points = 0;

QString global::prevProfile;
QString global::currentProfile;
QString global::currentAvatar;
QVariantList global::listaPerfiles;

bool global::conjunt1 = false;
bool global::conjunt2 = false;
bool global::conjunt3 = false;
bool global::conjunt4 = false;
bool global::conjunt5 = false;
bool global::conjunt6 = false;
bool global::conjunt7 = false;
bool global::conjunt8 = false;

void global::calcularTotal()
{
    global::m1total = global::m1[0] +  global::m1[1] +  global::m1[2] +  global::m1[3];
    global::m2total = global::m2[0] +  global::m2[1] +  global::m2[2] +  global::m2[3];
    global::m3total = global::m3[0] +  global::m3[1] +  global::m3[2] +  global::m3[3];
    global::m4total = global::m4[0] +  global::m4[1] +  global::m4[2] +  global::m4[3];
}

void global::reiniciarConjuntos(){
    global::conjunt1 = false;
    global::conjunt2 = false;
    global::conjunt3 = false;
    global::conjunt4 = false;
    global::conjunt5 = false;
    global::conjunt6 = false;
    global::conjunt7 = false;
    global::conjunt8 = false;

}

void global::guardarPerfil()
{
    if (!currentProfile.isEmpty() && currentProfile != "No hay perfil")
    {
        QString carpetaPerfiles = QCoreApplication::applicationDirPath() + "/perfiles";
        QString filePath = QString("%1/%2.json").arg(carpetaPerfiles, currentProfile);
        QJsonObject jsonObject;
        jsonObject["imagen"] = global::currentAvatar;
        jsonObject["m1_0"] = m1[0];
        jsonObject["m1_1"] = m1[1];
        jsonObject["m1_2"] = m1[2];
        jsonObject["m1_3"] = m1[3];
        jsonObject["m1points"] = m1points;
        jsonObject["m2_0"] = m2[0];
        jsonObject["m2_1"] = m2[1];
        jsonObject["m2_2"] = m2[2];
        jsonObject["m2_3"] = m2[3];
        jsonObject["m2points"] = m2points;
        jsonObject["m3_0"] = m3[0];
        jsonObject["m3_1"] = m3[1];
        jsonObject["m3_2"] = m3[2];
        jsonObject["m3_3"] = m3[3];
        jsonObject["m3points"] = m3points;
        jsonObject["m4_0"] = m4[0];
        jsonObject["m4_1"] = m4[1];
        jsonObject["m4_2"] = m4[2];
        jsonObject["m4_3"] = m4[3];
        jsonObject["m4points"] = m4points;

        QJsonDocument jsonDoc(jsonObject);
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream jsonStream(&file);
            jsonStream.setEncoding(QStringConverter::Utf8);
            jsonStream << jsonDoc.toJson();
            file.close();
        }
    }
}

void global::reiniciarVariables()
{
    global::m1part = 0;
    global::m2part = 0;
    global::m3part = 0;
    global::m4part = 0;
}
