#ifndef MODULE1TEST_H
#define MODULE1TEST_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QSet>

namespace Ui {
class module1test;
}

class module1test : public QWidget
{
    Q_OBJECT

public:
    explicit module1test(QWidget *parent = nullptr);
    ~module1test();
    void aniText(QLabel *label, QString text);

    QString okstyle = QString("#nextPart{ \
                            image: url(:/assets/iconos/ok.png);     \
                            background: transparent;}               \
                            #nextPart:hover{                        \
                            image: url(:/assets/iconos/okH.png);}   \
                            #nextPart:pressed{                      \
                            image: url(:/assets/iconos/okP.png);}   \
                            #nextPart:disabled{                     \
                            image: url(:/assets/iconos/okD.png.png);}");

    QString estiloBotonRStandar = QString("QPushButton{     \
                                    background-color: white;\
                                    border: 2px solid black;\
                                    border-radius: 20px;}   \
                                    QPushButton:hover{");

    QString r1style = estiloBotonRStandar + "border: 2px solid teal;}";
    QString r2style = estiloBotonRStandar + "border: 2px solid blue;}";
    QString r3style = estiloBotonRStandar + "border: 2px solid purple;}";
    QString r4style = estiloBotonRStandar + "border: 2px solid orange;}";
    QString correctoEstilo = "border:2px solid green; border-radius:20px; background-color:white; color: green;";
    QString incorrectoEstilo = "border:2px solid red; border-radius:20px; background-color:white; color: red;";
    QString preguntaEstilo = "border:2px solid black; border-radius:20px; background-color:white; color: black";


    void progressB();
    void update();
    int numeroAleatorio = 0;
    int currentOption = 0;
    QSet<int> listaRandoms;
    void pregunta1();
    void pregunta2();
    void pregunta3();
    void pregunta4();
    void pregunta5();
    void pregunta6();
    void pregunta7();
    void pregunta8();
    void pregunta9();
    void pregunta10();
    void pregunta11();
    void pregunta12();
    void pregunta13();
    void pregunta14();
    void pregunta15();
    void pregunta16();
    void pregunta17();
    void pregunta18();
    void pregunta19();
    void pregunta20();
    void sinPreguntas();
    void correcto(int r);
    void incorrecto(int r, int c);

private slots:
    void on_backModuleS_clicked();
    void on_nextPart_clicked();

    void on_aceptar_clicked();

    void on_R1_clicked();

    void on_R2_clicked();

    void on_R3_clicked();

    void on_R4_clicked();

private:
    Ui::module1test *ui;
    QTimer* timer;
};

#endif // MODULE1TEST_H
