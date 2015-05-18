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

	SkeletalRender(Movement::Skeletal2d* skeletal);

	~SkeletalRender();

	void paintEvent(QPaintEvent *event);

};

#endif // SKELETALRENDER_H
