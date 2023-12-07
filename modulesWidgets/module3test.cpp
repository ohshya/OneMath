#include "modulesWidgets/module3test.h"
#include "ui_module3test.h"
#include "global.h"
#include "mainwindow.h"
#include <QRandomGenerator>
#include <QRegularExpression>
#include <QValidator>

module3test::module3test(QWidget *parent) : QWidget(parent), ui(new Ui::module3test)
{
    ui->setupUi(this);
    ui->aviso->setVisible(false);
    global::m3[2]=0;
    global::m3[3]=0;
    QRegularExpression regex("(-?\\d+)|(-?∞)");
    QValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->LimLeft->setValidator(validator);
    ui->LimRigt->setValidator(validator);
    ui->LimLeft->setValidator(new QIntValidator(-999, 999, this));
    ui->LimRigt->setValidator(new QIntValidator(-999, 999, this));
    progressB();
    global::m3points = -1;
    update();
}

module3test::~module3test()
{
    delete ui;
}

void module3test::progressB()
{
    QString style = QString("#nextPart{image: url(:/assets/iconos/%1ok.png);}").arg(global::m3points);
    if(global::m3points < 6)
    {
        ui->nextPart->setDisabled(true);
        ui->nextPart->setStyleSheet(style);
        ui->aviso->setVisible(false);
    }else{
        ui->nextPart->setStyleSheet(okstyle);
        ui->nextPart->setDisabled(false);
        ui->aviso->setVisible(true);
    }
}

void module3test::on_nextPart_clicked()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    mainWin->switchToModulos();
}

void module3test::on_backModuleS_clicked()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    mainWin->switchToModule3();
}

void module3test::update(){
    global::m3points++;

    if(global::m3points > 3){
        global::m3[2] = 1;
    }
    if(global::m2points > 5){
        global::m3[3] = 1;
    }

    int min = 1;
    int max = 8;
    int randN;
    testCase = 0;
    if(listaRandoms.size()<8){
    do{
        randN = QRandomGenerator::global()->bounded(min, max + 1);
    }while(listaRandoms.contains(randN));
    }else{
        ui->pushButton->setDisabled(true);
        ui->funcion->setText("La prueba ha\n llegado a su fin");
        aniText(ui->titulo, "Sigue adelante →");
        randN = 0;
    }
    listaRandoms.insert(randN);
    testCase = randN;
    progressB();
    ui->funcion->setStyleSheet("border: 2px solid black;");
    limpiar();
    if(testCase!=0){
        QPixmap image(QString(":/assets/funciones/graph%1.png").arg(testCase));
        ui->funcion->setPixmap(image);
        ui->funcion->setScaledContents(true);
        ui->lim1->setPixmap(QString(":/assets/funciones/lim%1.png").arg(testCase));
    }else{
        ui->funcion->setPixmap(QPixmap(""));
        ui->funcion->setText("Haz finalizado \nlas preguntas");
        ui->pushButton->setDisabled(true);
    }
}

void module3test::caso1(){
    if (!(ui->opc0->isChecked() || ui->opc1->isChecked()) &&
        (ui->LimRigt->text() == "5" || ui->LimRigt->text() == "05")) {
        ui->pushButton->setText("Siguiente");
        ui->funcion->setStyleSheet("border: 4px solid green;");
    } else {
    ui->funcion->setStyleSheet("border: 4px solid red;");
    }
}

