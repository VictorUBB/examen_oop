#include "examen_oop.h"
#include <QtWidgets/QApplication>
#include "Gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileRepo repo{"input.txt"};
    Service serv{ repo };
    Gui gui{ serv };
    gui.show();
    return a.exec();
}
