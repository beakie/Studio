#include "skeletalrender.h"

SkeletalRender::SkeletalRender(Movement::Skeletal2d* skeletal)
{
	this->Skeletal = skeletal;
}

SkeletalRender::~SkeletalRender()
{
	jointBrush = QBrush(Qt::red);
	jointPen = QPen(Qt::red);
	jointPen.setWidth(6);

	boneBrush = QBrush(Qt::blue);
	bonePen = QPen(Qt::black);
	bonePen.setWidth(1);
}

void SkeletalRender::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);

	for (int i = 0; i < this->Skeletal->ZeroPositions.PositionCount; i++)
	{

		if (i > 0)
		{
			painter.setPen(bonePen);
			painter.setBrush(boneBrush);
			painter.drawLine(this->Skeletal->ZeroPositions.Positions[i - 1]->Values[0], this->Skeletal->ZeroPositions.Positions[i - 1]->Values[1], this->Skeletal->ZeroPositions.Positions[i]->Values[0], this->Skeletal->ZeroPositions.Positions[i]->Values[1]);
		}

		painter.setPen(jointPen);
		painter.setBrush(jointBrush);
		painter.drawEllipse(this->Skeletal->ZeroPositions.Positions[i]->Values[0] - jointRadius, this->Skeletal->ZeroPositions.Positions[i]->Values[1] - jointRadius, jointRadius * 2, jointRadius * 2);
	}

}
