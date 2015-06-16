#ifndef MOVEMENT_ROTATIONLIST_H
#define MOVEMENT_ROTATIONLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TVECTOR>
	struct RotationList
	{
		TVECTOR** Rotations;
		UInt8 RotationCount;

		RotationList()
			: Rotations(0),
			  RotationCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		RotationList(const RotationList<TVECTOR>& rotationList)
		{
			Rotations = new TVECTOR*[rotationList.RotationCount];

			for (UInt8 i = 0; i < rotationList.RotationCount; i++)
				Rotations[i] = new TVECTOR(*rotationList.Rotations[i]);

			RotationCount = rotationList.RotationCount;
		}

		RotationList(UInt8 size)
			: RotationCount(size)
		{
			Rotations = new TVECTOR*[size];

			for (UInt8 i = 0; i < size; i++)
				Rotations[i] = new TVECTOR(TVECTOR::getZero());
		}

		RotationList<TVECTOR>& operator=(const RotationList<TVECTOR>& rotationList)
		{
			TVECTOR** tmpRotations = new TVECTOR*[rotationList.RotationCount + 1];

			for (UInt8 i = 0; i < rotationList.RotationCount; i++)
				tmpRotations[i] = new TVECTOR(*rotationList.Rotations[i]);

			delete[] Rotations;

			Rotations = tmpRotations;

			RotationCount = rotationList.RotationCount;

			return *this;
		}

		UInt8 addRotation()
		{
			TVECTOR** tmpRotations = new TVECTOR*[RotationCount + 1];

			for (UInt8 i = 0; i < RotationCount; i++)
				tmpRotations[i] = Rotations[i];

			tmpRotations[RotationCount] = new TVECTOR(TVECTOR::getZero());

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
