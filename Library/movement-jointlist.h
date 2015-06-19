#ifndef MOVEMENT_JOINTLIST_H
#define MOVEMENT_JOINTLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TMATRIX>
	struct JointList
		: Common::ICollection<TMATRIX, UInt8>
	{
		TMATRIX** Joints;
		UInt8 JointCount;

		JointList()
			: Joints(0),
			  JointCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		JointList(const Common::ICollection<TMATRIX, UInt8>& jointList)
		{
			Joints = new TMATRIX*[jointList.JointCount];

			for (UInt8 i = 0; i < jointList.JointCount; i++)
				Joints[i] = new TMATRIX(*jointList.Joints[i]);

			JointCount = jointList.JointCount;
		}

		JointList(UInt8 size)
			: JointCount(size)
		{
			Joints = new TMATRIX*[size];

			for (UInt8 i = 0; i < size; i++)
				Joints[i] = new TMATRIX(TMATRIX::getIdentity());
		}

		JointList<TMATRIX>& operator=(const Common::ICollection<TMATRIX, UInt8>& jointList)
		{
			TMATRIX** tmpJoints = new TMATRIX*[jointList.JointCount + 1];

			for (UInt8 i = 0; i < jointList.JointCount; i++)
				tmpJoints[i] = new TMATRIX(*jointList.Joints[i]);

			delete[] Joints;

			Joints = tmpJoints;

			JointCount = jointList.JointCount;

			return *this;
		}

		TMATRIX& addJoint()
		{
			addJoint(TMATRIX::getIdentity());

			return *Joints[JointCount - 1];
		}

		void addJoint(const TMATRIX& item)
		{
			TMATRIX** tmpJoints = new TMATRIX*[JointCount + 1];

			for (UInt8 i = 0; i < JointCount; i++)
				tmpJoints[i] = Joints[i];

			tmpJoints[JointCount] = new TMATRIX(item);

			delete[] Joints;

			Joints = tmpJoints;

			JointCount++;
		}

		UInt8 count() const
		{
			return JointCount;
		}

		TMATRIX operator[] (UInt8 n) const
		{
			return *Joints[n];
		}

		~JointList()
		{
			for (UInt8 i = 0; i < JointCount; i++)
				delete Joints[i];

			delete[] Joints;
		}

	};
}

#endif // MOVEMENT_JOINTLIST_H
