#include "skeletalrender.h"

SkeletalRender::SkeletalRender(Movement::Skeletal2d* skeletal)
{
	this->Skeletal = skeletal;
}

SkeletalRender::~SkeletalRender()
{
}

void SkeletalRender::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);

	for (int i = 1; i < this->Skeletal->ZeroPositions.PositionCount; i++)
	{
		painter.drawLine(this->Skeletal->ZeroPositions.Positions[i - 1]->Values[0],
							this->Skeletal->ZeroPositions.Positions[i - 1]->Values[1],
							this->Skeletal->ZeroPositions.Positions[i]->Values[0],
							this->Skeletal->ZeroPositions.Positions[i]->Values[1]);
	}

}
