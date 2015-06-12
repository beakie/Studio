#ifndef MOVEMENT_LINEAR2DACTUATOR_H
#define MOVEMENT_LINEAR2DACTUATOR_H

#include "space2d-plot.h"
#include "space2d-transformmatrixbuilders_.h"

namespace Movement
{
	template <typename TVALUE, typename TMATRIX>
	class Linear2dActuator // Translates along X axis
	{
	public:
		Linear2dActuator()
		{
		}

		TMATRIX getJointMatrix(TVALUE translation) // This means the function isnt generic
		{
			return Space2d::getTranslationMatrix(translation, 0);
		}

		virtual ~Linear2dActuator()
		{
		}
	};
}

#endif // MOVEMENT_LINEAR2DACTUATOR_H
