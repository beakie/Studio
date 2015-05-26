#ifndef SKELETALRENDER_H
#define SKELETALRENDER_H

#include <qwidget.h>
#include <qgraphicswidget.h>
#include <qpainter.h>

#include "../Library/studio.h"

template <typename TPOINT, typename TMATRIX>
class SkeletalRender : public QWidget
{

public:
	Movement::SkeletalManifest<TPOINT, TMATRIX>* SkeletalManifest;

	QBrush backgroundBrush;
	QPen bonePen1;
	QPen bonePen2;
	QBrush jointBrush;
	QPen jointPen;
	int jointRadius;

	SkeletalRender(Movement::SkeletalManifest<TPOINT, TMATRIX>* skeletalManifest)
	{
		this->SkeletalManifest = skeletalManifest;

		this->backgroundBrush = QBrush(Qt::white);

		this->jointBrush = QBrush(Qt::yellow);
		this->jointPen = QPen(Qt::blue);
		this->jointPen.setWidth(1);
		this->jointRadius = 4;

		this->bonePen1 = QPen(Qt::blue);
		this->bonePen2 = QPen(Qt::red);
		this->bonePen1.setWidth(2);
		this->bonePen2.setWidth(2);
	}

	void paintEvent(QPaintEvent *event)
	{
		QPainter painter(this);

		painter.setRenderHint(QPainter::Antialiasing, true);

		painter.fillRect(0, 0, this->width(), this->height(), backgroundBrush);

		int offsetX = this->width() / 2;
		int offsetY = this->height() / 2;

		// ***** Bones (Zero - Direct Connection Method)

		//for (int i = 1; i < this->SkeletalManifest->ZeroPositions.PositionCount; i++)
		//{
		//	painter.setPen(this->bonePen);
		//	painter.drawLine(this->SkeletalManifest->ZeroPositions.Positions[i - 1]->Values[0], this->SkeletalManifest->ZeroPositions.Positions[i - 1]->Values[1], this->SkeletalManifest->ZeroPositions.Positions[i]->Values[0], this->SkeletalManifest->ZeroPositions.Positions[i]->Values[1]);
		//}

		// ***** Joints (Zero Position)

		for (int i = 0; i < this->SkeletalManifest->ZeroPositions.PositionCount; i++)
		{
			painter.setPen(this->jointPen);
			painter.setBrush(this->jointBrush);
			painter.drawEllipse(this->SkeletalManifest->ZeroPositions.Positions[i]->Values[0] - jointRadius + offsetX, this->SkeletalManifest->ZeroPositions.Positions[i]->Values[1] - jointRadius + offsetY, jointRadius * 2, jointRadius * 2);
		}

		//// ***** Bones (Translated - Direct Connection Method)

		//Common::ManagedList<Space2d::LineSegment2d<>, UInt8> lineList = BodyRender::getJointToJointBones(*this->SkeletalManifest);

		//for (int i = 0; i < lineList.count(); i++)
		//{
		//	if (i % 2 == 0)
		//		painter.setPen(this->bonePen1);
		//	else
		//		painter.setPen(this->bonePen2);

		//	UInt8 fromX = lineList.Items[i]->PlotFrom.Values[0];
		//	UInt8 fromY = lineList.Items[i]->PlotFrom.Values[1];
		//	UInt8 toX = lineList.Items[i]->PlotTo.Values[0];
		//	UInt8 toY = lineList.Items[i]->PlotTo.Values[1];

		//	painter.drawLine(fromX + offsetX, fromY + offsetY, toX + offsetX, toY + offsetY);
		//}

		// ***** Joints (Translated)

		Movement::PositionList<TPOINT> translatedJoints = Movement::getTranslatedJoints(this->SkeletalManifest->Joints, this->SkeletalManifest->BoneMap, this->SkeletalManifest->ZeroPositions);

		for (int i = 0; i < translatedJoints.PositionCount; i++)
		{
			painter.setPen(this->jointPen);
			painter.setBrush(this->jointBrush);
			painter.drawEllipse(translatedJoints.Positions[i]->Values[0] - jointRadius + offsetX, translatedJoints.Positions[i]->Values[1] - jointRadius + offsetY, jointRadius * 2, jointRadius * 2);
		}

		// *****

	}

	~SkeletalRender()
	{
	}

};

#endif // SKELETALRENDER_H
