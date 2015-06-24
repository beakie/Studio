#ifndef MOVEMENT_ROTATING2DSERVO_H
#define MOVEMENT_ROTATING2DSERVO_H

#include "space2d-plot.h"
#include "space2d-transformmatrixbuilders_.h"
#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE>
	class Rotating2dServo : IActuator<Common::Matrix3<TVALUE>>
	{
	public:
		TVALUE Angle;

		Rotating2dServo()
		{
		}

		void set(Common::Matrix3<TVALUE>& matrix)
		{
			matrix = Space2d::getRotationMatrix(Angle);
		}

		virtual ~Rotating2dServo()
		{
		}
	};
}

#endif // MOVEMENT_ROTATING2DSERVO_H
