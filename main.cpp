#include <QApplication>
#include "mainwindow.h"
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString dataPath = QCoreApplication::applicationDirPath() + QDir::separator() + "data";
    QCoreApplication::addLibraryPath(dataPath);

    MainWindow mainWindow;
    mainWindow.setFixedSize(1000, 600);
    mainWindow.setWindowTitle("OneMath");
    mainWindow.setWindowIcon(QIcon(":/assets/otros/icon.ico"));
    mainWindow.show();
    return app.exec();
}
