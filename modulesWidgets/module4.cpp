#include "module4.h"
#include "ui_module4.h"
#include "mainwindow.h"
#include "global.h"
#include <QMessageBox>

module4::module4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::module4)
{
    ui->setupUi(this);
    setBG();
    ui->stackedWidget->setCurrentIndex(global::m4part);
    actualizar();
}

module4::~module4()
{
    delete ui;
}

void module4::actualizar()
{
    switch(ui->stackedWidget->currentIndex())
    {
        case 0:aniText(ui->partText, "Definición de pendiente"); global::m4part = 0; break;
        case 1:aniText(ui->partText, "Ejemplo gráfico de pendiente secante"); global::m4[0] = 1; global::m4part = 1; break;
        case 2:aniText(ui->partText, "Definición formal de Derivada"); global::m4[1] = 1; global::m4part = 2; break;
        case 3:aniText(ui->partText, "Demostración gráfica de la derivada"); global::m4[2] = 1; global::m4part = 3; break;
        case 4:aniText(ui->partText, "Derivadas más comunes"); global::m4[3] = 1; global::m4part = 0; break;
        default: break;
    }
    if(ui->stackedWidget->currentIndex()==4){
        ui->siguiente->setDisabled(true);
    }else{ui->siguiente->setDisabled(false);}
    if(ui->stackedWidget->currentIndex()==0){
        ui->anterior->setDisabled(true);
    }else{ui->anterior->setDisabled(false);}
    progressB();
    global::calcularTotal();
    if(global::m4total<4){ui->nextPart->setDisabled(true);}
    else{ui->nextPart->setDisabled(false);}
}

void module4::setBG()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    QPixmap backgroundImage(":/assets/otros/background.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    mainWin->setPalette(palette);
}

void module4::on_backModuleS_clicked()
{
    if(!timer->isActive()){
        MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
        if (mainWin) {
            mainWin->switchToModulos();
        }
    }
}

void module4::aniText(QLabel *label, QString text) //Texto Animado del titulo
{
    timer = new QTimer(this);
    QString currentText = "";
    int currentIndex = 0;
    timer->start(50);
    connect(timer, &QTimer::timeout, this, [=]() mutable{
        if (currentIndex < text.length()) {
            currentText += text[currentIndex];
            label->setText(currentText);
            label->setAlignment(Qt::AlignCenter);
            ++currentIndex;
        } else {
            timer->stop();
        }
    });
}

void module4::on_anterior_clicked()
{
    if(ui->stackedWidget->currentIndex() != 0 && !timer->isActive()){
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()-1);
        actualizar();
    }

}

void module4::on_siguiente_clicked()
{
    if(ui->stackedWidget->currentIndex() != 4 && !timer->isActive()){
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()+1);
        actualizar();
    }
}

void module4::progressB()
{   
    global::calcularTotal();
    QString style;
    switch(global::m4total){
    case 0: style = "#nextPart{image: url(:/assets/iconos/0ok.png);}"; break;
    case 1: style = "#nextPart{image: url(:/assets/iconos/2ok.png);}"; break;
    case 2: style = "#nextPart{image: url(:/assets/iconos/4ok.png);}"; break;
    case 3: style = "#nextPart{image: url(:/assets/iconos/6ok.png);}"; break;
    case 4: style = "#nextPart{image: url(:/assets/iconos/7ok.png);}"; break;
    default: break;
    }


    if(global::m4total < 4)
    {
        ui->nextPart->setDisabled(true);
        ui->nextPart->setStyleSheet(style);
    }else {
        ui->nextPart->setStyleSheet(okstyle);
        ui->nextPart->setDisabled(false);
    }
}

void module4::on_nextPart_clicked()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    mainWin->switchToModulos();
}

