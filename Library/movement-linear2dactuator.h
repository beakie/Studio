#ifndef MOVEMENT_LINEAR2DACTUATOR_H
#define MOVEMENT_LINEAR2DACTUATOR_H

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

#endif // MOVEMENT_LINEAR2DACTUATOR_H
