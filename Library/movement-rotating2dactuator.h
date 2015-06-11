#ifndef MOVEMENT_ROTATING2DACTUATOR_H
#define MOVEMENT_ROTATING2DACTUATOR_H

namespace Movement
{
	template <typename TVALUE>
	class Rotating2dActuator
	{
	public:
		TVALUE Angle;

		Rotating2dActuator()
		{
		}

		virtual ~Rotating2dActuator()
		{
		}
	};
}

#endif // MOVEMENT_ROTATING2DACTUATOR_H
