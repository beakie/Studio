#ifndef COMMONIMAGE_H
#define COMMONIMAGE_H

#include "common-bounds_.h"
#include "common-math_.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"

namespace Common
{
	template <typename TVALUE = FloatMax, typename TINDEX = UIntMax>
	/// <summary>
	/// 2 dimensional array of pixels
	/// </summary>
	struct Image
	{
		/// <summary>
		/// The values of the image stored in [x][y] form
		/// </summary>
		TVALUE** Pixels;

		/// <summary>
		/// The width of the image
		/// </summary>
		TINDEX Width;
		/// <summary>
		/// The height of the image
		/// </summary>
		TINDEX Height;

		/// <summary>
		/// Constructs an unpopulated image
		/// </summary>
		Image()
		{
			createPixelArray(0, 0);
		}

		/// <summary>
		/// Constructs an image and copies existing image into it
		/// </summary>
		Image(const Image<TVALUE, TINDEX>& image)
		{
			Pixels = 0;
			Width = 0;
			Height = 0;
			operator=(image); //use a swap function instead?
		}

		/// <summary>
		/// Constructs an unpopulated image
		/// </summary>
		Image(TINDEX width, TINDEX height)
		{
			createPixelArray(width, height);
		}

		/// <summary>
		/// Constructs a image and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		Image(TINDEX width, TINDEX height, const TVALUE pixel)
			: Image(width, height)
		{
			for (TINDEX x = 0; x < width; x++)
				for (TINDEX y = 0; y < height; y++)
					Pixels[x][y] = pixel;
		}

