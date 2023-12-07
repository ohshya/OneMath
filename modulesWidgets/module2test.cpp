#include "modulesWidgets/module2test.h"
#include "ui_module2test.h"
#include "mainwindow.h"
#include "global.h"
#include "extendedWidgets/conjuntos.h"
#include <QRandomGenerator>

module2test::module2test(QWidget *parent) : QWidget(parent), ui(new Ui::module2test)
{
    ui->setupUi(this);
    progressB();
    global::reiniciarConjuntos();
    ui->aviso->setVisible(false);
    ui->op1->setVisible(false);
    ui->op2->setVisible(false);
    ui->op3->setVisible(false);
    ui->op4->setVisible(false);
    ui->op5->setVisible(false);
    ui->conjuntoA->setVisible(false);
    ui->conjuntoB->setVisible(false);
    ui->conjuntoC->setVisible(false);
    ui->explainConjunt->setVisible(false);
    ui->explainConjunt2->setVisible(false);
    update();
}

module2test::~module2test()
{
    delete ui;
}

void module2test::on_backModuleS_clicked()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    if(!timer->isActive() && mainWin){
            mainWin->switchToModule2();
    }
}
void module2test::on_nextPart_clicked()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    if(!timer->isActive() && mainWin){
        mainWin->switchToModulos();
    }
}
void module2test::progressB()
{
    QString style = QString("#nextPart{image: url(:/assets/iconos/%1ok.png);}").arg(global::m2points);
    if(global::m2points < 8)
    {
        ui->nextPart->setDisabled(true);
        ui->nextPart->setStyleSheet(style);
    }else {
        ui->nextPart->setStyleSheet(okstyle);
        ui->nextPart->setDisabled(false);
        ui->aviso->setVisible(true);
    }
}

void module2test::on_conjuntoA_clicked()
{
    ui->explainConjunt->setStyleSheet(QString("border-image: url(:/assets/conjuntos/CA.png);"));
}

void module2test::on_conjuntoB_clicked()
{
    ui->explainConjunt->setStyleSheet(QString("border-image: url(:/assets/conjuntos/CB.png);"));
}

void module2test::on_conjuntoC_clicked()
{
    ui->explainConjunt->setStyleSheet(QString("border-image: url(:/assets/conjuntos/CC.png);"));
}

void module2test::on_op1_clicked()
{
    ui->explainConjunt2->setStyleSheet("border-image: url(:/assets/conjuntos/O1.png);");
}

void module2test::on_op2_clicked()
{
    ui->explainConjunt2->setStyleSheet("border-image: url(:/assets/conjuntos/O2.png);");
}

void module2test::on_op3_clicked()
{
    ui->explainConjunt2->setStyleSheet("border-image: url(:/assets/conjuntos/O3.png);");
}

void module2test::on_op4_clicked()
{
    ui->explainConjunt2->setStyleSheet("border-image: url(:/assets/conjuntos/O4.png);");
}

void module2test::on_op5_clicked()
{
    ui->explainConjunt2->setStyleSheet("border-image: url(:/assets/conjuntos/O5.png);");
}

void module2test::on_mostrar1_clicked()
{
    if(ui->mostrar1->text() == "▼"){
        ui->mostrar1->setText("▲");
        ui->op1->setVisible(true);
        ui->op2->setVisible(true);
        ui->op3->setVisible(true);
        ui->op4->setVisible(true);
        ui->op5->setVisible(true);
        ui->explainConjunt2->setVisible(true);
    }
    else{
        ui->mostrar1->setText("▼");
        ui->op1->setVisible(false);
        ui->op2->setVisible(false);
        ui->op3->setVisible(false);
        ui->op4->setVisible(false);
        ui->op5->setVisible(false);
        ui->explainConjunt2->setVisible(false);
    }
}


