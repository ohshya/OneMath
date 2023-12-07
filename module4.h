#ifndef MODULE4_H
#define MODULE4_H

#include <QWidget>
#include <QTimer>
#include <QLabel>

namespace Ui {
class module4;
}

class module4 : public QWidget
{
    Q_OBJECT

public:
    explicit module4(QWidget *parent = nullptr);
    ~module4();
    QString okstyle = QString("#nextPart{ \
                            image: url(:/buttons/buttons/ok.png);   \
                            background: transparent;}               \
                            #nextPart:hover{                        \
                            image: url(:/buttons/buttons/okH.png);} \
                            #nextPart:pressed{                      \
                            image: url(:/buttons/buttons/okP.png);} \
                            #nextPart:disabled{                     \
                            image: url(:/buttons/buttons/okD.png);}");
    void setBG();
    void actualizar();
    void aniText(QLabel *label, QString text);
    void progressB();

private slots:
    void on_backModuleS_clicked();

    void on_anterior_clicked();

    void on_siguiente_clicked();

    void on_nextPart_clicked();

private:
    Ui::module4 *ui;
    QTimer* timer;
};

#endif // MODULE4_H
