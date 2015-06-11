#ifndef SKELETALRENDERWIDGET_H
#define SKELETALRENDERWIDGET_H

#include <qwidget.h>
#include <qgraphicswidget.h>
#include <qpainter.h>
#include <qstring.h>

#include "../Library/studio.h"

template <typename TPOINT, typename TMATRIX>
class SkeletalRenderWidget : public QWidget
{

public:
	Skeletals::DefinitionUncompressed<TPOINT, TMATRIX>* Skeletal;

	QBrush backgroundBrush;

	QPen zeroPositionBonePen;

	QBrush zeroPositionJointBrush;
	QPen zeroPositionJointPen;
	int zeroPositionJointRadius;

	QPen translatedPositionBonePen;

	QBrush translatedPositionJointBrush;
	QPen translatedPositionJointPen;
	int translatedPositionJointRadius;

	SkeletalRenderWidget(Skeletals::DefinitionUncompressed<TPOINT, TMATRIX>* skeletal)
	{
		this->Skeletal = skeletal;

		this->backgroundBrush = QBrush(Qt::white);

		this->zeroPositionJointBrush = QBrush(Qt::lightGray);
		this->zeroPositionJointPen = QPen(Qt::blue);
		this->zeroPositionJointPen.setWidth(1);
		this->zeroPositionJointRadius = 2;

		this->zeroPositionBonePen = QPen(Qt::darkGray);
		this->zeroPositionBonePen.setWidth(2);

		this->translatedPositionJointBrush = QBrush(Qt::green);
		this->translatedPositionJointPen = QPen(Qt::red);
		this->translatedPositionJointPen.setWidth(1);
		this->translatedPositionJointRadius = 4;

		this->translatedPositionBonePen = QPen(Qt::blue);
		this->translatedPositionBonePen.setWidth(2);
	}

	void paintEvent(QPaintEvent *event)
	{
		QPainter painter(this);

		painter.setRenderHint(QPainter::Antialiasing, true);

		painter.fillRect(0, 0, this->width(), this->height(), backgroundBrush);

		int offsetX = this->width() / 2;
		int offsetY = this->height() / 2;

		// ***** Bones (Zero)
		renderLineList(SkeletalRender::getJointToJointBoneLines(this->Skeletal->BoneMap, this->Skeletal->ZeroPositions), painter, this->zeroPositionBonePen, offsetX, offsetY);

		//////// ***** Joints (Zero)
		renderPositionList(this->Skeletal->ZeroPositions, painter, this->zeroPositionJointPen, this->zeroPositionJointBrush, this->zeroPositionJointRadius, offsetX, offsetY);

		Movement::PositionList<TPOINT> translatedJointPositions = Movement::getTranslatedJointPositions(this->Skeletal->Joints, this->Skeletal->BoneMap, this->Skeletal->ZeroPositions);

		// ***** Angles

		Common::ManagedList<FloatMax> angleList = Common::ManagedList<FloatMax>();
		angleList.add(10);
		angleList.add(20);
		angleList.add(30);
		angleList.add(40);
		angleList.add(50);

		renderAngles(translatedJointPositions, angleList, painter, this->translatedPositionJointPen, offsetX, offsetY);

		// ***** Bones (Translated)
		renderLineList(SkeletalRender::getJointToJointBoneLines(this->Skeletal->BoneMap, translatedJointPositions), painter, this->translatedPositionBonePen, offsetX, offsetY);

		// ***** Joints (Translated)
		renderPositionList(translatedJointPositions, painter, this->translatedPositionJointPen, this->translatedPositionJointBrush, this->translatedPositionJointRadius, offsetX, offsetY);

		// ***** Bones (Zero - Direct Connection Method)
		//for (int i = 1; i < this->Skeletal->ZeroPositions.PositionCount; i++)
		//{
		//	painter.setPen(this->bonePen);
		//	painter.drawLine(this->Skeletal->ZeroPositions.Positions[i - 1]->Values[0], this->Skeletal->ZeroPositions.Positions[i - 1]->Values[1], this->Skeletal->ZeroPositions.Positions[i]->Values[0], this->Skeletal->ZeroPositions.Positions[i]->Values[1]);
		//}

	}

	void renderLineList(Common::ManagedList<Common::Tuple2<Space2d::PlotF, Space2d::PlotF>, UInt8> lineList, QPainter& painter, QPen pen, const int offsetX, const int offsetY)
	{
		painter.setPen(pen);

		for (int i = 0; i < lineList.count(); i++)
			painter.drawLine(lineList.Items[i]->Item1.Values[0] + offsetX, lineList.Items[i]->Item1.Values[1] + offsetY, lineList.Items[i]->Item2.Values[0] + offsetX, lineList.Items[i]->Item2.Values[1] + offsetY);
	}

	void renderPositionList(Movement::PositionList<TPOINT> positionList, QPainter& painter, QPen pen, QBrush brush, const int jointRadius, const int offsetX, const int offsetY)
	{
		painter.setPen(pen);
		painter.setBrush(brush);

		for (int i = 0; i < positionList.PositionCount; i++)
			painter.drawEllipse(positionList.Positions[i]->Values[0] + offsetX - jointRadius, positionList.Positions[i]->Values[1] + offsetY - jointRadius, jointRadius * 2, jointRadius * 2);
	}

	void renderAngles(Movement::PositionList<TPOINT> positionList, Common::ManagedList<FloatMax> angleList, QPainter& painter, QPen pen, const int offsetX, const int offsetY)
	{
		painter.setPen(pen);
		
		for (int i = 0; i < positionList.PositionCount; i++)
		{
			QString angleString = QString::number((double)*angleList.Items[i]);
			painter.drawText(positionList.Positions[i]->Values[0] + offsetX - 10, positionList.Positions[i]->Values[1] + offsetY - 10, angleString);
		}
	}

	~SkeletalRenderWidget()
	{
	}

};

#endif // SKELETALRENDERWIDGET_H
