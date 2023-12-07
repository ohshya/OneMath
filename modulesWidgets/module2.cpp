#include "modulesWidgets/module2.h"
#include "ui_module2.h"
#include "mainwindow.h"
#include "global.h"
#include <QMessageBox>

module2::module2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::module2)
{
    ui->setupUi(this);
    setBG();
    ui->stackedWidget->setCurrentIndex(global::m2part);
    actualizar();
}

module2::~module2()
{
    delete ui;
}

void module2::setBG()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    QPixmap backgroundImage(":/assets/otros/background.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    mainWin->setPalette(palette);
}

void module2::actualizar()
{
    switch(global::m2part)
    {
    case 0:aniText(ui->partText, "Introducción: Conjuntos y elementos");break;
    case 1:aniText(ui->partText, "Introducción: Notación de conjuntos");break;
    case 2:aniText(ui->partText, "Operaciones: Unión e Intersección");break;
    case 3:aniText(ui->partText, "Operaciones: Diferencia y Complemento");break;
    case 4:aniText(ui->partText, "Operaciones: Diferencia Simetrica");break;
    default: break;
    }

    global::calcularTotal();
    if(global::m2total<2){ui->nextPart->setDisabled(true);}
    else{ui->nextPart->setDisabled(false);}
}

void module2::on_backModuleS_clicked()
{
    if(!timer->isActive()){
        MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
        if (mainWin) {
            mainWin->switchToModulos();
        }
    }
}

void module2::aniText(QLabel *label, QString text)
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

void module2::on_stack0_clicked()
{
    if(!timer->isActive()){
        global::m2part = 0;
        ui->stackedWidget->setCurrentIndex(0);
        actualizar();
    }
}

void module2::on_stack1_clicked()
{
    if(!timer->isActive()){
        ui->stackedWidget->setCurrentIndex(1);
        global::m2part = 1;
        actualizar();
    }
}


void module2::on_stack2_clicked()
{
    if(!timer->isActive()){
        ui->stackedWidget->setCurrentIndex(2);
        global::m2part = 2; global::m2[0]=1; actualizar();

    }
}


void module2::on_stack3_clicked()
{
    if(!timer->isActive()){
        global::m2part = 3;
        ui->stackedWidget->setCurrentIndex(3);
        actualizar();
    }
}

void module2::on_stack4_clicked()
{
    if(!timer->isActive()){
        global::m2part = 4;
        ui->stackedWidget->setCurrentIndex(4);
        global::m2[1]=1; actualizar();
    }
}

void module2::on_nextPart_clicked()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    if (mainWin && !timer->isActive()) {
        if(global::m2points > 0 ){
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
                global::m2points = 0;
                mainWin->switchToModule2Test();
            }
        }else{
            mainWin->switchToModule2Test();
        }
    }
}
