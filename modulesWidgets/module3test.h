#ifndef MODULE3TEST_H
#define MODULE3TEST_H

#include <QWidget>
#include <QSet>
#include <QLabel>
#include <QTimer>

namespace Ui {
class module3test;
}

class module3test : public QWidget
{
    Q_OBJECT

public:
    explicit module3test(QWidget *parent = nullptr);
    ~module3test();

    QString okstyle = QString("#nextPart{ \
                            image: url(:/assets/iconos/ok.png);     \
                            background: transparent;}               \
                            #nextPart:hover{                        \
                            image: url(:/assets/iconos/okH.png);}   \
                            #nextPart:pressed{                      \
                            image: url(:/assets/iconos/okP.png);}   \
                            #nextPart:disabled{                     \
                            image: url(:/assets/iconos/okD.png.png);}");
    void progressB();
    void update();
    void limpiar();
    QSet<int> listaRandoms;
    void aniText(QLabel *label, QString text);
    void caso1();
    void caso2();
    void caso3();
    void caso4();
    void caso5();
    void caso6();
    void caso7();
    void caso8();
    void caso9();
    void caso10();

    int testCase=0;
private slots:
    void on_nextPart_clicked();
    void on_backModuleS_clicked();
    void on_pushButton_clicked();

    void on_opc0_toggled(bool checked);

    void on_LimRigt_textChanged(const QString &arg1);

    void on_opc1_toggled(bool checked);

private:
    Ui::module3test *ui;
    QTimer* timer;
};

#endif // MODULE3TEST_H