void module3test::caso2(){
    if (!ui->opc0->isChecked() && ui->opc1->isChecked()) {
        ui->pushButton->setText("Siguiente");
        global::m3points++;
        ui->funcion->setStyleSheet("border: 4px solid green;");
    } else {
        ui->funcion->setStyleSheet("border: 4px solid red;");
    }
}
void module3test::caso3(){
    if (!(ui->opc0->isChecked() || ui->opc1->isChecked()) &&
        (ui->LimRigt->text() == "2" || ui->LimRigt->text() == "02")) {
        ui->pushButton->setText("Siguiente");
        ui->funcion->setStyleSheet("border: 4px solid green;");
    } else {
        ui->funcion->setStyleSheet("border: 4px solid red;");
    }
}
void module3test::caso4(){
    if (!(ui->opc0->isChecked() || ui->opc1->isChecked()) &&
        (ui->LimRigt->text() == "1" || ui->LimRigt->text() == "01")) {
        ui->pushButton->setText("Siguiente");
        ui->funcion->setStyleSheet("border: 4px solid green;");
    } else {
        ui->funcion->setStyleSheet("border: 4px solid red;");
    }
}
void module3test::caso5(){
    if (!(ui->opc0->isChecked() || ui->opc1->isChecked()) &&
        (ui->LimRigt->text() == "1" || ui->LimRigt->text() == "01")){
        ui->pushButton->setText("Siguiente");
        ui->funcion->setStyleSheet("border: 4px solid green;");
    } else {
        ui->funcion->setStyleSheet("border: 4px solid red;");
    }
}
void module3test::caso6(){
    if ((ui->opc0->isChecked() || !ui->opc1->isChecked()) &&
        (ui->LimRigt->text() == "1" || ui->LimRigt->text() == "01") &&
        (ui->LimLeft->text() == "3" || ui->LimLeft->text() == "03")){
        ui->pushButton->setText("Siguiente");
        ui->funcion->setStyleSheet("border: 4px solid green;");
    } else {
        ui->funcion->setStyleSheet("border: 4px solid red;");
    }
}
void module3test::caso7(){
    if (!ui->opc0->isChecked() && ui->opc1->isChecked()) {
        ui->pushButton->setText("Siguiente");
        ui->funcion->setStyleSheet("border: 4px solid green;");
    } else {
        ui->funcion->setStyleSheet("border: 4px solid red;");
    }
}
void module3test::caso8(){
    if (!(ui->opc0->isChecked() || ui->opc1->isChecked()) &&
        (ui->LimRigt->text() == "1" || ui->LimRigt->text() == "01")){
        ui->pushButton->setText("Siguiente");
        ui->funcion->setStyleSheet("border: 4px solid green;");
    } else {
        ui->funcion->setStyleSheet("border: 4px solid red;");
    }
}

void module3test::on_pushButton_clicked()
{
    if(ui->pushButton->text() == "Comprobar"){
        switch(testCase){
        case 1:caso1(); break;
        case 2:caso2(); break;
        case 3:caso3(); break;
        case 4:caso4(); break;
        case 5:caso5(); break;
        case 6:caso6(); break;
        case 7:caso7(); break;
        case 8:caso8(); break;
        default: break;
        }
    }else{
        ui->pushButton->setText("Comprobar");
        update();
    }
}

void module3test::limpiar(){
    switch(testCase){
    case 1:aniText(ui->titulo, "X² + 3X - 5"); break;
    case 2:aniText(ui->titulo, "2X+1 / X-3"); break;
    case 3:aniText(ui->titulo, "√X+1"); break;
    case 4:aniText(ui->titulo, "e²ˣ"); break;
    case 5:aniText(ui->titulo, "Sin(X)"); break;
    case 6:aniText(ui->titulo, "2-sgn(X)"); break;
    case 7:aniText(ui->titulo, "3X+2/(X² + 1)(X - 1)²"); break;
    case 8:aniText(ui->titulo, "x³ - 2x² + 1"); break;
    default: break;
    }
    ui->LimLeft->setDisabled(true);
    ui->LimRigt->setDisabled(false);
    ui->LimLeft->setText("");
    ui->LimRigt->setText("");
    ui->opc0->setChecked(false);
    ui->opc1->setChecked(false);
    ui->chain->setVisible(true);
    ui->pushButton->setText("Comprobar");
}

void module3test::aniText(QLabel *label, QString text) //Texto Animado del titulo
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

void module3test::on_opc0_toggled(bool checked)
{
    if(checked){
        on_opc1_toggled(false);
        ui->opc1->setCheckState(Qt::Unchecked);
        ui->LimLeft->setDisabled(false);
        ui->chain->setVisible(false);
    }else{
        ui->LimLeft->setDisabled(true);
        ui->chain->setVisible(true);
        on_LimRigt_textChanged(ui->LimRigt->text());
    }
}

void module3test::on_opc1_toggled(bool checked)
{
    if(checked){
        on_opc0_toggled(false);
        ui->opc0->setCheckState(Qt::Unchecked);
        ui->LimLeft->setDisabled(true);
        ui->LimRigt->setDisabled(true);
        ui->LimLeft->setText("∞");
        ui->LimRigt->setText("-∞");
    }else{
        ui->LimLeft->setDisabled(true);
        ui->LimRigt->setDisabled(false);
        ui->chain->setVisible(true);
        ui->LimLeft->setText("");
        ui->LimRigt->setText("");
    }
}

void module3test::on_LimRigt_textChanged(const QString &arg1)
{
    if(!ui->LimLeft->isEnabled()){
        ui->LimLeft->setText(arg1);
    }
}
