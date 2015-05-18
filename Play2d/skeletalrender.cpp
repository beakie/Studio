#include "skeletalrender.h"

SkeletalRender::SkeletalRender(Movement::Skeletal2d* skeletal)
{
	this->Skeletal = skeletal;

	this->backgroundBrush = QBrush(Qt::white);

	this->jointBrush = QBrush(Qt::yellow);
	this->jointPen = QPen(Qt::blue);
	this->jointPen.setWidth(1);
	this->jointRadius = 4;

	this->bonePen = QPen(Qt::blue);
	this->bonePen.setWidth(2);
}

void SkeletalRender::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing, true);

	painter.fillRect(0, 0, this->width(), this->height(), backgroundBrush);

	//for (int i = 1; i < this->Skeletal->ZeroPositions.PositionCount; i++)
	//{
	//	painter.setPen(this->bonePen);
	//	painter.drawLine(this->Skeletal->ZeroPositions.Positions[i - 1]->Values[0], this->Skeletal->ZeroPositions.Positions[i - 1]->Values[1], this->Skeletal->ZeroPositions.Positions[i]->Values[0], this->Skeletal->ZeroPositions.Positions[i]->Values[1]);
	//}

	//for (int i = 0; i < this->Skeletal->ZeroPositions.PositionCount; i++)
	//{
	//	painter.setPen(this->jointPen);
	//	painter.setBrush(this->jointBrush);
	//	painter.drawEllipse(this->Skeletal->ZeroPositions.Positions[i]->Values[0] - jointRadius, this->Skeletal->ZeroPositions.Positions[i]->Values[1] - jointRadius, jointRadius * 2, jointRadius * 2);
	//}

	Common::ManagedList<Space2d::LineSegment2d<>, UInt8> lineList = BodyRender::getJointToJointBones(*this->Skeletal);

	for (int i = 0; i < lineList.count(); i++)
	{
		painter.setPen(this->jointPen);
		painter.drawLine(lineList.Items[i]->PlotFrom.Values[0], lineList.Items[i]->PlotFrom.Values[1], lineList.Items[i]->PlotTo.Values[0], lineList.Items[i]->PlotTo.Values[1]);
	}

}

SkeletalRender::~SkeletalRender()
{
}
