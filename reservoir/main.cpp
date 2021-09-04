/* Include the header file the primary executable code (c++) - by 'mainwindow.cpp' 
 * Include the QT Application header
*/
#include "mainwindow.h"
#include <QApplication> 

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

