#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "global.h"
#include "clickableframe.h"

#include "credits.h"
#include "mybutton.h"
#include "moduleselection.h"
#include "profiles.h"
#include "configuracion.h"
#include "module1.h"
#include "module1test.h"
#include "module2.h"
#include "module2test.h"
#include "module3.h"
#include "module3test.h"
#include "module4.h"
#include <QLabel>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), currentUI(nullptr), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    profilesInstance = new profiles();
    profilesInstance->cargar();
    profilesInstance->cargarPerfil();
    setBG();
    botones();
    profileB();
}

void MainWindow::setBG()
{
    QPixmap backgroundImage(":/assets/background2.jpg");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    this->setPalette(palette);
}

void MainWindow::profileB()
{
    if (global::currentProfile.isEmpty() || global::currentProfile == "No hay perfil")
    {
        global::currentProfile="No hay perfil";
        global::currentAvatar=":/users/users/noUser.png";
        this->findChild<QPushButton*>("mainModulos")->setDisabled(true);
        this->findChild<QPushButton*>("mainModulos")->setToolTip("Primero debes crear un perfil");
    }
    else{this->findChild<QPushButton*>("mainModulos")->setEnabled(true);
    this->findChild<QPushButton*>("mainModulos")->setToolTip("");}


    MyButton* btn = this->findChild<MyButton*>("mainPerfiles");
    if(btn)
    {
    QFile perfilFile(QCoreApplication::applicationDirPath()+"/perfiles/"+global::currentProfile+".json");
    if(perfilFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&perfilFile);
        QString perfilJson = in.readAll();
        perfilFile.close();
        QJsonDocument perfilDoc = QJsonDocument::fromJson(perfilJson.toUtf8());
        QJsonObject perfilObject = perfilDoc.object();
        if (perfilObject.contains("imagen") && perfilObject["imagen"].isString()){
            QString imagenPath = perfilObject["imagen"].toString();
            global::currentAvatar = imagenPath;
        }
    }
        btn->setGeometry(0, 0, 0, 0);
        btn->setStyleSheet(QString("QPushButton{\
        background-image: url(%1);          \
        background-repeat: no-repeat;       \
        background-origin: content;         \
        background-position: left center;   \
        background-color: transparent;      \
        border: 1px solid transparent;}"
        ).arg(global::currentAvatar));

        auto* labl = new QLabel(global::currentProfile, btn);
        labl->setGeometry(btn->width(), 0, labl->width()+100, btn->height());
        labl->setStyleSheet("color: #333333;");
        QFont labelFont("Sitka", 14);
        labl->setFont(labelFont);
        if (global::currentProfile=="No hay perfíl"){
            global::currentProfile.clear();
            global::currentAvatar.clear();
        }
    }
}

void MainWindow::botones(){
    QMainWindow *mainWindowWidget = this;
    mainWindowWidget->findChild<QPushButton*>("mainPerfiles")->setDisabled(global::switchControl);
    connect(mainWindowWidget->findChild<ClickableFrame*>("logo"), &ClickableFrame::clicked, this, &MainWindow::logo_clicked);
    connect(mainWindowWidget->findChild<QPushButton*>("mainSalir"), &QPushButton::clicked, this, &MainWindow::close);
    connect(mainWindowWidget->findChild<QPushButton*>("mainModulos"), &QPushButton::clicked, this, &MainWindow::switchToModulos);
    connect(mainWindowWidget->findChild<MyButton*>("mainPerfiles"), &QPushButton::clicked, this, &MainWindow::switchToPerfiles);
    connect(mainWindowWidget->findChild<QPushButton*>("mainOpciones"), &QPushButton::clicked, this, &MainWindow::switchToConfig);
    connect(mainWindowWidget->findChild<QPushButton*>("mainAbout"), &QPushButton::clicked, this, &MainWindow::creditos);
}

void MainWindow::loadUI(QWidget *uiWidget)
{
    unloadCurrentUI();
    currentUI = uiWidget;
    setCentralWidget(currentUI);
}
void MainWindow::unloadCurrentUI()
{
    if (currentUI){
        delete currentUI;
        currentUI = nullptr;
    }
}

void MainWindow::switchToModulos()
{
    QWidget *ventanaModulos = new moduleSelection(this);
    loadUI(ventanaModulos);
    setBG();
}

void MainWindow::switchToConfig()
{
    QWidget *ventanaConfiguracion = new configuracion(this);
    loadUI(ventanaConfiguracion);
}

void MainWindow::switchToPerfiles()
{
    QWidget *ventanaPerfiles = new profiles(this);
    loadUI(ventanaPerfiles);
}

void MainWindow::switchToModule1()
{
    QWidget *ventanaM1 = new module1(this);
    loadUI(ventanaM1);
}

void MainWindow::switchToModule1Test()
{
    QWidget *ventanaM1 = new module1test(this);
    loadUI(ventanaM1);
}

void MainWindow::switchToModule2()
{
    QWidget *ventanaM2 = new module2(this);
    loadUI(ventanaM2);
}

void MainWindow::switchToModule2Test()
{
    QWidget *ventanaM2 = new module2test(this);
    loadUI(ventanaM2);
}

void MainWindow::switchToModule3()
{
    QWidget *ventanaM3 = new module3(this);
    loadUI(ventanaM3);
}

void MainWindow::switchToModule3Test()
{
    QWidget *ventanaM3 = new module3test(this);
    loadUI(ventanaM3);
}
void MainWindow::switchToModule4()
{
    QWidget *ventanaM4 = new module4(this);
    loadUI(ventanaM4);
}

void MainWindow::creditos()
{
    Credits *c = new Credits(this);
    c->setModal(true);
    c->exec();
}

void MainWindow::logo_clicked()
{
    QMainWindow *mainWindowWidget = this;
    global::logo++;

    if (global::logo == 1)
    {
        mainWindowWidget->findChild<QFrame*>("logo")->setStyleSheet("ClickableFrame#logo{ \
            image: url(:/assets/logo2.png);}");
    }else if (global::logo == 2)
    {
        mainWindowWidget->findChild<QFrame*>("logo")->setStyleSheet("ClickableFrame#logo{ \
            image: url(:/assets/logo3.png);}");
    } else
    {
        mainWindowWidget->findChild<QFrame*>("logo")->setStyleSheet("ClickableFrame#logo{ \
            image: url(:/assets/logo.png);}");
        global::logo = 0;
    }
}

void MainWindow::switchToMainWindow()
{
    Ui::MainWindow mainWinUI;
    QMainWindow *mainWindowWidget = new QMainWindow;
    mainWinUI.setupUi(mainWindowWidget);
    loadUI(mainWindowWidget);
    setBG();
    botones();
    profileB();
}
MainWindow::~MainWindow()
{
    profilesInstance = new profiles();
    profilesInstance->guardar();
    global::guardarPerfil();
    delete profilesInstance;
    delete ui;
}
