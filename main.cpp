#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.setFixedSize(1000, 600);
    mainWindow.setWindowTitle("OneMath");
    mainWindow.setWindowIcon(QIcon(":/assets/icon.ico"));
    mainWindow.show();
    return app.exec();
}
