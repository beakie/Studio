#ifndef PICTURE_QT_IMAGEMAPPER_H
#define PICTURE_QT_IMAGEMAPPER_H

#include "picture.h"

#include <QImage>
#include <QPixmap>
#include <QRgb>

namespace Picture
{
	namespace Qt
	{
		template <typename TINDEX>
		Common::Image<UInt1, TINDEX> getUInt1Image(QImage qimage)
		{
			int width = qimage.width();
			TINDEX height = qimage.height();

			Common::Image<UInt1, TINDEX> image = Common::Image<UInt1, TINDEX>(width, height);

			for (TINDEX x = 0; x < width; x++)
				for (TINDEX y = 0; y < height; y++)
					image.Pixels[x][y] = qimage.pixel(x, y);

			return image;
		}

		template <typename TINDEX>
		Common::Image<Picture::Rgb8, TINDEX> getRgb8Image(QImage qimage)
		{
			int width = qimage.width();
			TINDEX height = qimage.height();

			Common::Image<Picture::Rgb8, TINDEX> image = Common::Image<Picture::Rgb8, TINDEX>(width, height);

			for (TINDEX x = 0; x < width; x++)
				for (TINDEX y = 0; y < height; y++)
				{
					QRgb pixel = qimage.pixel(x, y);
					image.Pixels[x][y] = Picture::Rgb8(qRed(pixel), qGreen(pixel), qBlue(pixel));
				}

			return image;
		}

		template <typename TINDEX>
		Common::Image<Picture::Argb8, TINDEX> getArgb8Image(QImage qimage)
		{
			int width = qimage.width();
			TINDEX height = qimage.height();

			Common::Image<Picture::Argb8, TINDEX> image = Common::Image<Picture::Argb8, TINDEX>(width, height);

			for (TINDEX x = 0; x < width; x++)
				for (TINDEX y = 0; y < height; y++)
				{
					QRgb pixel = qimage.pixel(x, y);
					image.Pixels[x][y] = Picture::Argb8(qAlpha(pixel), qRed(pixel), qGreen(pixel), qBlue(pixel));
				}

			return image;
		}

		template <typename TINDEX>
		QImage getQImage(Common::Image<UInt1, TINDEX> image)
		{
			QImage qimage = QImage(image.Width, image.Height, QImage::Format_Mono);

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					qimage.setPixel(x, y, image.Pixels[x][y].Values[0]);

			return qimage;
		}

		template <typename TINDEX>
		QImage getQImage(Common::Image<Picture::Rgb8, TINDEX> image)
		{
			QImage qimage = QImage(image.Width, image.Height, QImage::Format_RGB888);

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					qimage.setPixel(x, y, qRgb(image.Pixels[x][y].Values[0], image.Pixels[x][y].Values[1], image.Pixels[x][y].Values[2]));

			return qimage;
		}

		template <typename TINDEX>
		QImage getQImage(Common::Image<Picture::Argb8, TINDEX> image)
		{
			QImage qimage = QImage(image.Width, image.Height, QImage::Format_ARGB32);

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					qimage.setPixel(x, y, qArgb(image.Pixels[x][y].Values[0], image.Pixels[x][y].Values[1], image.Pixels[x][y].Values[2], image.Pixels[x][y].Values[3]));

			return qimage;
		}

		template <typename TINDEX>
		QPixmap getQPixmap(Common::Image<UInt1, TINDEX> image)
		{
			return QPixmap::fromImage(getQImage(image));
		}

		template <typename TINDEX>
		QPixmap getQPixmap(Common::Image<Picture::Rgb8, TINDEX> image)
		{
			return QPixmap::fromImage(getQImage(image));
		}

		template <typename TINDEX>
		QPixmap getQPixmap(Common::Image<Picture::Argb8, TINDEX> image)
		{
			return QPixmap::fromImage(getQImage(image));
		}

	}
}

#endif // PICTURE_QT_IMAGEMAPPER_H
