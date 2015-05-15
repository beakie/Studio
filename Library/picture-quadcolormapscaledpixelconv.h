#ifndef PICTUREQUADCOLORMAPSCALEDPIXELCONV_H
#define PICTUREQUADCOLORMAPSCALEDPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	//template specialization the main function. will be quicker, and end resulting would be the same... code base is bigger but worth every bytes

	template <typename TUNITINTERVAL, typename TVALUEIN, typename TVALUEOUT>
	class QuadColorMapScaledPixelConv
	{
	private:
		const QuadColorMap<TUNITINTERVAL>* _colorMap; // transform this on population. lowerbound defines offset, upperbound lets calc of multiplication
		FloatMax _inLowerBound;
		FloatMax _inUpperBound;
		FloatMax _inBoundDiff;
		FloatMax _outLowerBound;
		FloatMax _outUpperBound;
		FloatMax _outBoundDiff;
		UInt8 _lastIndex;
		TUNITINTERVAL _spacing;
		FloatMax _indexUnfloored;
		UInt8 _index;
		TUNITINTERVAL _fromMapping;
		TUNITINTERVAL _toMapping;
		FloatMax _toUnitInterval;
		FloatMax _diffUnitInterval;
		FloatMax _channel[4];

	public:
		QuadColorMapScaledPixelConv(const QuadColorMap<TUNITINTERVAL>* colorMap, const TVALUEIN lowerBound, const TVALUEIN upperBound) //should this be input type templates?
		{
			_colorMap = colorMap;
			_inLowerBound = lowerBound;
			_inUpperBound = upperBound;
			_inBoundDiff = upperBound - lowerBound;
			_lastIndex = _colorMap->Size - 1;
			_spacing = ((TUNITINTERVAL)1 / _lastIndex);
			_outLowerBound = Common::getLowerBound<TVALUEOUT>();
			_outUpperBound = Common::getUpperBound<TVALUEOUT>();
			_outBoundDiff = _outUpperBound - _outLowerBound;
		}

		QuadColorMapScaledPixelConv(const QuadColorMap<TUNITINTERVAL>* colorMap)
			: QuadColorMapScaledPixelConv(colorMap, Common::getLowerBound<TVALUEIN>(), Common::getUpperBound<TVALUEIN>())
		{
		}

		Common::Vector4<TVALUEOUT> convertPixel(const TVALUEIN& value)
		{
			if (value == _inUpperBound)
				return Common::Vector4<TVALUEOUT>((_colorMap->Values[_lastIndex].Values[0] * _outBoundDiff) + _outLowerBound,
													(_colorMap->Values[_lastIndex].Values[1] * _outBoundDiff) + _outLowerBound,
													(_colorMap->Values[_lastIndex].Values[2] * _outBoundDiff) + _outLowerBound,
													(_colorMap->Values[_lastIndex].Values[3] * _outBoundDiff) + _outLowerBound);

			_indexUnfloored = ((FloatMax)value - _inLowerBound) / _inBoundDiff / _spacing;
			_index = (UInt8)_indexUnfloored;

			if (_indexUnfloored == _index)
				return Common::Vector4<TVALUEOUT>((_colorMap->Values[_index].Values[0] * _outBoundDiff) + _outLowerBound,
													(_colorMap->Values[_index].Values[1] * _outBoundDiff) + _outLowerBound,
													(_colorMap->Values[_index].Values[2] * _outBoundDiff) + _outLowerBound,
													(_colorMap->Values[_index].Values[3] * _outBoundDiff) + _outLowerBound);


			_toUnitInterval = (_index + 1) * _spacing;
			_diffUnitInterval = 1 - ((_toUnitInterval - (((FloatMax)value - _inLowerBound) / _inBoundDiff)) / (_toUnitInterval - (_index * _spacing)));

			for (UInt8 i = 0; i < 4; i++)
			{
				_fromMapping = _colorMap->Values[_index].Values[i];
				_toMapping = _colorMap->Values[_index + 1].Values[i];

				if (_fromMapping == _toMapping)
					_channel[i] = _fromMapping;
				else
					_channel[i] = ((_toMapping - _fromMapping) * _diffUnitInterval) + _fromMapping;
			}

			return Common::Vector4<TVALUEOUT>((_channel[0] * _outBoundDiff) + _outLowerBound,
												(_channel[1] * _outBoundDiff) + _outLowerBound,
												(_channel[2] * _outBoundDiff) + _outLowerBound,
												(_channel[3] * _outBoundDiff) + _outLowerBound);
		}
	};

}

#endif // PICTUREQUADCOLORMAPSCALEDPIXELCONV_H
