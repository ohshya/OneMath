#include "profiles.h"
#include "ui_profiles.h"
#include "mainwindow.h"
#include "adduser.h"
#include "global.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDir>
#include <QFileDialog>

//iniciarlizador:
profiles::profiles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profiles)
{
    ui->setupUi(this);
    cargarLista();
    cargarInfo();

    for(int row=0; row < ui->tableWidget->rowCount(); ++row){
        if(ui->tableWidget->item(row, 0)->text() == global::currentProfile){
            ui->tableWidget->selectRow(row);
            break;
        }
    }

    connect(ui->tableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(cambiarPerfil()));
    connect(this, &profiles::perfilAgregado, this, &profiles::cargarLista);    
}

profiles::~profiles()
{
    guardar();
    delete ui;
}

//Modelo para el TableWidget
void profiles::modelo(){
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setAlternatingRowColors(false);
}



//cargar perfil:
void profiles::cargar()
{
    QFile jsonFile("perfiles.json");
    if (jsonFile.open(QIODevice::ReadOnly))
    {
        QByteArray jsonData = jsonFile.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        if (jsonDoc.isArray())
        {
            QJsonArray jsonArray = jsonDoc.array();
            for (const QJsonValue &value : jsonArray)
            {
                if (value.isObject())
                {
                    QVariantMap perfiles = value.toObject().toVariantMap();
                    global::listaPerfiles.append(QVariant(perfiles));
                }
            }
        }
        jsonFile.close();
    }
}

void profiles::cargarLista()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    modelo();
    for (int i = 0; i < global::listaPerfiles.size(); ++i){
        const QVariant &item = global::listaPerfiles[i];

        if (item.type() == QVariant::Map) {
            QVariantMap perfil = item.toMap();
            ui->tableWidget->insertRow(i);

            QString nombre = perfil["Nombre"].toString();
            QTableWidgetItem *nombreItem = new QTableWidgetItem(nombre);
            nombreItem->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(i, 0, nombreItem);

            bool current = perfil["Current"].toBool();
            if(current) global::currentProfile = nombre;
        }
    }
}

void profiles::cargarPerfil()
{
    for (int i = 0; i < global::listaPerfiles.size(); ++i) {
        const QVariant &item = global::listaPerfiles[i];
        if (item.type() == QVariant::Map) {
            QVariantMap perfil = item.toMap();

            QString nombre = perfil["Nombre"].toString();
            bool current = perfil["Actual"].toBool();
            if (current) {
                global::currentProfile = nombre;

                // Construir la ruta completa al archivo JSON del perfil
                QString carpetaPerfiles = QCoreApplication::applicationDirPath() + "/perfiles";
                QString filePath = QString("%1/%2.json").arg(carpetaPerfiles, global::currentProfile);

                QFile perfilFile(filePath);
                if (perfilFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QByteArray perfilData = perfilFile.readAll();
                    QJsonDocument perfilDoc = QJsonDocument::fromJson(perfilData);
                    if (perfilDoc.isObject()) {
                        QJsonObject perfilObject = perfilDoc.object();
                        global::currentAvatar = perfilObject["imagen"].toString();
                        global::m1[0] = perfilObject["m1_0"].toInt();
                        global::m1[1] = perfilObject["m1_1"].toInt();
                        global::m1[2] = perfilObject["m1_2"].toInt();
                        global::m1[3] = perfilObject["m1_3"].toInt();
                        global::m1points = perfilObject["m1points"].toInt();
                        global::m2[0] = perfilObject["m2_0"].toInt();
                        global::m2[1] = perfilObject["m2_1"].toInt();
                        global::m2[2] = perfilObject["m2_2"].toInt();
                        global::m2[3] = perfilObject["m2_3"].toInt();
                        global::m2points = perfilObject["m2points"].toInt();
                        global::m3[0] = perfilObject["m3_0"].toInt();
                        global::m3[1] = perfilObject["m3_1"].toInt();
                        global::m3[2] = perfilObject["m3_2"].toInt();
                        global::m3[3] = perfilObject["m3_3"].toInt();
                        global::m3points = perfilObject["m3points"].toInt();
                        global::m4[0] = perfilObject["m4_0"].toInt();
                        global::m4[1] = perfilObject["m4_1"].toInt();
                        global::m4[2] = perfilObject["m4_2"].toInt();
                        global::m4[3] = perfilObject["m4_3"].toInt();
                        global::m4points = perfilObject["m4points"].toInt();
                    }
                    perfilFile.close();
                }
                break;
            }
        }
    }
    global::calcularTotal();
    cargarInfo();
}

void profiles::cargarInfo()
{
    if(global::currentProfile.isEmpty() || global::currentProfile == "No hay perfil"){
        ui->stackedWidget->setCurrentIndex(1);
    }else{
        ui->stackedWidget->setCurrentIndex(0);
    }

    //Nombre y avatar
    ui->name->setText(global::currentProfile);
    ui->name->setAlignment(Qt::AlignCenter);
    ui->avatar->setPixmap(global::currentAvatar);
    ui->avatar->setScaledContents(true);
    global::calcularTotal();

    ui->prog1->setText(perText(global::m1total));
    ui->prog1->setAlignment(Qt::AlignCenter);
    ui->prog2->setText(perText(global::m2total));
    ui->prog2->setAlignment(Qt::AlignCenter);
    ui->prog3->setText(perText(global::m3total));
    ui->prog3->setAlignment(Qt::AlignCenter);
    ui->prog4->setText(perText(global::m4total));
    ui->prog4->setAlignment(Qt::AlignCenter);
}


