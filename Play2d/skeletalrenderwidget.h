#ifndef SKELETALRENDERWIDGET_H
#define SKELETALRENDERWIDGET_H

#include <qwidget.h>
#include <qgraphicswidget.h>
#include <qpainter.h>
#include <qstring.h>
#include <qlineedit.h>

#include "../Library/studio.h"

template <typename TPOINT, typename TMATRIX>
class SkeletalRenderWidget : public QWidget
{

public:
	Skeletals::Implemented<TPOINT, TMATRIX>* Skeletal;

	QBrush backgroundBrush;

	QPen zeroPositionBonePen;

	QBrush zeroPositionJointBrush;
	QPen zeroPositionJointPen;
	int zeroPositionJointRadius;

	QPen translatedPositionBonePen;

	QBrush translatedPositionJointBrush;
	QPen translatedPositionJointPen;
	int translatedPositionJointRadius;

	QLineEdit* angle1Edit;
	QLineEdit* angle2Edit;
	QLineEdit* angle3Edit;
	QLineEdit* angle4Edit;
	QLineEdit* angle5Edit;

	SkeletalRenderWidget(Skeletals::Implemented<TPOINT, TMATRIX>* skeletal)
	{
		angle1Edit = new QLineEdit(this);
		angle2Edit = new QLineEdit(this);
		angle3Edit = new QLineEdit(this);
		angle4Edit = new QLineEdit(this);
		angle5Edit = new QLineEdit(this);

		angle1Edit->setText("100");
		angle1Edit->move(0, 0);
		angle2Edit->setText("200");
		angle2Edit->move(0, 25);
		angle3Edit->setText("300");
		angle3Edit->move(0, 50);
		angle4Edit->setText("400");
		angle4Edit->move(0, 75);
		angle5Edit->setText("500");
		angle5Edit->move(0, 100);
		this->setMinimumSize(750, 500);

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
		renderPointList(this->Skeletal->ZeroPositions, painter, this->zeroPositionJointPen, this->zeroPositionJointBrush, this->zeroPositionJointRadius, offsetX, offsetY);

		Movement::PointList<TPOINT> translatedJointPositions = Movement::getTranslatedJointPositions(this->Skeletal->Joints, this->Skeletal->BoneMap, this->Skeletal->ZeroPositions);

		// ***** Angles

		// This needs the values from IActuators... ToString()?
		Common::ManagedList<FloatMax> angleList = Common::ManagedList<FloatMax>();
		angleList.add(angle1Edit->text().toFloat());
		angleList.add(angle2Edit->text().toFloat());
		angleList.add(angle3Edit->text().toFloat());
		angleList.add(angle4Edit->text().toFloat());
		angleList.add(angle5Edit->text().toFloat());

		renderAngles(translatedJointPositions, angleList, painter, this->translatedPositionJointPen, offsetX, offsetY);

		// ***** Bones (Translated)
		renderLineList(SkeletalRender::getJointToJointBoneLines(this->Skeletal->BoneMap, translatedJointPositions), painter, this->translatedPositionBonePen, offsetX, offsetY);

		// ***** Joints (Translated)
		renderPointList(translatedJointPositions, painter, this->translatedPositionJointPen, this->translatedPositionJointBrush, this->translatedPositionJointRadius, offsetX, offsetY);

		// ***** Bones (Zero - Direct Connection Method)
		//for (int i = 1; i < this->Skeletal->ZeroPositions.PointCount; i++)
		//{
		//	painter.setPen(this->bonePen);
		//	painter.drawLine(this->Skeletal->ZeroPositions.Points[i - 1]->Values[0], this->Skeletal->ZeroPositions.Points[i - 1]->Values[1], this->Skeletal->ZeroPositions.Points[i]->Values[0], this->Skeletal->ZeroPositions.Points[i]->Values[1]);
		//}

	}

	void renderLineList(Common::ManagedList<Common::Tuple2<Space2d::PlotF, Space2d::PlotF>, UInt8> lineList, QPainter& painter, QPen pen, const int offsetX, const int offsetY)
	{
		painter.setPen(pen);

		for (int i = 0; i < lineList.count(); i++)
			painter.drawLine(lineList.Items[i]->Item1.Values[0] + offsetX, lineList.Items[i]->Item1.Values[1] + offsetY, lineList.Items[i]->Item2.Values[0] + offsetX, lineList.Items[i]->Item2.Values[1] + offsetY);
	}

	void renderPointList(Movement::PointList<TPOINT> pointList, QPainter& painter, QPen pen, QBrush brush, const int jointRadius, const int offsetX, const int offsetY)
	{
		painter.setPen(pen);
		painter.setBrush(brush);

		for (int i = 0; i < pointList.PointCount; i++)
			painter.drawEllipse(pointList.Points[i]->Values[0] + offsetX - jointRadius, pointList.Points[i]->Values[1] + offsetY - jointRadius, jointRadius * 2, jointRadius * 2);
	}

	void renderAngles(Movement::PointList<TPOINT> pointList, Common::ManagedList<FloatMax> angleList, QPainter& painter, QPen pen, const int offsetX, const int offsetY)
	{
		painter.setPen(pen);
		
		for (int i = 0; i < pointList.PointCount; i++)
		{
			QString angleString = QString::number((double)*angleList.Items[i]);
			painter.drawText(pointList.Points[i]->Values[0] + offsetX - 10, pointList.Points[i]->Values[1] + offsetY - 10, angleString);
		}
	}

	~SkeletalRenderWidget()
	{
	}

};

#endif // SKELETALRENDERWIDGET_H