void module2test::on_mostrar2_clicked()
{
    if(ui->mostrar2->text() == "▼"){
        ui->mostrar2->setText("▲");
        ui->conjuntoA->setVisible(true);
        ui->conjuntoB->setVisible(true);
        ui->conjuntoC->setVisible(true);
        ui->explainConjunt->setVisible(true);
    }
    else{
        ui->mostrar2->setText("▼");
        ui->conjuntoA->setVisible(false);
        ui->conjuntoB->setVisible(false);
        ui->conjuntoC->setVisible(false);
        ui->explainConjunt->setVisible(false);
    }
}

void module2test::update(){
    int min = 1;
    int max = 20;
    int randN;
    numeroAleatorio = 0;
    if(listaRandoms.size()<20){
        do {
            randN = QRandomGenerator::global()->bounded(min, max + 1);
        } while (listaRandoms.contains(randN));
    }else{randN = 0;}
    listaRandoms.insert(randN);
    numeroAleatorio = randN;

    progressB();
    if(global::m2points == 4){
        global::m2[2] = 1;
    }
    if(global::m2points == 8){
        global::m2[3] = 1;
    }
    ui->operacion->setStyleSheet("border: 2px solid black; border-radius: 10px; background-color: white;");
    ui->comprobar->setText("Comprobar");
    conjuntos* myInstance = ui->widget;
    ui->widget->reiniciar(myInstance);
    global::reiniciarConjuntos();

    switch (numeroAleatorio) {
    case 1: aniText(ui->operacion, "A Δ B Δ C"); break;
    case 2: aniText(ui->operacion, "(A U B U C)' U (A ∩ B ∩ C)"); break;
    case 3: aniText(ui->operacion, "C - (A ∩ B)"); break;
    case 4: aniText(ui->operacion, "B - (A ∩ C)"); break;
    case 5: aniText(ui->operacion, "(A U B) ∩ (A U C)"); break;
    case 6: aniText(ui->operacion, "(A U B)' ∩ C"); break;
    case 7: aniText(ui->operacion, "[(A U B) - C] U (A ∩ B)"); break;
    case 8: aniText(ui->operacion, "(A Δ B)'"); break;
    case 9: aniText(ui->operacion, "(A U B) - (A ∩ B)"); break;
    case 10: aniText(ui->operacion, "C - (A - B)"); break;
    case 11: aniText(ui->operacion, "[(A Δ C) - B] U (A ∩ B ∩ C)"); break;
    case 12: aniText(ui->operacion, "A' ∩ B'"); break;
    case 13: aniText(ui->operacion, "(A ∩ B ∩ C)'"); break;
    case 14: aniText(ui->operacion, "[(A ∩ B) - C] U (A Δ B) ∩ C"); break;
    case 15: aniText(ui->operacion, "(A U B) ∩ C"); break;
    case 16: aniText(ui->operacion, "(A ∩ B) - C"); break;
    case 17: aniText(ui->operacion, "A' U B"); break;
    case 18: aniText(ui->operacion, "(C - A) ∩ (C - B) U (A ∩ B)"); break;
    case 19: aniText(ui->operacion, "C - (B Δ C)"); break;
    case 20: aniText(ui->operacion, "C Δ B"); break;
    default: aniText(ui->operacion, "No quedan más Ejercicios"); break;
    }
}

void module2test::correcto(){
    global::m2points++;
    ui->operacion->setStyleSheet("border: 4px solid green; border-radius: 10px; background-color: white;");
    ui->comprobar->setText("Siguiente");
}
void module2test::incorrecto(){
    ui->operacion->setStyleSheet("border: 4px solid red; border-radius: 10px; background-color: white;");
}

