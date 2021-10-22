#include "utilisateurr.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Utilisateurr w;
    w.show();
    return a.exec();
}
