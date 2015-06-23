#ifndef MOVEMENT_IACTUATOR_H
#define MOVEMENT_IACTUATOR_H

namespace Movement
{
	template <typename TMATRIX>
	class IActuator
	{
	public:
		IActuator()
		{
		}

		void set(TMATRIX& matrix);

		virtual ~IActuator()
		{
		}
	};
}

#endif // MOVEMENT_IACTUATOR_H
