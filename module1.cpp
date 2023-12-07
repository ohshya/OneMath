#include "module1.h"
#include "ui_module1.h"
#include "mainwindow.h"
#include "global.h"
#include <QDebug>
#include <QTimer>
#include <QIntValidator>
#include <QtMath>
#include <QWidget>
#include <QtGlobal>
#include <QMessageBox>

module1::module1(QWidget *parent) : QWidget(parent), ui(new Ui::module1)
{
    ui->setupUi(this);
    setBG();
    actualizar();
    switch(global::m1part)
    {
    case 1: aumentarDecimal(); break;
    case 3: aumentarOctal(); break;
    default: break;
    }

    connect(ui->B0, &QPushButton::clicked, this, [=](){
        if(!timer->isActive()){
            global::m1part=0; actualizar();
        }});
    connect(ui->B1, &QPushButton::clicked, this, [=](){
        if(!timer->isActive() && global::m1part!=1){aumentarDecimal();
            global::m1part=1; actualizar();
        }});

    connect(ui->B2, &QPushButton::clicked, this, [=](){
        if(!timer->isActive() && global::m1part!=2){
            global::m1[0]=1; global::m1part=2; actualizar();
        }});

    connect(ui->B3, &QPushButton::clicked, this, [=](){
        if(!timer->isActive() && global::m1part!=3){aumentarOctal();
            global::m1part=3; actualizar();
        }});

    connect(ui->B4, &QPushButton::clicked, this, [=](){
        if(!timer->isActive() && global::m1part!=4){
            global::m1[1]=1; global::m1part=4; actualizar();
        }});

    ui->decToBi->setValidator(new QIntValidator(0, 99999999, this));
    ui->biToDec->setValidator(new QRegularExpressionValidator(QRegularExpression("^[01]{1,18}$"), this));
    connect(ui->decToBi, &QLineEdit::textChanged, this, &module1::convertirDecimalABinario);
    connect(ui->biToDec, &QLineEdit::textChanged, this, &module1::convertirBinarioADecimal);
}

module1::~module1()
{
    delete ui;
}

void module1::actualizar()
{
    botones();
    titulo();
    ui->stackedWidget->setCurrentIndex(global::m1part);
    global::calcularTotal();
    if(global::m1total<2){ui->nextPart->setDisabled(true);}
    else{ui->nextPart->setDisabled(false);}
}

void module1::on_backModuleS_clicked()
{
    if(!timer->isActive()){
        MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
        if (mainWin) {
            mainWin->switchToModulos();
        }
    }
}

void module1::on_nextPart_clicked()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    if (mainWin && !timer->isActive()) {
        if(global::m1points > 0 ){
            QMessageBox msgBox;
            msgBox.setWindowTitle("¿Continuar?");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText("¿Quieres realizar el test nuevamente?<br>Se borrará tu puntuación anterior");
            msgBox.setStyleSheet("QLabel{qproperty-alignment: AlignCenter; }");
            msgBox.setFont(QFont("Sitka", 12));
            msgBox.setTextFormat(Qt::RichText);
            msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Cancel);
            int ret = msgBox.exec();
            if (ret == QMessageBox::Ok) {
                global::m1points = 0;
                mainWin->switchToModule1Test();
            }
        }else{
            mainWin->switchToModule1Test();
        }
    }
}

void module1::aniText(QLabel *label, QString text) //Texto Animado del titulo
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

void module1::convertirDecimalABinario()
{
    bool ok;
    int decimal = ui->decToBi->text().toInt(&ok);
    if (ok) {
        ui->binario->setWordWrap(true);
        QString binarioStr = QString::number(decimal, 2);
        ui->binario->setText(binarioStr);
    } else {
        ui->binario->setText("Binario");
    }
}

void module1::convertirBinarioADecimal()
{
    QString binario = ui->biToDec->text();
    static QRegularExpression binaryRegex("^[01]{1,18}$");

    if (binaryRegex.match(binario).hasMatch()) {
        bool ok;
        int decimal = binario.toInt(&ok, 2);

        if (ok) {
            ui->decimal->setText(QString("%1").arg(decimal));
        } else {
            ui->decimal->setText("Decimal");
        }
    } else {
        ui->decimal->setText("Decimal");
    }
}

