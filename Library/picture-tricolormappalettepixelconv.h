#ifndef PICTURE_TRICOLORMAPPALETTEPIXELCONV_H
#define PICTURE_TRICOLORMAPPALETTEPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	//template specialization the main function. will be quicker, and end resulting would be the same... code base is bigger but worth every bytes

	template <typename TUNITINTERVAL, typename TVALUEIN, typename TVALUEOUT> // TVALUEIN should be UInt values only. how to specify this?
	class TriColorMapPalettePixelConv
	{
	private:
		const TriColorMap<TUNITINTERVAL>* _colorMap; // transform this on population. lowerbound defines offset, upperbound lets calc of multiplication
		FloatMax _outLowerBound;
		FloatMax _outUpperBound;
		FloatMax _outBoundDiff;

	public:
		TriColorMapPalettePixelConv(const TriColorMap<TUNITINTERVAL>* colorMap)
		{
			_colorMap = colorMap;
			_outLowerBound = Common::getLowerBound<TVALUEOUT>();
			_outUpperBound = Common::getUpperBound<TVALUEOUT>();
			_outBoundDiff = _outUpperBound - _outLowerBound;
		}

		Common::Vector3<TVALUEOUT> convertPixel(const TVALUEIN& value)
		{
			return Common::Vector3<TVALUEOUT>((_colorMap[value].Values[0] *_outBoundDiff) + _outLowerBound,
												(_colorMap[value].Values[1] * _outBoundDiff) + _outLowerBound,
												(_colorMap[value].Values[2] * _outBoundDiff) + _outLowerBound);
		}
	};

}

#endif // PICTURE_TRICOLORMAPPALETTEPIXELCONV_H
