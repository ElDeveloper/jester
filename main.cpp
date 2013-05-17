#include <QApplication>
#include "JesterMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JesterMainWindow w;
    w.show();
    
    return a.exec();
}
