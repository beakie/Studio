#ifndef MOVEMENT_ROTATIONLIST_H
#define MOVEMENT_ROTATIONLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct RotationList
	{
		TPOINT** Rotations;
		UInt8 RotationCount;

		RotationList()
			: Rotations(0),
			  RotationCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		RotationList(const RotationList<TPOINT>& rotationList)
		{
			Rotations = new TPOINT*[rotationList.RotationCount];

			for (UInt8 i = 0; i < rotationList.RotationCount; i++)
				Rotations[i] = new TPOINT(*rotationList.Rotations[i]);

			RotationCount = rotationList.RotationCount;
		}

		RotationList(UInt8 size)
			: RotationCount(size)
		{
			Rotations = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
				Rotations[i] = new TPOINT(TPOINT::getZero());
		}

		RotationList<TPOINT>& operator=(const RotationList<TPOINT>& rotationList)
		{
			TPOINT** tmpRotations = new TPOINT*[rotationList.RotationCount + 1];

			for (UInt8 i = 0; i < rotationList.RotationCount; i++)
				tmpRotations[i] = new TPOINT(*rotationList.Rotations[i]);

			delete[] Rotations;

			Rotations = tmpRotations;

			RotationCount = rotationList.RotationCount;

			return *this;
		}

		UInt8 addRotation()
		{
			TPOINT** tmpRotations = new TPOINT*[RotationCount + 1];

			for (UInt8 i = 0; i < RotationCount; i++)
				tmpRotations[i] = Rotations[i];

			tmpRotations[RotationCount] = new TPOINT(TPOINT::getZero());

			delete[] Rotations;

			Rotations = tmpRotations;

			RotationCount++;

			return RotationCount - 1;
		}

		~RotationList()
		{
			for (UInt8 i = 0; i < RotationCount; i++)
				delete Rotations[i];

			delete[] Rotations;
		}

	};
}

#endif // MOVEMENT_ROTATIONLIST_H