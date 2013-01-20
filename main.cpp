#include <QApplication>
#include "qkmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QKMainWindow w;
    w.show(); 
    return a.exec();
}
