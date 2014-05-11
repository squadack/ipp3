#include <QtWidgets>
#include "Ipp3Window.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
	Ipp3Window window;
	window.show();
    return app.exec();
}
