#include "login.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
#include <QSound>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSound Music(":/new/prefix1/MyResources/firefles-dreams.wav");
    LogIn w;
    w.show();  
    Connection c;
    try {
        bool test=c.createconnect();
        if(test)
{
//Music.play();
//Music.setLoops(-1);
        w.show();

        }
    } catch (QString s ) {

    }
    return a.exec();
}
