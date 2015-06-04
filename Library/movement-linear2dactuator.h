#ifndef MOVEMENTLINEAR2DACTUATOR_H
#define MOVEMENTLINEAR2DACTUATOR_H

#include "space2d-plot.h"

namespace Movement
{
	template <typename TVALUE>
	class Linear2dActuator
	{
	public:
		TVALUE Translation;

		Linear2dActuator()
		{
		}

		virtual ~Linear2dActuator()
		{
		}
	};
}

#endif // MOVEMENTLINEAR2DACTUATOR_H