void module2test::on_comprobar_clicked()
{
    if(ui->comprobar->text() == "Comprobar" && !timer->isActive())
    {
        switch (numeroAleatorio) {
        case 1:global::conjunt1 && !global::conjunt2 && global::conjunt3 && !global::conjunt4 && global::conjunt5 && !global::conjunt6 &&global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 2:!global::conjunt1 && !global::conjunt2 && !global::conjunt3 && !global::conjunt4 && global::conjunt5 && !global::conjunt6 && !global::conjunt7 && global::conjunt8 ? correcto() : incorrecto();
            break;

        case 3:!global::conjunt1 && !global::conjunt2 && !global::conjunt3 && global::conjunt4 && !global::conjunt5 && global::conjunt6 && global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 4:!global::conjunt1 && global::conjunt2 && global::conjunt3 && !global::conjunt4 && !global::conjunt5 &&  global::conjunt6 && !global::conjunt7 &&!global::conjunt8 ? correcto() : incorrecto();
            break;

        case 5:global::conjunt1 && global::conjunt2 && !global::conjunt3 && global::conjunt4 && global::conjunt5 && global::conjunt6 && !global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 6:!global::conjunt1 && !global::conjunt2 && !global::conjunt3 && !global::conjunt4 && !global::conjunt5 && !global::conjunt6 && global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 7:global::conjunt1 && global::conjunt2 && global::conjunt3 && !global::conjunt4 && global::conjunt5 && !global::conjunt6 && !global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 8:!global::conjunt1 && global::conjunt2 && !global::conjunt3 && !global::conjunt4 && global::conjunt5 && !global::conjunt6 && global::conjunt7 && global::conjunt8 ? correcto() : incorrecto();
            break;

        case 9:global::conjunt1 && !global::conjunt2 && global::conjunt3 && global::conjunt4 && !global::conjunt5 && global::conjunt6 && !global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 10:!global::conjunt1 && !global::conjunt2 && !global::conjunt3 && !global::conjunt4 && global::conjunt5 && global::conjunt6 && global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 11:global::conjunt1 && global::conjunt2 && !global::conjunt3 && !global::conjunt4 && global::conjunt5 && !global::conjunt6 && global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 12:!global::conjunt1 && !global::conjunt2 && !global::conjunt3 && !global::conjunt4 && !global::conjunt5 && !global::conjunt6 && global::conjunt7 && global::conjunt8 ? correcto() : incorrecto();
            break;

        case 13:global::conjunt1 && global::conjunt2 && global::conjunt3 && global::conjunt4 && !global::conjunt5 && global::conjunt6 && global::conjunt7 && global::conjunt8 ? correcto() : incorrecto();
            break;

        case 14:!global::conjunt1 && global::conjunt2 && !global::conjunt3 && global::conjunt4 && !global::conjunt5 && global::conjunt6 && !global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 15:!global::conjunt1 && !global::conjunt2 && !global::conjunt3 && global::conjunt4 && global::conjunt5 && global::conjunt6 && !global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 16:!global::conjunt1 && global::conjunt2 && !global::conjunt3 && !global::conjunt4 && !global::conjunt5 && !global::conjunt6 && !global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 17:!global::conjunt1 && global::conjunt2 && global::conjunt3 && !global::conjunt4 && global::conjunt5 && global::conjunt6 && global::conjunt7 && global::conjunt8 ? correcto() : incorrecto();
            break;

        case 18:!global::conjunt1 && global::conjunt2 && !global::conjunt3 && !global::conjunt4 && global::conjunt5 && !global::conjunt6 && global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 19:!global::conjunt1 && !global::conjunt2 && !global::conjunt3 && !global::conjunt4 && global::conjunt5 && global::conjunt6 && !global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        case 20:!global::conjunt1 && global::conjunt2 && global::conjunt3 && global::conjunt4 && !global::conjunt5 && !global::conjunt6 && global::conjunt7 && !global::conjunt8 ? correcto() : incorrecto();
            break;

        default: break;
        }
    }
    else{
        if(!timer->isActive())update();
    }
}

void module2test::aniText(QLabel *label, QString text) //Texto Animado del titulo
{
    timer = new QTimer(this);
    QString currentText = "";
    int currentIndex = 0;
    timer->start(75);
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
