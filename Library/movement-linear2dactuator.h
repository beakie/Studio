#ifndef MOVEMENT_LINEAR2DACTUATOR_H
#define MOVEMENT_LINEAR2DACTUATOR_H

#include "space2d-plot.h"
#include "space2d-transformmatrixbuilders_.h"
#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE>
	class Linear2dActuator : public IActuator<Common::Matrix3<TVALUE>> // Translates along X axis
	{
	public:
		TVALUE Translation;
			
		Linear2dActuator()
		{
		}

		void setLocalActuation(Common::Matrix3<TVALUE>& matrix)
		{
			matrix = Space2d::getTranslationMatrix(Translation, 0);
		}

		virtual ~Linear2dActuator()
		{
		}
	};
}

#endif // MOVEMENT_LINEAR2DACTUATOR_H
