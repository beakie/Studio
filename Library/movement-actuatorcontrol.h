#ifndef MOVEMENT_ACTUATORCONTROL_H
#define MOVEMENT_ACTUATORCONTROL_H

#include "core.h"
#include "common.h"

#include "movement-iactuator.h"

namespace Movement
{
	template <typename TMATRIX>
	struct ActuatorControl : public Common::ManagedList<IActuator<TMATRIX>, UInt8>
	{

		template <typename TACTUATOR>
		TACTUATOR & get(const UInt8 n)
		{
			return *((TACTUATOR*)(Items[n]));
		}

		~ActuatorControl()
		{
		}

	};
}

#endif // MOVEMENT_ACTUATORCONTROL_H
