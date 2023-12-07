#ifndef MODULESELECTION_H
#define MODULESELECTION_H

#include <QWidget>

namespace Ui {
class moduleSelection;
}

class moduleSelection : public QWidget
{
    Q_OBJECT

public:
    explicit moduleSelection(QWidget *parent = nullptr);
    ~moduleSelection();
    void checkPrevNext();
    void progressBar();

public slots:
    void on_modulesBToMain_clicked();
    void frameM1_clicked();
    void frameM2_clicked();
    void frameM3_clicked();
    void frameM4_clicked();

private:
    Ui::moduleSelection *ui;
};

#endif // MODULESELECTION_H
