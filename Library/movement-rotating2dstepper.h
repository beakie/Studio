#ifndef MOVEMENT_ROTATING2DSTEPPER_H
#define MOVEMENT_ROTATING2DSTEPPER_H

#include "space2d-plot.h"
#include "space2d-transformmatrixbuilders_.h"
#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE>
	class Rotating2dStepper : IActuator<Common::Matrix3<TVALUE>>
	{
	public:

		Rotating2dStepper()
		{
		}

		void setLocalActuation(Common::Matrix3<TVALUE>& matrix)
		{
			matrix = Common::Matrix3<TVALUE>::getIdentity();
		}

		virtual ~Rotating2dStepper()
		{
		}
	};
}

#endif // MOVEMENT_ROTATING2DSTEPPER_H
