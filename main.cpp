#include <QApplication>
#include "bolderdash.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bolderdash mBolderdash;

    mBolderdash.showFullScreen();

    return a.exec();
}
