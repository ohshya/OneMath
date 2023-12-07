#include "conjuntos.h"
#include "ui_conjuntos.h"
#include "global.h"

conjuntos::conjuntos(QWidget *parent) : QWidget(parent), ui(new Ui::conjuntos)
{
    ui->setupUi(this);
}

conjuntos::~conjuntos()
{
    delete ui;
}

void conjuntos::reiniciar(conjuntos *instance)
{
    instance->ui->con1->setStyleSheet(QString("border-image: url(:/assets/conjuntos/1N.png);"));
    instance->ui->con2->setStyleSheet(QString("border-image: url(:/assets/conjuntos/2N.png);"));
    instance->ui->con3->setStyleSheet(QString("border-image: url(:/assets/conjuntos/3N.png);"));
    instance->ui->con4->setStyleSheet(QString("border-image: url(:/assets/conjuntos/4N.png);"));
    instance->ui->con5->setStyleSheet(QString("border-image: url(:/assets/conjuntos/5N.png);"));
    instance->ui->con6->setStyleSheet(QString("border-image: url(:/assets/conjuntos/6N.png);"));
    instance->ui->con7->setStyleSheet(QString("border-image: url(:/assets/conjuntos/7N.png);"));
    instance->ui->con8->setStyleSheet(QString("border-image: url(:/assets/conjuntos/8N.png);"));
}

void conjuntos::on_con1_clicked()
{
    if(global::conjunt1){
        ui->con1->setStyleSheet(QString("border-image: url(:/assets/conjuntos/1N.png);"));
        global::conjunt1 = false;
    }
    else{
        ui->con1->setStyleSheet(QString("border-image: url(:/assets/conjuntos/1Y.png);"));
        global::conjunt1 = true;
    }
}

void conjuntos::on_con2_clicked()
{
    if(global::conjunt2){
        ui->con2->setStyleSheet(QString("border-image: url(:/assets/conjuntos/2N.png);"));
        global::conjunt2 = false;
    }
    else{
        ui->con2->setStyleSheet(QString("border-image: url(:/assets/conjuntos/2Y.png);"));
        global::conjunt2 = true;
    }
}

void conjuntos::on_con3_clicked()
{
    if(global::conjunt3){
        ui->con3->setStyleSheet(QString("border-image: url(:/assets/conjuntos/3N.png);"));
        global::conjunt3 = false;
    }
    else{
        ui->con3->setStyleSheet(QString("border-image: url(:/assets/conjuntos/3Y.png);"));
        global::conjunt3 = true;
    }
}

void conjuntos::on_con4_clicked()
{
    if(global::conjunt4){
        ui->con4->setStyleSheet(QString("border-image: url(:/assets/conjuntos/4N.png);"));
        global::conjunt4 = false;
    }
    else{
        ui->con4->setStyleSheet(QString("border-image: url(:/assets/conjuntos/4Y.png);"));
        global::conjunt4 = true;
    }
}

void conjuntos::on_con5_clicked()
{
    if(global::conjunt5){
        ui->con5->setStyleSheet(QString("border-image: url(:/assets/conjuntos/5N.png);"));
        global::conjunt5 = false;
    }
    else{
        ui->con5->setStyleSheet(QString("border-image: url(:/assets/conjuntos/5Y.png);"));
        global::conjunt5 = true;
    }
}

void conjuntos::on_con6_clicked()
{
    if(global::conjunt6){
        ui->con6->setStyleSheet(QString("border-image: url(:/assets/conjuntos/6N.png);"));
        global::conjunt6 = false;
    }
    else{
        ui->con6->setStyleSheet(QString("border-image: url(:/assets/conjuntos/6Y.png);"));
        global::conjunt6 = true;
    }
}

void conjuntos::on_con7_clicked()
{
    if(global::conjunt7){
        ui->con7->setStyleSheet(QString("border-image: url(:/assets/conjuntos/7N.png);"));
        global::conjunt7 = false;
    }
    else{
        ui->con7->setStyleSheet(QString("border-image: url(:/assets/conjuntos/7Y.png);"));
        global::conjunt7 = true;
    }
}

void conjuntos::on_con8_clicked()
{
    if(global::conjunt8){
        ui->con8->setStyleSheet(QString("border-image: url(:/assets/conjuntos/8N.png);"));
        global::conjunt8 = false;
    }
    else{
        ui->con8->setStyleSheet(QString("border-image: url(:/assets/conjuntos/8Y.png);"));
        global::conjunt8 = true;
    }
}
