#ifndef MOVEMENT_ACTUATORCONTROL_H
#define MOVEMENT_ACTUATORCONTROL_H

#include "core.h"
#include "common.h"

#include "movement-iactuator.h"

namespace Movement
{
	template <typename TMATRIX>
	struct ActuatorControl : public Common::ManagedList<IActuator<TMATRIX>>
	{



		~ActuatorControl()
		{
		}

	};
}

#endif // MOVEMENT_ACTUATORCONTROL_H
