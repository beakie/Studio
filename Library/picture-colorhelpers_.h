//128 64 192 255 0

#ifndef PICTURE_COLORHELPERS_H
#define PICTURE_COLORHELPERS_H

#include "common.h"

namespace Picture
{
	// Definitions

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getWhiteRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getSilverRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getGreyRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getBlackRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getRedRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getMaroonRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getYellowRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getOliveRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getLimeRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getGreenRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getAquaRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getTealRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getBlueRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getNavyRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getFuchsiaRgb();

	template <typename TVALUE = Common::UnitIntervalMax>
	static Common::Vector3<TVALUE> getPurpleRgb();

	// UnitInterval32
	
	template <>
	static Common::Vector3<Common::UnitInterval32> getWhiteRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(1.0, 1.0, 1.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getSilverRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.75, 0.75, 0.75);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getGreyRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.5, 0.5, 0.5);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getBlackRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.0, 0.0, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getRedRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(1.0, 0.0, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getMaroonRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.5, 0.0, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getYellowRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(1.0, 1.0, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getOliveRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.5, 0.5, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getLimeRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.0, 1.0, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getGreenRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.0, 0.5, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getAquaRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.0, 1.0, 1.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getTealRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.0, 0.5, 0.5);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getBlueRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.0, 0, 1.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getNavyRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.0, 0.0, 0.5);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getFuchsiaRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(1.0, 0.0, 1.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval32> getPurpleRgb()
	{
		return Common::Vector3<Common::UnitInterval32>(0.5, 0.0, 0.5);
	}

	// UnitInterval64

	template <>
	static Common::Vector3<Common::UnitInterval64> getWhiteRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(1.0, 1.0, 1.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getSilverRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.75, 0.75, 0.75);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getGreyRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.5, 0.5, 0.5);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getBlackRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.0, 0.0, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getRedRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(1.0, 0.0, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getMaroonRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.5, 0.0, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getYellowRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(1.0, 1.0, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getOliveRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.5, 0.5, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getLimeRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.0, 1.0, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getGreenRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.0, 0.5, 0.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getAquaRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.0, 1.0, 1.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getTealRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.0, 0.5, 0.5);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getBlueRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.0, 0, 1.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getNavyRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.0, 0.0, 0.5);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getFuchsiaRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(1.0, 0.0, 1.0);
	}

	template <>
	static Common::Vector3<Common::UnitInterval64> getPurpleRgb()
	{
		return Common::Vector3<Common::UnitInterval64>(0.5, 0.0, 0.5);
	}

	// UInt8

	template <>
	static Common::Vector3<UInt8> getWhiteRgb()
	{
		return Common::Vector3<UInt8>(255, 255, 255);
	}

	template <>
	static Common::Vector3<UInt8> getSilverRgb()
	{
		return Common::Vector3<UInt8>(192, 192, 192);
	}

	template <>
	static Common::Vector3<UInt8> getGreyRgb()
	{
		return Common::Vector3<UInt8>(128, 128, 128);
	}

	template <>
	static Common::Vector3<UInt8> getBlackRgb()
	{
		return Common::Vector3<UInt8>(0, 0, 0);
	}

	template <>
	static Common::Vector3<UInt8> getRedRgb()
	{
		return Common::Vector3<UInt8>(255, 0, 0);
	}

	template <>
	static Common::Vector3<UInt8> getMaroonRgb()
	{
		return Common::Vector3<UInt8>(128, 0, 0);
	}

	template <>
	static Common::Vector3<UInt8> getYellowRgb()
	{
		return Common::Vector3<UInt8>(255, 255, 0);
	}

	template <>
	static Common::Vector3<UInt8> getOliveRgb()
	{
		return Common::Vector3<UInt8>(128, 128, 0);
	}

	template <>
	static Common::Vector3<UInt8> getLimeRgb()
	{
		return Common::Vector3<UInt8>(0, 255, 0);
	}

	template <>
	static Common::Vector3<UInt8> getGreenRgb()
	{
		return Common::Vector3<UInt8>(0, 128, 0);
	}

	template <>
	static Common::Vector3<UInt8> getAquaRgb()
	{
		return Common::Vector3<UInt8>(0, 255, 255);
	}

	template <>
	static Common::Vector3<UInt8> getTealRgb()
	{
		return Common::Vector3<UInt8>(0, 128, 128);
	}

	template <>
	static Common::Vector3<UInt8> getBlueRgb()
	{
		return Common::Vector3<UInt8>(0, 0, 255);
	}

	template <>
	static Common::Vector3<UInt8> getNavyRgb()
	{
		return Common::Vector3<UInt8>(0, 0, 128);
	}

	template <>
	static Common::Vector3<UInt8> getFuchsiaRgb()
	{
		return Common::Vector3<UInt8>(255, 0, 255);
	}

	template <>
	static Common::Vector3<UInt8> getPurpleRgb()
	{
		return Common::Vector3<UInt8>(128, 0, 128);
	}

	// UInt16

	template <>
	static Common::Vector3<UInt16> getWhiteRgb()
	{
		return Common::Vector3<UInt16>(65535, 65535, 65535);
	}

	template <>
	static Common::Vector3<UInt16> getSilverRgb()
	{
		return Common::Vector3<UInt16>(49151, 49151, 49151);
	}

	template <>
	static Common::Vector3<UInt16> getGreyRgb()
	{
		return Common::Vector3<UInt16>(32767, 32767, 32767);
	}

	template <>
	static Common::Vector3<UInt16> getBlackRgb()
	{
		return Common::Vector3<UInt16>(0, 0, 0);
	}

	template <>
	static Common::Vector3<UInt16> getRedRgb()
	{
		return Common::Vector3<UInt16>(65535, 0, 0);
	}

	template <>
	static Common::Vector3<UInt16> getMaroonRgb()
	{
		return Common::Vector3<UInt16>(32767, 0, 0);
	}

	template <>
	static Common::Vector3<UInt16> getYellowRgb()
	{
		return Common::Vector3<UInt16>(65535, 65535, 0);
	}

	template <>
	static Common::Vector3<UInt16> getOliveRgb()
	{
		return Common::Vector3<UInt16>(32767, 32767, 0);
	}

	template <>
	static Common::Vector3<UInt16> getLimeRgb()
	{
		return Common::Vector3<UInt16>(0, 65535, 0);
	}

	template <>
	static Common::Vector3<UInt16> getGreenRgb()
	{
		return Common::Vector3<UInt16>(0, 32767, 0);
	}

	template <>
	static Common::Vector3<UInt16> getAquaRgb()
	{
		return Common::Vector3<UInt16>(0, 65535, 65535);
	}

	template <>
	static Common::Vector3<UInt16> getTealRgb()
	{
		return Common::Vector3<UInt16>(0, 32767, 32767);
	}

	template <>
	static Common::Vector3<UInt16> getBlueRgb()
	{
		return Common::Vector3<UInt16>(0, 0, 65535);
	}

	template <>
	static Common::Vector3<UInt16> getNavyRgb()
	{
		return Common::Vector3<UInt16>(0, 0, 32767);
	}

	template <>
	static Common::Vector3<UInt16> getFuchsiaRgb()
	{
		return Common::Vector3<UInt16>(65535, 0, 65535);
	}

	template <>
	static Common::Vector3<UInt16> getPurpleRgb()
	{
		return Common::Vector3<UInt16>(32767, 0, 32767);
	}
}

#endif // PICTURE_COLORHELPERS_H
