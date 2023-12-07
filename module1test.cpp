#include "module1test.h"
#include "ui_module1test.h"
#include "global.h"
#include "mainwindow.h"
#include <QLabel>
#include <QRandomGenerator>
#include <QTime>
#include <QSet>

module1test::module1test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::module1test)
{
    ui->setupUi(this);
    ui->title->setText("Test");
    ui->aviso->setVisible(false);
    progressB();
    update();
}

module1test::~module1test()
{
    delete ui;
}

void module1test::on_backModuleS_clicked()
{
    if(!timer->isActive()){
        MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
        if (mainWin) {
            mainWin->switchToModule1();
        }
    }
}

void module1test::aniText(QLabel *label, QString text)
{
    timer = new QTimer(this);
    QString currentText = "";
    int currentIndex = 0;
    timer->start(40);
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

void module1test::progressB()
{
    QString style = QString("#nextPart{image: url(:/buttons/buttons/%1ok.png);}").arg(global::m1points);
    if(global::m1points < 8)
    {
        ui->nextPart->setDisabled(true);
        ui->nextPart->setStyleSheet(style);
    }else {
        ui->nextPart->setStyleSheet(okstyle);
        ui->nextPart->setDisabled(false);
        ui->aviso->setVisible(true);
    }
}

void module1test::on_nextPart_clicked()
{
    if(!timer->isActive()){
        MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
        if (mainWin) {
            mainWin->switchToModulos();
        }
    }
}

void module1test::update(){
    int min = 1;
    int max = 20;
    int randN;

    if(listaRandoms.size()<20){
        do {
            randN = QRandomGenerator::global()->bounded(min, max + 1);
        } while (listaRandoms.contains(randN));
    }else{randN = 0;}

    listaRandoms.insert(randN);
    numeroAleatorio = randN;
    ui->R1->setStyleSheet(r1style);
    ui->R2->setStyleSheet(r2style);
    ui->R3->setStyleSheet(r3style);
    ui->R4->setStyleSheet(r4style);
    ui->preguntaText->setStyleSheet(preguntaEstilo);
    currentOption = 0;
    progressB();
    if(global::m1points == 4){
        global::m1[2] = 1;
    }
    if(global::m1points == 8){
        global::m1[3] = 1;
    }

    switch (numeroAleatorio) {
    case 1: pregunta1(); break;
    case 2: pregunta2(); break;
    case 3: pregunta3(); break;
    case 4: pregunta4(); break;
    case 5: pregunta5(); break;
    case 6: pregunta6(); break;
    case 7: pregunta7(); break;
    case 8: pregunta8(); break;
    case 9: pregunta9(); break;
    case 10: pregunta10(); break;
    case 11: pregunta11(); break;
    case 12: pregunta12(); break;
    case 13: pregunta13(); break;
    case 14: pregunta14(); break;
    case 15: pregunta15(); break;
    case 16: pregunta16(); break;
    case 17: pregunta17(); break;
    case 18: pregunta18(); break;
    case 19: pregunta19(); break;
    case 20: pregunta20(); break;
    default: sinPreguntas();
    }
}


void module1test::pregunta1()
{
    aniText(ui->preguntaText, "¿Cuál es la base numérica utilizada como lenguaje maquina?");
    ui->R1->setText("Octal");
    ui->R2->setText("Hexadecimal");
    ui->R3->setText("Decimal");
    ui->R4->setText("Binaria ");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta2()
{
    aniText(ui->preguntaText, "¿Cuál de las siguientes bases numéricas utiliza los dígitos 0-7?");
    ui->R1->setText("Decimal");
    ui->R2->setText("Binaria");
    ui->R3->setText("Octal ");
    ui->R4->setText("Hexadecimal");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta3()
{
    aniText(ui->preguntaText, "¿Cuál es el valor decimal del número binario 1101?");
    ui->R1->setText("13");
    ui->R2->setText("14");
    ui->R3->setText("12");
    ui->R4->setText("15");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta4()
{
    aniText(ui->preguntaText, "¿Cuál de las siguientes bases numéricas utiliza los dígitos 0-9 y las letras A-F?");
    ui->R1->setText("Decimal");
    ui->R2->setText("Octal");
    ui->R3->setText("Binaria");
    ui->R4->setText("Hexadecimal ");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta5()
{
    aniText(ui->preguntaText, "En el sistema hexadecimal, ¿qué representa el dígito 'A'?");
    ui->R1->setText("11");
    ui->R2->setText("12");
    ui->R3->setText("10");
    ui->R4->setText("13");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta6()
{
    aniText(ui->preguntaText, "¿Cuál de las siguientes afirmaciones es cierta acerca de la base octal?");
    ui->R1->setText("Utiliza solo los\n dígitos 0-7");
    ui->R2->setText("Equivalente a \nbase binaria");
    ui->R3->setText("Es la base más \ncomún en matemáticas");
    ui->R4->setText("Utiliza los dígitos 0-9");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta7()
{
    aniText(ui->preguntaText, "¿Cuál es el valor decimal del número binario 101010?");
    ui->R1->setText("42");
    ui->R2->setText("52");
    ui->R3->setText("32");
    ui->R4->setText("62");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta8()
{
    aniText(ui->preguntaText, " ¿Cuál de las siguientes bases numéricas se utiliza comúnmente para representar colores en HTML y CSS?");
    ui->R1->setText("Decimal");
    ui->R2->setText("Binaria");
    ui->R3->setText("Hexadecimal");
    ui->R4->setText("Octal");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta9()
{
    aniText(ui->preguntaText, "El '10' en octal a cuanto equivale en Decimal");
    ui->R1->setText("10");
    ui->R2->setText("11");
    ui->R3->setText("8");
    ui->R4->setText("9");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta10()
{
    aniText(ui->preguntaText, "¿Cuál de las siguientes afirmaciones es cierta acerca de la base binaria?");
    ui->R1->setText("Es la base más\n utilizada en matemáticas");
    ui->R2->setText("Se utiliza en la\n codificación de caracteres\n en ASCII");
    ui->R3->setText("No se utiliza\n en computación");
    ui->R4->setText("Utiliza solo los\n dígitos 0 y 1");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta11()
{
    aniText(ui->preguntaText, "El numero binario '111' ¿Cuanto equivale en Decimal?");
    ui->R1->setText("6");
    ui->R2->setText("7");
    ui->R3->setText("10");
    ui->R4->setText("8");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta12()
{
    aniText(ui->preguntaText, "¿Cuál de las siguientes afirmaciones es cierta acerca de la base decimal?");
    ui->R1->setText("Utiliza los dígitos\n 0-7");
    ui->R2->setText("Es la base más\n común en sistemas \ninformáticos");
    ui->R3->setText("Utiliza los \ndígitos 0-9");
    ui->R4->setText("es poco comúnmente \nusada en matemáticas");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta13()
{
    aniText(ui->preguntaText, " En el sistema octal, ¿qué representa el dígito '5'?");
    ui->R1->setText("4");
    ui->R2->setText("5");
    ui->R3->setText("6");
    ui->R4->setText("8");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta14()
{
    aniText(ui->preguntaText, "¿Cuál de las siguientes bases numéricas se utiliza comúnmente en la representación de números enteros en la vida cotidiana?");
    ui->R1->setText("Decimal");
    ui->R2->setText("Binaria");
    ui->R3->setText("Hexadecimal");
    ui->R4->setText("Octal");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta15()
{
    aniText(ui->preguntaText, "En el sistema hexadecimal, ¿qué representa el dígito 'C'?");
    ui->R1->setText("10");
    ui->R2->setText("12");
    ui->R3->setText("13");
    ui->R4->setText("15");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta16()
{
    aniText(ui->preguntaText, "¿Cual de las siguientes formas es correcta para representar un Unicode con Hexadecimal?");
    ui->R1->setText("/d00A9");
    ui->R2->setText("\\u00A9");
    ui->R3->setText("\\n00A9");
    ui->R4->setText("/u00A9");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta17()
{
    aniText(ui->preguntaText, "¿Cuál es la base numérica máxima que existe?");
    ui->R1->setText("16");
    ui->R2->setText("No existe un límite");
    ui->R3->setText("La cantidad de\n simbolos diferentes\n que existen");
    ui->R4->setText("La cantidad de\n numeros que existen");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta18()
{
    aniText(ui->preguntaText, "¿Cuál sí es una secuencia de números octales?");
    ui->R1->setText("57, 58, 60, 61, 62");
    ui->R2->setText("8, 10, 11, 12, 13");
    ui->R3->setText("926, 927, 930,\n 931, 932");
    ui->R4->setText("1010, 1011,\n 1012, 1013, 1014");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta19()
{
    aniText(ui->preguntaText, "¿Cuál de estos SÍ es un número Hexadecimal?");
    ui->R1->setText("1A2B3C");
    ui->R2->setText("XYZ12");
    ui->R3->setText("7F8G9");
    ui->R4->setText("A1B2K3");
    ui->aceptar->setText("Comprobar");
}
void module1test::pregunta20()
{
    aniText(ui->preguntaText, "¿Cuál sí es una secuencia de números Hexadecimales?");
    ui->R1->setText("EE, EF, F0, F1, F2");
    ui->R2->setText("5A, 5B, 5C, 54, 55");
    ui->R3->setText("AD, AE, AF, AG, B0");
    ui->R4->setText("88, 89, 70, 7A, 7B");
    ui->aceptar->setText("Comprobar");
}
void module1test::sinPreguntas()
{
    ui->R1->setDisabled(true);
    ui->R2->setDisabled(true);
    ui->R3->setDisabled(true);
    ui->R4->setDisabled(true);
    if(global::m1points < 8){
        aniText(ui->preguntaText, "Ya no quedan preguntas, intentelo de nuevo");
        ui->preguntaText->setStyleSheet(incorrectoEstilo);
        ui->points->setStyleSheet("color: red;");
    }else if(global::m1points<15){
        aniText(ui->preguntaText, "Ya no quedan preguntas, puede continuar");
        ui->preguntaText->setStyleSheet(preguntaEstilo);
        ui->points->setStyleSheet("color: black;");
    }else{
        aniText(ui->preguntaText, "¡Felicidades!, puede continuar");
        ui->preguntaText->setStyleSheet(correctoEstilo);
        ui->points->setStyleSheet("color: green;");
    }
    ui->points->setText(QString("%1/20").arg(global::m1points));
    ui->R1->setText("");
    ui->R2->setText("");
    ui->R3->setText("");
    ui->R4->setText("");
}

void module1test::on_aceptar_clicked()
{
    if(!timer->isActive()){
        if(ui->aceptar->text() == "Comprobar"){
            switch(numeroAleatorio){
            case 1: currentOption == 4 ? correcto(currentOption) : incorrecto(currentOption, 4);break;
            case 2: currentOption == 3 ? correcto(currentOption) : incorrecto(currentOption, 3);break;
            case 3: currentOption == 1 ? correcto(currentOption) : incorrecto(currentOption, 1);break;
            case 4: currentOption == 4 ? correcto(currentOption) : incorrecto(currentOption, 4);break;
            case 5: currentOption == 3 ? correcto(currentOption) : incorrecto(currentOption, 3);break;
            case 6: currentOption == 1 ? correcto(currentOption) : incorrecto(currentOption, 1);break;
            case 7: currentOption == 1 ? correcto(currentOption) : incorrecto(currentOption, 1);break;
            case 8: currentOption == 3 ? correcto(currentOption) : incorrecto(currentOption, 3);break;
            case 9: currentOption == 3 ? correcto(currentOption) : incorrecto(currentOption, 3);break;
            case 10: currentOption == 4 ? correcto(currentOption) : incorrecto(currentOption, 4);break;
            case 11: currentOption == 2 ? correcto(currentOption) : incorrecto(currentOption, 2);break;
            case 12: currentOption == 3 ? correcto(currentOption) : incorrecto(currentOption, 3);break;
            case 13: currentOption == 2 ? correcto(currentOption) : incorrecto(currentOption, 2);break;
            case 14: currentOption == 1 ? correcto(currentOption) : incorrecto(currentOption, 1);break;
            case 15: currentOption == 2 ? correcto(currentOption) : incorrecto(currentOption, 2);break;
            case 16: currentOption == 2 ? correcto(currentOption) : incorrecto(currentOption, 2);break;
            case 17: currentOption == 2 ? correcto(currentOption) : incorrecto(currentOption, 2);break;
            case 18: currentOption == 4 ? correcto(currentOption) : incorrecto(currentOption, 4);break;
            case 19: currentOption == 1 ? correcto(currentOption) : incorrecto(currentOption, 1);break;
            case 20: currentOption == 1 ? correcto(currentOption) : incorrecto(currentOption, 1);break;
            default: break;
           }
        }else{
            update();
        }
    }
}

void module1test::correcto(int r){
    global::m1points++;
    aniText(ui->preguntaText, "¡Respuesta correcta!");
    ui->preguntaText->setStyleSheet(correctoEstilo);
    ui->aceptar->setText("siguiente");

    switch(r){
        case 1: ui->R1->setStyleSheet(correctoEstilo); break;
        case 2: ui->R2->setStyleSheet(correctoEstilo); break;
        case 3: ui->R3->setStyleSheet(correctoEstilo); break;
        case 4: ui->R4->setStyleSheet(correctoEstilo); break;
    }
}
void module1test::incorrecto(int r, int c){
    aniText(ui->preguntaText, "¡Respuesta Incorrecta!");
    ui->preguntaText->setStyleSheet(incorrectoEstilo);
    ui->aceptar->setText("siguiente");

    switch(c){
    case 1: ui->R1->setStyleSheet(correctoEstilo); break;
    case 2: ui->R2->setStyleSheet(correctoEstilo); break;
    case 3: ui->R3->setStyleSheet(correctoEstilo); break;
    case 4: ui->R4->setStyleSheet(correctoEstilo); break;
    }

    switch(r){
    case 1: ui->R1->setStyleSheet(incorrectoEstilo); break;
    case 2: ui->R2->setStyleSheet(incorrectoEstilo); break;
    case 3: ui->R3->setStyleSheet(incorrectoEstilo); break;
    case 4: ui->R4->setStyleSheet(incorrectoEstilo); break;
    }
}

void module1test::on_R1_clicked()
{
    ui->R1->setStyleSheet("border: 2px solid teal; border-radius: 20px;"
                          "background-color: white;");
    ui->R2->setStyleSheet(r2style);
    ui->R3->setStyleSheet(r3style);
    ui->R4->setStyleSheet(r4style);
    currentOption = 1;
}


void module1test::on_R2_clicked()
{
    ui->R2->setStyleSheet("border: 2px solid blue; border-radius: 20px;"
                          "background-color: white;");
    ui->R1->setStyleSheet(r1style);
    ui->R3->setStyleSheet(r3style);
    ui->R4->setStyleSheet(r4style);
    currentOption = 2;
}


void module1test::on_R3_clicked()
{
    ui->R3->setStyleSheet("border: 2px solid purple; border-radius: 20px;"
                          "background-color: white;");
    ui->R1->setStyleSheet(r1style);
    ui->R2->setStyleSheet(r2style);
    ui->R4->setStyleSheet(r4style);
    currentOption = 3;
}


void module1test::on_R4_clicked()
{
    ui->R4->setStyleSheet("border: 2px solid orange; border-radius: 20px;"
                          "background-color: white;");
    ui->R1->setStyleSheet(r1style);
    ui->R2->setStyleSheet(r2style);
    ui->R3->setStyleSheet(r3style);
    currentOption = 4;
}