void module1::calcularOperacionOctal()
{
    QStringList octalValues = ui->octal->text().split("\n");
    QString octalRText;
    for (int i = 0; i < octalValues.size(); ++i) {
        bool ok;
        int octalNumber = octalValues[i].toInt(&ok);
        if (ok) {
            int resultado = octalNumber * qPow(8, i);
            octalRText += QString::number(resultado);
            if (i < octalValues.size() - 1) {
                octalRText += "\n";
            }
        }
    }
    ui->octalR->setText(octalRText);
    actualizarResultado();
}

void module1::actualizarResultado()
{
    QStringList octalRValues = ui->octalR->text().split("\n");
    int suma = 0;
    for (const QString& value : octalRValues) {
        bool ok;
        int resultado = value.toInt(&ok);
        if (ok) {
            suma += resultado;
        }
    }
    QString resultadoText = QString("(%1)₁₀").arg(suma);
    ui->resultado->setText(resultadoText);
    QString sumaEnOctal = QString::number(suma, 8);
    QString resultado2Text = QString("(%1)₈").arg(sumaEnOctal);
    ui->resultado2->setText(resultado2Text);

}

void module1::aumentarDecimal()
{
    ui->contador->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
    if(!Cdecimal){
        Cdecimal=true;
        QTimer *timer = new QTimer(this);
        timer->start(50);
        connect(timer, &QTimer::timeout, this, [&]() mutable{
            ++contadorValue;
            QString contadorText = QString("%1  %2  %3  %4  %5  %6  %7")
           .arg((contadorValue / 1000000) % 10)
           .arg((contadorValue / 100000) % 10)
           .arg((contadorValue / 10000) % 10)
           .arg((contadorValue / 1000) % 10)
           .arg((contadorValue / 100) % 10)
           .arg((contadorValue / 10) % 10)
           .arg(contadorValue % 10);
            ui->contador->setText(contadorText);
        });
    }
}

void module1::aumentarOctal()
{
    QTimer *octalTimer = new QTimer(this);
    octalTimer->start(100);
    connect(octalTimer, &QTimer::timeout, this, [=]() mutable {
        ++contadorOctalValue;
        QString contadorOctalText = QString("%1\n%2\n%3\n%4\n%5\n%6\n%7")
        .arg((contadorOctalValue / 1) % 8)
        .arg((contadorOctalValue / 8) % 8)
        .arg((contadorOctalValue / 64) % 8)
        .arg((contadorOctalValue / 512) % 8)
        .arg((contadorOctalValue / 4096) % 8)
        .arg((contadorOctalValue / 32768) % 8)
        .arg((contadorOctalValue / 262144) % 8);
        ui->octal->setText(contadorOctalText);
        calcularOperacionOctal();
    });
}

void module1::setBG()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    QPixmap backgroundImage(":/assets/background3.jpeg");
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    mainWin->setPalette(palette);
}

void module1::titulo(){
    switch(global::m1part){
    case 0: aniText(ui->partText, "Introducción: Sistemas numéricos");
            ui->stackedWidget->setCurrentIndex(0); break;
    case 1: aniText(ui->partText, "Sistema Decimal (Base 10)"); break;
    case 2: aniText(ui->partText, "Sistema Binario (Base 2)"); break;
    case 3: aniText(ui->partText, "Sistema Octal (Base 8)"); break;
    case 4: aniText(ui->partText, "Sistema Hexadecimal (Base 16)"); break;
    default: break;
    }
}

void module1::botones(){
    if(global::m1[0]==0){
        ui->B0->setStyleSheet("#B0{background: transparent; background-image: url(:/buttons/buttons/nH.png);}");
    }if(global::m1part==1){
        ui->B1->setStyleSheet("#B1{background: transparent; background-image: url(:/buttons/buttons/n10H.png);}");
    }if(global::m1part==2){
        ui->B2->setStyleSheet("#B2{background: transparent; background-image: url(:/buttons/buttons/n2H.png);}");
    }if(global::m1part==3){
        ui->B3->setStyleSheet("#B3{background: transparent; background-image: url(:/buttons/buttons/n8H.png);}");
    }if(global::m1part==4){
        ui->B4->setStyleSheet("#B4{background: transparent; background-image: url(:/buttons/buttons/n16H.png);}");
    }
}
