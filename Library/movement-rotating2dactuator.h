#ifndef MOVEMENT_ROTATING2DACTUATOR_H
#define MOVEMENT_ROTATING2DACTUATOR_H

#include "space2d-plot.h"
#include "space2d-transformmatrixbuilders_.h"
#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE, typename TMATRIX>
	class Rotating2dActuator : IActuator<TMATRIX>
	{
	public:
		TVALUE Angle;

		Rotating2dActuator()
		{
		}

		void set(const TMATRIX& matrix)
		{
			matrix = Space2d::getRotationMatrix(Angle);
		}

		virtual ~Rotating2dActuator()
		{
		}
	};
}

#endif // MOVEMENT_ROTATING2DACTUATOR_H
