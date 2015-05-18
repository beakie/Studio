#include "skeletalrender.h"

SkeletalRender::SkeletalRender(Movement::Skeletal2d* skeletal)
{
	this->Skeletal = skeletal;

	backgroundBrush = QBrush(Qt::white);

	jointBrush = QBrush(Qt::yellow);
	jointPen = QPen(Qt::red);
	jointPen.setWidth(1);

	bonePen = QPen(Qt::blue);
	bonePen.setWidth(1);
}

void SkeletalRender::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing, true);

	painter.fillRect(0, 0, this->width(), this->height(), backgroundBrush);

	for (int i = 1; i < this->Skeletal->ZeroPositions.PositionCount; i++)
	{
		painter.setPen(bonePen);
		painter.drawLine(this->Skeletal->ZeroPositions.Positions[i - 1]->Values[0], this->Skeletal->ZeroPositions.Positions[i - 1]->Values[1], this->Skeletal->ZeroPositions.Positions[i]->Values[0], this->Skeletal->ZeroPositions.Positions[i]->Values[1]);
	}

	for (int i = 0; i < this->Skeletal->ZeroPositions.PositionCount; i++)
	{
		painter.setPen(jointPen);
		painter.setBrush(jointBrush);
		painter.drawEllipse(this->Skeletal->ZeroPositions.Positions[i]->Values[0] - jointRadius, this->Skeletal->ZeroPositions.Positions[i]->Values[1] - jointRadius, jointRadius * 2, jointRadius * 2);
	}

}

SkeletalRender::~SkeletalRender()
{
}
