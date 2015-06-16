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

		void set(const TMATRIX& matrix);

		virtual ~IActuator()
		{
		}
	};
}

#endif // MOVEMENT_IACTUATOR_H
