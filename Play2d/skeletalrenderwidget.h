#ifndef SKELETALRENDERWIDGET_H
#define SKELETALRENDERWIDGET_H

#include <qwidget.h>
#include <qgraphicswidget.h>
#include <qpainter.h>

#include "../Library/studio.h"

template <typename TPOINT, typename TMATRIX>
class SkeletalRenderWidget : public QWidget
{

public:
	Skeletals::BasicSkeletal<TPOINT, TMATRIX>* Skeletal;

	QBrush backgroundBrush;
	QPen zeroPositionBonePen;
	QBrush zeroPositionJointBrush;
	QPen zeroPositionJointPen;
	int zeroPositionJointRadius;

	SkeletalRenderWidget(Skeletals::BasicSkeletal<TPOINT, TMATRIX>* skeletal)
	{
		this->Skeletal = skeletal;

		this->backgroundBrush = QBrush(Qt::white);

		this->zeroPositionJointBrush = QBrush(Qt::lightGray);
		this->zeroPositionJointPen = QPen(Qt::blue);
		this->zeroPositionJointPen.setWidth(1);
		this->zeroPositionJointRadius = 4;

		this->zeroPositionBonePen = QPen(Qt::darkGray);
		this->zeroPositionBonePen.setWidth(2);
	}

	void paintEvent(QPaintEvent *event)
	{
		QPainter painter(this);

		painter.setRenderHint(QPainter::Antialiasing, true);

		painter.fillRect(0, 0, this->width(), this->height(), backgroundBrush);

		int offsetX = this->width() / 2;
		int offsetY = this->height() / 2;

		// ***** Bones (Zero - Direct Connection Method)

		//for (int i = 1; i < this->Skeletal->ZeroPositions.PositionCount; i++)
		//{
		//	painter.setPen(this->bonePen);
		//	painter.drawLine(this->Skeletal->ZeroPositions.Positions[i - 1]->Values[0], this->Skeletal->ZeroPositions.Positions[i - 1]->Values[1], this->Skeletal->ZeroPositions.Positions[i]->Values[0], this->Skeletal->ZeroPositions.Positions[i]->Values[1]);
		//}

		// ***** Joints (Zero Position)

		//renderLineList(SkeletalRender::getJointToJointBoneLines(this->Skeletal->BoneMap, this->Skeletal->ZeroPositions), painter, this->zeroPositionJointPen, offsetX, offsetY);

		////////in order to do this next line... i need a line base class to cater for both 2d and 3d
		//////Common::ManagedList<Common::Tuple2<TPOINT, TPOINT>, UInt8> zeroPositionJoints = ;

		//////renderLineList(SkeletalRender::getJointToJointBoneLines(this->Skeletal->BoneMap, this->Skeletal->ZeroPositions));
		//////for (int i = 0; i < this->Skeletal->ZeroPositions.PositionCount; i++)
		//////{
		//////	painter.setPen(this->jointPen);
		//////	painter.setBrush(this->jointBrush);
		//////	painter.drawEllipse(this->Skeletal->ZeroPositions.Positions[i]->Values[0] - jointRadius + offsetX, this->Skeletal->ZeroPositions.Positions[i]->Values[1] - jointRadius + offsetY, jointRadius * 2, jointRadius * 2);
		//////}

		// ***** Bones (Zero)
		renderLineList(SkeletalRender::getJointToJointBoneLines(this->Skeletal->BoneMap, this->Skeletal->ZeroPositions), painter, this->zeroPositionBonePen, offsetX, offsetY);

		//////// ***** Joints (Zero)
		//////renderPositionList(Movement::getTranslatedJointPositions(this->Skeletal->Joints, this->Skeletal->BoneMap, this->Skeletal->ZeroPositions), painter, this->zeroPositionJointPen, this->zeroPositionJointBrush, offsetX, offsetY);

		// ***** Bones (Translated)
		//renderLineList(SkeletalRender::getJointToJointBoneLines(this->Skeletal->BoneMap, this->Skeletal->ZeroPositions), painter, this->zeroPositionBonePen, offsetX, offsetY);

		// ***** Joints (Translated)
		renderPositionList(Movement::getTranslatedJointPositions(this->Skeletal->Joints, this->Skeletal->BoneMap, this->Skeletal->ZeroPositions), painter, this->zeroPositionJointPen, this->zeroPositionJointBrush, offsetX, offsetY);

	}

	void renderLineList(Common::ManagedList<Common::Tuple2<Space2d::PlotF64, Space2d::PlotF64>, UInt8> lineList, QPainter& painter, QPen pen, int offsetX, int offsetY)
	{
		for (int i = 0; i < lineList.count(); i++)
		{
			painter.setPen(pen);

			UInt8 fromX = lineList.Items[i]->Item1.Values[0];
			UInt8 fromY = lineList.Items[i]->Item1.Values[1];
			UInt8 toX = lineList.Items[i]->Item2.Values[0];
			UInt8 toY = lineList.Items[i]->Item2.Values[1];

			painter.drawLine(fromX + offsetX, fromY + offsetY, toX + offsetX, toY + offsetY);
		}
	}

	void renderPositionList(Movement::PositionList<TPOINT> positionList, QPainter& painter, QPen pen, QBrush brush, int offsetX, int offsetY)
	{
		painter.setPen(pen);
		painter.setBrush(brush);

		for (int i = 0; i < positionList.PositionCount; i++)
			painter.drawEllipse(positionList.Positions[i]->Values[0] - zeroPositionJointRadius + offsetX, positionList.Positions[i]->Values[1] - zeroPositionJointRadius + offsetY, zeroPositionJointRadius * 2, zeroPositionJointRadius * 2);
	}

	~SkeletalRenderWidget()
	{
	}

};

#endif // SKELETALRENDERWIDGET_H
