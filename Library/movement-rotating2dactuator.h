#ifndef MOVEMENTROTATING2DACTUATOR_H
#define MOVEMENTROTATING2DACTUATOR_H

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

#endif // MOVEMENTROTATING2DACTUATOR_H
