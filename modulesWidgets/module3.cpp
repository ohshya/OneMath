#include "module3.h"
#include "ui_module3.h"
#include "mainwindow.h"
#include "global.h"
#include <QMessageBox>

module3::module3(QWidget *parent) : QWidget(parent), ui(new Ui::module3)
{
    ui->setupUi(this);
    setBG();
    ui->stackedWidget->setCurrentIndex(global::m3part);
    actualizar();
}

module3::~module3()
{
    delete ui;
}

void module3::setBG()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    QPixmap backgroundImage(":/assets/otros/background.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    mainWin->setPalette(palette);
}

void module3::actualizar()
{
    if(ui->stackedWidget->currentIndex() == 4){
        global::m3[0] = 1;
        global::m3[1] = 1;
    }

    switch(global::m3part)
    {
        case 0:aniText(ui->partText, "Introducción: Limites");break;
        case 1:aniText(ui->partText, "Ejemplo: Limites Laterales");break;
        case 2:aniText(ui->partText, "Indeterminación");break;
        case 3:aniText(ui->partText, "Tendencia al infinito");break;
        case 4:aniText(ui->partText, "Calculo de limites");break;
    default: break;
    }

    global::calcularTotal();
    if(global::m3total<2){
        if(!global::switchControl)ui->nextPart->setDisabled(true);
    }
    else{ui->nextPart->setDisabled(false);}

    ui->stackedWidget->currentIndex() == 0 ? ui->anterior->setDisabled(true) : ui->anterior->setDisabled(false);
    ui->stackedWidget->currentIndex() == 4 ? ui->siguiente->setDisabled(true) : ui->siguiente->setDisabled(false);

}

void module3::on_backModuleS_clicked()
{
    if(!timer->isActive()){
        MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
        if (mainWin) {
            mainWin->switchToModulos();
        }
    }
}

void module3::aniText(QLabel *label, QString text) //Texto Animado del titulo
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

void module3::on_anterior_clicked()
{
    if(!timer->isActive()){
        int ind = ui->stackedWidget->currentIndex();
        ui->stackedWidget->setCurrentIndex(ind-1);
        global::m3part = ui->stackedWidget->currentIndex();
        actualizar();
    }
}

void module3::on_siguiente_clicked()
{
    if(!timer->isActive()){
        int ind = ui->stackedWidget->currentIndex();
        ui->stackedWidget->setCurrentIndex(ind+1);
        global::m3part = ui->stackedWidget->currentIndex();
        actualizar();
    }
}

void module3::on_nextPart_clicked()
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    if (mainWin && !timer->isActive()) {
        if(global::m3points > 0 ){
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
                global::m3points = 0;
                mainWin->switchToModule3Test();
            }
        }else{
            mainWin->switchToModule3Test();
        }
    }
}
