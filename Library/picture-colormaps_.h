#ifndef PICTURECOLORMAPS_H
#define PICTURECOLORMAPS_H

#include "core.h"
#include "common.h"

#include "picture-tricolormap.h"

namespace Picture
{

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	TriColorMap<TUNITINTERVAL> getRgbJetColorMap()
	{
		TriColorMap<TUNITINTERVAL> map(9);

		map.Values[0] = Common::Vector3<TUNITINTERVAL>(0.0, 0.0, 0.5);
		map.Values[1] = Common::Vector3<TUNITINTERVAL>(0.0, 0.0, 1.0);
		map.Values[2] = Common::Vector3<TUNITINTERVAL>(0.0, 0.5, 1.0);
		map.Values[3] = Common::Vector3<TUNITINTERVAL>(0.0, 1.0, 1.0);
		map.Values[4] = Common::Vector3<TUNITINTERVAL>(0.5, 1.0, 0.5);
		map.Values[5] = Common::Vector3<TUNITINTERVAL>(1.0, 1.0, 0.0);
		map.Values[6] = Common::Vector3<TUNITINTERVAL>(1.0, 0.5, 0.0);
		map.Values[7] = Common::Vector3<TUNITINTERVAL>(1.0, 0.0, 0.0);
		map.Values[8] = Common::Vector3<TUNITINTERVAL>(0.5, 0.0, 0.0);

		return map;
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static TriColorMap<TUNITINTERVAL> getRgbGreyColorMap()
	{
		TriColorMap<TUNITINTERVAL> map(2);

		map.Values[0] = Common::Vector3<TUNITINTERVAL>(0.0, 0.0, 0.0);
		map.Values[1] = Common::Vector3<TUNITINTERVAL>(1.0, 1.0, 1.0);

		return map;
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static TriColorMap<TUNITINTERVAL> getRgbCoolColorMap()
	{
		TriColorMap<TUNITINTERVAL> map(2);

		map.Values[0] = Common::Vector3<TUNITINTERVAL>(0.0, 1.0, 1.0);
		map.Values[1] = Common::Vector3<TUNITINTERVAL>(1.0, 0.0, 1.0);

		return map;
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static TriColorMap<TUNITINTERVAL> getRgbHotColorMap()
	{
		TriColorMap<TUNITINTERVAL> map(6);

		map.Values[0] = Common::Vector3<TUNITINTERVAL>(0.0, 0.0, 0.0);
		map.Values[1] = Common::Vector3<TUNITINTERVAL>(0.5, 0.0, 0.0);
		map.Values[2] = Common::Vector3<TUNITINTERVAL>(1.0, 0.0, 0.0);
		map.Values[3] = Common::Vector3<TUNITINTERVAL>(1.0, 0.5, 0.0);
		map.Values[4] = Common::Vector3<TUNITINTERVAL>(1.0, 1.0, 0.0);
		map.Values[5] = Common::Vector3<TUNITINTERVAL>(1.0, 1.0, 1.0);

		return map;
	}

}

#endif // PICTURECOLORMAPS_H
