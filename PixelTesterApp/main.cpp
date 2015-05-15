#include "pixeltesterapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	PixelTesterApp w;
	w.show();
	
	return a.exec();
}
