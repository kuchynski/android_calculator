#include <QApplication>
#include "ccommander.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CCommander widget_main;

    widget_main.resize(500, 500);
    widget_main.show(); //    widget_main.showFullScreen();
    a.setWindowIcon(QIcon(":/andrcalc.ico"));
    return a.exec();
}
