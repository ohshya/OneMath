#include "mainWidgets/moduleselection.h"
#include "ui_moduleselection.h"
#include "extendedWidgets/slidingstackedwidget.h"
#include "mainwindow.h"
#include <QDebug>
#include "global.h"

//iniciarlizador:
moduleSelection::moduleSelection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::moduleSelection)
{
    ui->setupUi(this);
    //Qframes clickeables:
    connect(ui->frameM1, &ClickableFrame::clicked, this, &moduleSelection::frameM1_clicked);
    connect(ui->frameM2, &ClickableFrame::clicked, this, &moduleSelection::frameM2_clicked);
    connect(ui->frameM3, &ClickableFrame::clicked, this, &moduleSelection::frameM3_clicked);
    connect(ui->frameM4, &ClickableFrame::clicked, this, &moduleSelection::frameM4_clicked);

    //Control Del StackedWidget y sus transiciones:
    ui->stackedWidget->setCurrentIndex(global::indice);
    checkPrevNext();

    ui->stackedWidget->setAnimation(QEasingCurve::Type::OutQuart);
    ui->stackedWidget->setSpeed(400);
    connect(ui->prev,&QAbstractButton::clicked,[=]{
        if(ui->stackedWidget->slideInPrev()){
            ui->prev->setEnabled(false);
            ui->next->setEnabled(false);
            ui->stackedWidget->setEnabled(false);
        }
    });
    connect(ui->next,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget->slideInNext()){
            ui->prev->setEnabled(false);
            ui->next->setEnabled(false);
        }
    });
    connect(ui->stackedWidget,&SlidingStackedWidget::animationFinished,[this]{
        ui->prev->setEnabled(true);
        ui->next->setEnabled(true);
        ui->stackedWidget->setEnabled(true);
        global::indice = ui->stackedWidget->currentIndex();;
        checkPrevNext();
    });

    //Control de las barras de progreso
    global::calcularTotal();
    ui->progressM1->setValue((global::m1total)*25);
    ui->progressM2->setValue((global::m2total)*25);
    ui->progressM3->setValue((global::m3total)*25);
    ui->progressM4->setValue((global::m4total)*25);

    if(global::switchControl == 1) {
        ui->progressM1->setValue(100);
        ui->progressM2->setValue(100);
        ui->progressM3->setValue(100);
        ui->progressM4->setValue(100);
    }

    //Control tarjetas
    ui->frameM2->setDisabled(true);
    ui->frameM3->setDisabled(true);
    ui->frameM4->setDisabled(true);

    if(global::m1total==4 || global::switchControl==1){
        QString newStyleSheet = ui->frameM2->styleSheet();
        newStyleSheet += "\n#frameM2 { background-image: url(:/assets/modules/module2.png); }";
        ui->frameM2->setStyleSheet(newStyleSheet);
        ui->frameM2->setDisabled(false);
    }
    if(global::m2total==4 || global::switchControl==1){
        QString newStyleSheet2 = ui->frameM3->styleSheet();
        newStyleSheet2 += "\n#frameM3 { background-image: url(:/assets/modules/module3.png); }";
        ui->frameM3->setStyleSheet(newStyleSheet2);
        ui->frameM3->setDisabled(false);
    }
    if(global::m3total==4 || global::switchControl==1){
        QString newStyleSheet3 = ui->frameM4->styleSheet();
        newStyleSheet3 += "\n#frameM4 { background-image: url(:/assets/modules/module4.png); }";
        ui->frameM4->setStyleSheet(newStyleSheet3);
        ui->frameM4->setDisabled(false);
    }
}

moduleSelection::~moduleSelection()
{
    delete ui;
}

void moduleSelection::checkPrevNext() //función deshabilitar botones prev o next
{
    ui->prev->setDisabled(global::indice == 0);
    ui->next->setDisabled(global::indice == 3);
}

//botones:
void moduleSelection::on_modulesBToMain_clicked() //botón para volver al mainWindow
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    if (mainWin) {
        mainWin->switchToMainWindow();
    }
}

void moduleSelection::frameM1_clicked() //botón para entrar en el modulo 1
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    if (mainWin) {
        mainWin->switchToModule1();
    }
}
void moduleSelection::frameM2_clicked() //botón para entrar en el modulo 2
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    if (mainWin) {
        mainWin->switchToModule2();
    }
}
void moduleSelection::frameM3_clicked() //botón para entrar en el modulo 3
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    if (mainWin) {
        mainWin->switchToModule3();
    }
}
void moduleSelection::frameM4_clicked() //botón para entrar en el modulo 4
{
    MainWindow *mainWin = qobject_cast<MainWindow*>(parent());
    if (mainWin) {
        mainWin->switchToModule4();
    }
}
