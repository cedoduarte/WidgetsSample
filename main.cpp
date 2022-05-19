#include "mainwindow.h"
#include "persona.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Persona::initialize();
    MainWindow w;
    w.show();
    return a.exec();
}