		/// <summary>
		/// Constructs a image and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		Image(TINDEX width, TINDEX height, const TVALUE** pixels)
			: Image(width, height)
		{
			for (TINDEX x = 0; x < width; x++)
				for (TINDEX y = 0; y < height; y++)
					Pixels[x][y] = pixels[x][y];
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		TINDEX getWidth() const
		{
			return Width;
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		TINDEX getHeight() const
		{
			return Height;
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		bool validateX(const TINDEX x) const
		{
			return (x <= Width) && (x >= 0);
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		bool validateY(const TINDEX y) const
		{
			return (y <= Height) && (y >= 0);
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		static TVALUE getMinValue()
		{
			return Common::getLowerBound<TVALUE>();
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		static TVALUE getMaxValue()
		{
			return getUpperBound<TVALUE>();
		}

		/// <summary>
		/// Clone
		/// </summary>
		Image<TVALUE, TINDEX>& operator=(const Image<TVALUE, TINDEX>& image)  //use a swap function instead?
		{
			if (this != &image)
			{
				TINDEX newWidth = image.Width;
				TINDEX newHeight = image.Height;
				TVALUE** pixelsBuffer = new TVALUE*[newWidth];

				for (TINDEX x = 0; x < newWidth; x++)
				{
					pixelsBuffer[x] = new TVALUE[newHeight];

					for (TINDEX y = 0; y < newHeight; y++)
						pixelsBuffer[x][y] = image.Pixels[x][y];
				}

				replacePixelArray(newWidth, newHeight, pixelsBuffer);
			}

			return *this;
		}

		// ************************************************************************************ // LINE OF HAPPINESS

		/// <summary>
		/// Increase contrast
		/// </summary>
		Image<TVALUE, TINDEX> operator*(const TVALUE value) const
		{
			return Image<TVALUE, TINDEX>(*this) *= value;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		Image<TVALUE, TINDEX>& operator*=(const TVALUE value)
		{
			TVALUE** valuesBuffer = new TVALUE*[Width];

			TVALUE upperBound = getUpperBound<TVALUE>();
			TVALUE overflowCheck = upperBound / value;

			for (TINDEX x = 0; x < Width; x++)
			{
				valuesBuffer[x] = new TVALUE[Height];

				for (TINDEX y = 0; y < Height; y++)
					valuesBuffer[x][y] = (Pixels[x][y] > overflowCheck ? upperBound : Pixels[x][y] * value);
			}

			replacePixelArray(Width, Height, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		Image<TVALUE, TINDEX> operator/(const TVALUE value) const
		{
			return Image<TVALUE, TINDEX>(*this) /= value;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		Image<TVALUE, TINDEX>& operator/=(const TVALUE value)
		{
			TVALUE** valuesBuffer = new TVALUE*[Width];

			for (TINDEX x = 0; x < Width; x++)
			{
				valuesBuffer[x] = new TVALUE[Height];

				for (TINDEX y = 0; y < Height; y++)
					valuesBuffer[x][y] = Pixels[x][y] / value;
			}

			replacePixelArray(Width, Height, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX> operator>>(const TVALUE value) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Pixels[x][y] < value)
						i.Pixels[x][y] = value;
					else
						i.Pixels[x][y] = Pixels[x][y];

			return i
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX> operator<<(const TVALUE value)
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Pixels[x][y] > value)
						i.Pixels[x][y] = value;
					else
						i.Pixels[x][y] = Pixels[x][y];

			return i
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		Image<TVALUE, TINDEX> operator|(const Image<TVALUE, TINDEX>& image) const
		{
			return Image<TVALUE, TINDEX>(*this) |= image;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		Image<TVALUE, TINDEX>& operator|=(const Image<TVALUE, TINDEX>& image)
		{
			TVALUE** valuesBuffer = new TVALUE*[Width];

			for (TINDEX x = 0; x < Width; x++)
			{
				valuesBuffer[x] = new TVALUE[Height];

				for (TINDEX y = 0; y < Height; y++)
					valuesBuffer[x][y] = Pixels[x][y] | image.Pixels[x][y];
			}

			replacePixelArray(Width, Height, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		Image<TVALUE, TINDEX> operator&(const Image<TVALUE, TINDEX>& image) const
		{
			return Image<TVALUE, TINDEX>(*this) &= image;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		Image<TVALUE, TINDEX>& operator&=(const Image<TVALUE, TINDEX>& image)
		{
			TVALUE** valuesBuffer = new TVALUE*[Width];

			for (TINDEX x = 0; x < Width; x++)
			{
				valuesBuffer[x] = new TVALUE[Height];

				for (TINDEX y = 0; y < Height; y++)
					valuesBuffer[x][y] = Pixels[x][y] & image.Pixels[x][y];
			}

			replacePixelArray(Width, Height, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Invert
		/// </summary>
		Image<TVALUE, TINDEX> operator!() const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(*this);

			TVALUE upperBound = getUpperBound<TVALUE>();

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					i.Pixels[x][y] = upperBound - Pixels[x][y];

			return i;
		}

		/// <summary>
		/// Comparison
		/// </summary>
		bool operator==(const Image<TVALUE, TINDEX>& image) const
		{
			if ((Width != image.Width) || (Height != image.Height))
				return false;

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Pixels[x][y] != image.Pixels[x][y])
						return false;

			return true;
		}

		/// <summary>
		/// Not comparison
		/// </summary>
		bool operator!=(const Image<TVALUE, TINDEX>& image) const
		{
			return !operator==(image);
		}

		/// <summary>
		/// Greater than
		/// </summary>
		bool operator>(const TVALUE value) const
		{
			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Pixels[x][y] > values)
						return true;

			return false;
		}

		/// <summary>
		/// Less than
		/// </summary>
		bool operator<(const TVALUE value) const
		{
			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Pixels[x][y] < values)
						return true;

			return false;
		}

		/// <summary>
		/// Clones the image
		/// </summary>
		Image<TVALUE, TINDEX>& clone(const Image<TVALUE, TINDEX>& image)
		{
			return operator=(image);
		}

		static Image<TVALUE, TINDEX> getCroppedImage(const Image<TVALUE, TINDEX>& image, const TINDEX x1, const TINDEX y1, const TINDEX x2, const TINDEX y2)
		{
			Image<TVALUE, TINDEX> i;

			i.cropImage();

			return i;
		}

		/// <summary>
		/// Crops the image
		/// </summary>
		Image<TVALUE, TINDEX>& cropImage(const TINDEX x1, const TINDEX y1, const TINDEX x2, const TINDEX y2)
		{
			TVALUE** valuesBuffer;
			TINDEX newWidth = x2 - x1 + 1;
			TINDEX newHeight = y2 - y1 + 1;

			valuesBuffer = new TVALUE*[newWidth];

			for (TINDEX x = 0; x < newWidth; x++)
			{
				valuesBuffer[x] = new TVALUE[newHeight];

				for (TINDEX y = 0; y < newHeight; y++)
					valuesBuffer[x][y] = Pixels[x1 + x][y1 + y];
			}

			replacePixelArray(newWidth, newHeight, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<bool, TINDEX> getIsAboveThreshold(const TVALUE value) const
		{
			Image<bool, TINDEX> i = Image<bool, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					i.Pixels[x][y] = (Pixels[x][y] >= value);

			return i;
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<bool, TINDEX> getIsBelowThreshold(const TVALUE value) const
		{
			Image<bool, TINDEX> i = Image<bool, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					i.Pixels[x][y] = (Pixels[x][y] <= value);

			return i;
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX>& trimAboveThreshold(const TVALUE value) const
		{
			return operator>>(value);
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX>& trimBelowThreshold(const TVALUE value) const
		{
			return operator<<(value);
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX>& trimBetweenThresholds(const TVALUE lower, const TVALUE upper)
		{
			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Pixels[x][y] < lower) // use max function?
						Value[x][y] = lower;
					else if (Pixels[x][y] > upper) // use max function?
						Value[x][y] = upper;

			return *this;
		}

		/// <summary>
		/// Rotates the image 90 degrees clockwise
		/// </summary>
		Image<TVALUE, TINDEX>& rotate90()
		{
			TVALUE** valuesBuffer = new TVALUE*[Height];

			for (TINDEX y = 0; y < Height; y++)
			{
				valuesBuffer[y] = new TVALUE[Width];

				for (TINDEX x = 0; x < Width; x++)
					valuesBuffer[y][x] = Pixels[x][Height - y - 1];
			}

			replacePixelArray(Height, Width, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Rotates the image 180 degrees
		/// </summary>
		Image<TVALUE, TINDEX>& rotate180()
		{
			TVALUE** valuesBuffer = new TVALUE*[Width];

			for (TINDEX x = 0; x < Width; x++)
			{
				valuesBuffer[x] = new TVALUE[Height];

				for (TINDEX y = 0; y < Height; y++)
					valuesBuffer[x][y] = Pixels[Width - x - 1][Height - y - 1];
			}

			replacePixelArray(Width, Height, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Rotates the image 90 degrees anticlockwise
		/// </summary>
		Image<TVALUE, TINDEX>& rotate270()
		{
			TVALUE** valuesBuffer = new TVALUE*[Height];

			for (TINDEX y = 0; y < Height; y++)
			{
				valuesBuffer[y] = new TVALUE[Width];

				for (TINDEX x = 0; x < Width; x++)
					valuesBuffer[y][x] = Pixels[Width - x - 1][y];
			}

			replacePixelArray(Height, Width, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Horizontally flips the image
		/// </summary>
		Image<TVALUE, TINDEX>& flipHorizontally()
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX> = *this;

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					Pixels[x][y] = i.Pixels[Width - x - 1][y];

			return *this;
		}

		/// <summary>
		/// Vertically flips the image
		/// </summary>
		Image<TVALUE, TINDEX>& flipVertically()
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX> = *this;

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					Pixels[x][y] = i.Pixels[x][Height - y - 1];

			return *this;
		}

		/// <summary>
		/// Inverts the image
		/// </summary>
		Image<TVALUE, TINDEX>& invert(const Image<TVALUE, TINDEX>& image)
		{
			return operator=(!image.operator!());
		}

		/// <summary>
		/// Inverts the image
		/// </summary>
		Image<TVALUE, TINDEX>& invert()
		{
			return operator=(operator!());
		}

		/// <summary>
		/// Gets the inverted image
		/// </summary>
		Image<TVALUE, TINDEX> getInverted()
		{
			return operator!();
		}

		/// <summary>
		/// Apply 3x3 convolution matrix to image with cropped edges
		/// </summary>
		Image<TVALUE, TINDEX> getMatrixImageCrop(const Matrix3<TVALUE> matrix) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(Width - 2, Height - 2);

			for (TINDEX x = 0; x < Width - 2; x++)
				for (TINDEX y = 0; y < Height - 2; y++)
				{
					TINDEX x2 = x + 1;
					TINDEX x3 = x + 2;
					TINDEX y2 = y + 1;
					TINDEX y3 = y + 2;

					i.Pixels[x][y] = (Pixels[x][y] * matrix.Pixels[0][0])
										+ (Pixels[x2][y] * matrix.Pixels[1][0])
										+ (Pixels[x3][y] * matrix.Pixels[2][0])
										+ (Pixels[x][y2] * matrix.Pixels[0][1])
										+ (Pixels[x2][y2] * matrix.Pixels[1][1])
										+ (Pixels[x3][y2] * matrix.Pixels[2][1])
										+ (Pixels[x][y3] * matrix.Pixels[0][2])
										+ (Pixels[x2][y3] * matrix.Pixels[1][2])
										+ (Pixels[x3][y3] * matrix.Pixels[2][2]);
				}

			return i;
		}

		/// <summary>
		/// Apply 3x3 convolution matrix to image with wrapped edges
		/// </summary>
		Image<TVALUE, TINDEX> getMatrixImageWrap(const Matrix3<TVALUE> matrix) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
				{
					TINDEX xBefore = (x - 1) % width;
					TINDEX xAfter = (x + 1) % width;
					TINDEX yBefore = (y - 1) % height;
					TINDEX yAfter = (y + 1) % height;

					i.Pixels[x][y] = (Pixels[xBefore][yBefore] * matrix.Pixels[0][0])
										+ (Pixels[x][yBefore] * matrix.Pixels[1][0])
										+ (Pixels[xAfter][yBefore] * matrix.Pixels[2][0])
										+ (Pixels[xBefore][y] * matrix.Pixels[0][1])
										+ (Pixels[x][y] * matrix.Pixels[1][1])
										+ (Pixels[xAfter][y] * matrix.Pixels[2][1])
										+ (Pixels[xBefore][yAfter] * matrix.Pixels[0][2])
										+ (Pixels[x][yAfter] * matrix.Pixels[1][2])
										+ (Pixels[xAfter][yAfter] * matrix.Pixels[2][2]);
				}

			return i;
		}

		/// <summary>
		/// Apply 3x3 convolution matrix to image with extended edges
		/// </summary>
		Image<TVALUE, TINDEX> getMatrixImageExtend(const Matrix3<TVALUE> matrix) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
				{
					TINDEX xBefore = (x == 0 ? Width - 1 : x);
					TINDEX xAfter = (x == (Width - 1) ? 0 : x);
					TINDEX yBefore = (y == 0 ? Height - 1 : y);
					TINDEX yAfter = (y == (Height - 1) ? 0 : y);

					i.Pixels[x][y] = (Pixels[xBefore][yBefore] * matrix.Pixels[0][0])
										+ (Pixels[x][yBefore] * matrix.Pixels[1][0])
										+ (Pixels[xAfter][yBefore] * matrix.Pixels[2][0])
										+ (Pixels[xBefore][y] * matrix.Pixels[0][1])
										+ (Pixels[x][y] * matrix.Pixels[1][1])
										+ (Pixels[xAfter][y] * matrix.Pixels[2][1])
										+ (Pixels[xBefore][yAfter] * matrix.Pixels[0][2])
										+ (Pixels[x][yAfter] * matrix.Pixels[1][2])
										+ (Pixels[xAfter][yAfter] * matrix.Pixels[2][2]);
				}

			return i;
		}

		template <typename TVALUENEW, typename TCONVERTER>
		Common::Image<TVALUENEW, TINDEX> getImage(TCONVERTER* converter)
		{
			Common::Image<TVALUENEW, TINDEX> i = Common::Image<TVALUENEW, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					i.Pixels[x][y] = converter->convertPixel(Pixels[x][y]);

			return i;
		}

		template <typename TCONVERTER>
		Common::Image<TVALUE, TINDEX> convImage(TCONVERTER* converter)
		{
			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					Pixels[x][y] = converter->convertPixel(Pixels[x][y]);

			return i;
		}

	private:
		void createPixelArray(TINDEX width, TINDEX height)
		{
			TVALUE** values = new TVALUE*[width];

			for (TINDEX i = 0; i < width; i++)
				values[i] = new TVALUE[height];

			setPixelArray(width, height, values);
		}

		void setPixelArray(TINDEX width, TINDEX height, TVALUE** values)
		{
			Width = width;
			Height = height;
			Pixels = values;
		}

		void deletePixelArray()
		{
			for (TINDEX x = 0; x < Width; x++)
				delete[] Pixels[x];

			delete[] Pixels;
		}

		void recreatePixelArray(TINDEX width, TINDEX height)
		{
			deletePixelArray();
			createPixelArray(width, height);
		}

		void replacePixelArray(TINDEX width, TINDEX height, TVALUE** values)
		{
			deletePixelArray();
			setPixelArray(width, height, values);
		}

	public:
		~Image()
		{
			deletePixelArray();
		}

	};
}

#endif // COMMONIMAGE_H
