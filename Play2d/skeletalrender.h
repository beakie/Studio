#ifndef SKELETALRENDER_H
#define SKELETALRENDER_H

#include <qwidget.h>
#include <qgraphicswidget.h>
#include <qpainter.h>

#include "../Library/movement.h"

class SkeletalRender : public QWidget
{

public:
	Movement::Skeletal2d* Skeletal;

	QBrush backgroundBrush;
	QBrush jointBrush;
	QPen jointPen;
	QPen bonePen;

	int jointRadius = 5;

	SkeletalRender(Movement::Skeletal2d* skeletal);

	~SkeletalRender();

	void paintEvent(QPaintEvent *event);

};

#endif // SKELETALRENDER_H
