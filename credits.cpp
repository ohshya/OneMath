#include "credits.h"
#include "ui_credits.h"

Credits::Credits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credits)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Creditos");
}

Credits::~Credits()
{
    delete ui;
}
