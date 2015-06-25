#ifndef MOVEMENT_ROTATING2DSTEPPER_H
#define MOVEMENT_ROTATING2DSTEPPER_H

#include "space2d-plot.h"
#include "space2d-transformmatrixbuilders_.h"
#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE>
	class Rotating2dStepper : public IActuator<Common::Matrix3<TVALUE>>
	{
	public:
		int Steps;
		int Position; // Unlike the (unmodified) servo, this can rotate over and over

		Rotating2dStepper()
		{
		}

		Rotating2dStepper(int stepCount)
		{
			StepCount = stepCount;
		}

		void setLocalActuation(Common::Matrix3<TVALUE>& matrix)
		{
			matrix = Space2d::getRotationMatrix((Common::Pi * (360 / Steps * Position) / 180.0));
		}

		virtual ~Rotating2dStepper()
		{
		}
	};
}

#endif // MOVEMENT_ROTATING2DSTEPPER_H