QString profiles::perText(int const &x){
    switch (x) {
        case 0: return QString("⚪⚪⚪⚪"); break;
        case 1: return QString("🟢⚪⚪⚪"); break;
        case 2: return QString("🟢🟢⚪⚪"); break;
        case 3: return QString("🟢🟢🟢⚪"); break;
        case 4: return QString("🟢🟢🟢🟢"); break;
        default: return QString("Error");
    }
}

//Funcción para guardar el nombre del perfil
void profiles::guardar()
{
    QJsonDocument profilesDoc = QJsonDocument::fromVariant(global::listaPerfiles);
    QFile jsonFile("perfiles.json");
    if (jsonFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream jsonStream(&jsonFile);
        jsonStream.setEncoding(QStringConverter::Utf8);
        jsonStream << profilesDoc.toJson();
        jsonFile.close();
    }
}

//cambiar de perfil
void profiles::cambiarPerfil()
{
    int row = ui->tableWidget->currentRow();
    QString newProfileName = ui->tableWidget->item(row, 0)->text();
    if(newProfileName != global::currentProfile){

        // Guardar el perfil actual
        global::guardarPerfil();

        // Marcar el perfil actual como false en global::listaPerfiles
        for (int i = 0; i < global::listaPerfiles.size(); ++i) {
            QVariant &item = global::listaPerfiles[i];
            if (item.type() == QVariant::Map) {
                QVariantMap perfil = item.toMap();
                QString nombre = perfil["Nombre"].toString();
                if (nombre == global::currentProfile) {
                    perfil["Actual"] = false;
                    item = QVariant(perfil);
                }
            }
        }

        // Establecer el nuevo perfil seleccionado como actual
        for (int i = 0; i < global::listaPerfiles.size(); ++i) {
            QVariant &item = global::listaPerfiles[i];
            if (item.type() == QVariant::Map) {
                QVariantMap perfil = item.toMap();
                QString nombre = perfil["Nombre"].toString();
                if (nombre == newProfileName) {
                    perfil["Actual"] = true;
                    item = QVariant(perfil);
                }
            }
        }

        // Cargar el nuevo perfil seleccionado
        cargarPerfil();
        ui->profilesBToMain->setStyleSheet(
            "QPushButton#profilesBToMain{               \
            image: url(:/buttons/buttons/save.png);     \
            background: transparent;}                   \
            QPushButton#profilesBToMain:hover{          \
            image: url(:/buttons/buttons/saveH.png);}   \
            QPushButton#profilesBToMain:pressed{        \
            image: url(:/buttons/buttons/saveP.png);}"
        );
    }
    global::reiniciarVariables();
}

//botón de regresar al menú
void profiles::on_profilesBToMain_clicked()
{
    if(global::listaPerfiles.isEmpty())
    {
        global::currentAvatar.clear();
        global::currentProfile.clear();
    }
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    if (mainWin) {
        mainWin->switchToMainWindow();
    }
}

void profiles::on_pushButton_clicked()
{
    AddUser *addUserWindow = new AddUser(this);
    addUserWindow->setFixedSize(350, 200);
    addUserWindow->setModal(true);
    addUserWindow->exec();    
    emit perfilAgregado();
}

//eliminar perfil
void profiles::on_pushButton2_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow >= 0){
        QVariant &item = global::listaPerfiles[selectedRow];
        QVariantMap perfil = item.toMap();
        QString perfilAEliminar = perfil["Nombre"].toString();
        global::listaPerfiles.removeAt(selectedRow);

        QString carpetaPerfiles = QCoreApplication::applicationDirPath() + "/perfiles";
        QString filePath = QString("%1/%2.json").arg(carpetaPerfiles, perfilAEliminar);

        QFile::remove(filePath);

        global::currentProfile.clear();
        global::currentAvatar.clear();
        cargarLista();
    }
    cargarInfo();
}

void profiles::on_pushButton3_clicked()
{
    QString archivoJsonPath = QFileDialog::getOpenFileName(this, "Seleccionar archivo JSON", QString(), "Archivos JSON (*.json)");

    if (!archivoJsonPath.isEmpty()) {
        // Obtener el nombre del archivo sin la extensión .json
        QFileInfo fileInfo(archivoJsonPath);
        QString nombreArchivo = fileInfo.baseName();

        // Mover el archivo JSON seleccionado a la carpeta /perfiles en la raíz del programa
        QString destino = QCoreApplication::applicationDirPath() + "/perfiles";
        QString archivoDestinoPath = destino + "/" + nombreArchivo + ".json";
        QFile::copy(archivoJsonPath, archivoDestinoPath);

        // Agregar el perfil al archivo perfiles.json con "Actual" como false
        QVariantMap nuevoPerfil;
        nuevoPerfil["Actual"] = false;
        nuevoPerfil["Nombre"] = nombreArchivo;

        global::listaPerfiles.append(nuevoPerfil);
        guardar();
    }
    cargarLista();
    ui->name->setText(global::currentProfile);
    ui->avatar->setPixmap(global::currentAvatar);
}
