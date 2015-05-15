#ifndef MATRIXTESTERAPP_H
#define MATRIXTESTERAPP_H

#include <QtWidgets/QMainWindow>
#include "ui_matrixtesterapp.h"

class MatrixTesterApp : public QMainWindow
{
	Q_OBJECT

public:
	MatrixTesterApp(QWidget *parent = 0);
	~MatrixTesterApp();

private:
	Ui::MatrixTesterAppClass ui;
};

#endif // MATRIXTESTERAPP_H
