#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <profiles.h>

class QWidget;
class QPushButton;

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setBG();
    void botones();
    void setMainGif();
    void profileB();

public slots: //Declarar funciones de cambio de ventana Aquí:
    void switchToMainWindow();
    void switchToModulos();
    void switchToConfig();
    void switchToPerfiles();
    void switchToModule1();
    void switchToModule1Test();
    void switchToModule2();
    void switchToModule2Test();
    void switchToModule3();
    void switchToModule3Test();
    void switchToModule4();
    void creditos();
    void logo_clicked();

private:
    QWidget *currentUI;
    void loadUI(QWidget *uiWidget);
    void unloadCurrentUI();
    profiles *profilesInstance;
    Ui::MainWindow *ui;
};
#endif
