#ifndef SKELETALRENDER_H
#define SKELETALRENDER_H

#include <qwidget.h>
#include <qgraphicswidget.h>
#include <qpainter.h>

#include "../Library/studio.h"

class SkeletalRender : public QWidget
{

public:
	Movement::Skeletal2d* Skeletal;

	QBrush backgroundBrush;

	QPen bonePen1;
	QPen bonePen2;

	QBrush jointBrush;
	QPen jointPen;
	int jointRadius;

	SkeletalRender(Movement::Skeletal2d* skeletal);

	~SkeletalRender();

	void paintEvent(QPaintEvent *event);

};

#endif // SKELETALRENDER_H
