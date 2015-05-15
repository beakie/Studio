#include "matrixtesterapp.h"
#include <QtWidgets/QApplication>
#include "../Library/studio.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MatrixTesterApp w;
	w.show();
	return a.exec();
}
