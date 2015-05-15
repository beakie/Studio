#ifndef PIXELTESTERAPP_H
#define PIXELTESTERAPP_H

#include <QtWidgets/QMainWindow>
#include "ui_pixeltesterapp.h"

class PixelTesterApp : public QMainWindow
{
	Q_OBJECT

public:
	PixelTesterApp(QWidget *parent = 0);
	~PixelTesterApp();

private:
	Ui::PixelTesterAppClass ui;
};

#endif // PIXELTESTERAPP_H
