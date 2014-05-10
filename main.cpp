#include <QtGui/QApplication>
#include "Ipp3.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Ipp3 foo;
    foo.show();
    return app.exec();
}
