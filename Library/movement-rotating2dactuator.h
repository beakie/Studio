#ifndef MOVEMENT_ROTATING2DACTUATOR_H
#define MOVEMENT_ROTATING2DACTUATOR_H

#include "space2d-plot.h"
#include "space2d-transformmatrixbuilders_.h"

namespace Movement
{
	template <typename TVALUE, typename TMATRIX>
	class Rotating2dActuator
	{
	public:
		Rotating2dActuator()
		{
		}

		TMATRIX getJointMatrix(TVALUE angle)
		{
			return Space2d::getRotationMatrix(angle);
		}

		virtual ~Rotating2dActuator()
		{
		}
	};
}

#endif // MOVEMENT_ROTATING2DACTUATOR_H
