#ifndef MOVEMENT_ROTATING2DMOTOR_H
#define MOVEMENT_ROTATING2DMOTOR_H

#include "space2d-plot.h"
#include "space2d-transformmatrixbuilders_.h"
#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE>
	class Rotating2dMotor : public IActuator<Common::Matrix3<TVALUE>>
	{
	public:
		TVALUE Intensity;

		Rotating2dMotor()
		{
		}

		void setLocalActuation(Common::Matrix3<TVALUE>& matrix)
		{
			matrix = Common::Matrix3<TVALUE>::getIdentity();
		}

		virtual ~Rotating2dMotor()
		{
		}
	};
}

#endif // MOVEMENT_ROTATING2DMOTOR_H
