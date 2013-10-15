/*
* Simd Library.
*
* Copyright (c) 2011-2013 Yermalayeu Ihar.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy 
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
* copies of the Software, and to permit persons to whom the Software is 
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in 
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#ifndef __SimdBase_h__
#define __SimdBase_h__

#include "Simd/SimdLib.h"
#include "Simd/SimdTypes.h"

namespace Simd
{
	namespace Base
	{
		void AbsDifferenceSum(const uchar *a, size_t aStride, const uchar *b, size_t bStride, 
			size_t width, size_t height, uint64_t * sum);

		void AbsDifferenceSum(const uchar *a, size_t aStride, const uchar *b, size_t bStride, 
			const uchar *mask, size_t maskStride, uchar index, size_t width, size_t height, uint64_t * sum);

        void AbsGradientSaturatedSum(const uchar * src, size_t srcStride, size_t width, size_t height, uchar * dst, size_t dstStride);

        void AddFeatureDifference(const uchar * value, size_t valueStride, size_t width, size_t height, 
            const uchar * lo, size_t loStride, const uchar * hi, size_t hiStride,
            ushort weight, uchar * difference, size_t differenceStride);

        void AlphaBlending(const uchar *src, size_t srcStride, size_t width, size_t height, size_t channelCount, 
            const uchar *alpha, size_t alphaStride, uchar *dst, size_t dstStride);

        void BackgroundGrowRangeSlow(const uchar * value, size_t valueStride, size_t width, size_t height,
            uchar * lo, size_t loStride, uchar * hi, size_t hiStride);

        void BackgroundGrowRangeFast(const uchar * value, size_t valueStride, size_t width, size_t height,
            uchar * lo, size_t loStride, uchar * hi, size_t hiStride);

        void BackgroundIncrementCount(const uchar * value, size_t valueStride, size_t width, size_t height,
            const uchar * loValue, size_t loValueStride, const uchar * hiValue, size_t hiValueStride,
            uchar * loCount, size_t loCountStride, uchar * hiCount, size_t hiCountStride);

        void BackgroundAdjustRange(uchar * loCount, size_t loCountStride, size_t width, size_t height, 
            uchar * loValue, size_t loValueStride, uchar * hiCount, size_t hiCountStride, 
            uchar * hiValue, size_t hiValueStride, uchar threshold);

        void BackgroundAdjustRange(uchar * loCount, size_t loCountStride, size_t width, size_t height, 
            uchar * loValue, size_t loValueStride, uchar * hiCount, size_t hiCountStride, 
            uchar * hiValue, size_t hiValueStride, uchar threshold, const uchar * mask, size_t maskStride);

        void BackgroundShiftRange(const uchar * value, size_t valueStride, size_t width, size_t height,
            uchar * lo, size_t loStride, uchar * hi, size_t hiStride);

        void BackgroundShiftRange(const uchar * value, size_t valueStride, size_t width, size_t height,
            uchar * lo, size_t loStride, uchar * hi, size_t hiStride, const uchar * mask, size_t maskStride);

        void BackgroundInitMask(const uchar * src, size_t srcStride, size_t width, size_t height,
            uchar index, uchar value, uchar * dst, size_t dstStride);

        void BgraToBgr(const uchar *bgra, size_t size, uchar *bgr, bool lastRow = true);

        void BgraToBgr(const uchar *bgra, size_t width, size_t height, size_t bgraStride, uchar *bgr, size_t bgrStride);

        void BgraToGray(const uchar *bgra, size_t width, size_t height, size_t bgraStride, uchar *gray, size_t grayStride);

        void BgrToBgra(const uchar *bgr, size_t size, uchar *bgra, bool fillAlpha = true, bool lastRow = true, uchar alpha = 0xFF);

        void BgrToBgra(const uchar *bgr, size_t width, size_t height, size_t bgrStride, uchar *bgra, size_t bgraStride, uchar alpha = 0xFF);

        void BgrToGray(const uchar *bgr, size_t width, size_t height, size_t bgrStride, uchar *gray, size_t grayStride);

        void Binarization(const uchar * src, size_t srcStride, size_t width, size_t height, 
            uchar value, uchar positive, uchar negative, uchar * dst, size_t dstStride, SimdCompareType compareType);

        void AveragingBinarization(const uchar * src, size_t srcStride, size_t width, size_t height,
            uchar value, size_t neighborhood, uchar threshold, uchar positive, uchar negative, 
            uchar * dst, size_t dstStride, SimdCompareType compareType);

        void Copy(const uchar * src, size_t srcStride, size_t width, size_t height, size_t pixelSize, uchar * dst, size_t dstStride);

        void CopyFrame(const uchar * src, size_t srcStride, size_t width, size_t height, size_t pixelSize, 
            size_t frameLeft, size_t frameTop, size_t frameRight, size_t frameBottom, uchar * dst, size_t dstStride);

        uint32_t Crc32(const void * src, size_t size);

        void DeinterleaveUv(const uchar * uv, size_t uvStride, size_t width, size_t height, uchar * u, size_t uStride, uchar * v, size_t vStride);

        void EdgeBackgroundGrowRangeSlow(const uchar * value, size_t valueStride, size_t width, size_t height,
            uchar * background, size_t backgroundStride);

        void EdgeBackgroundGrowRangeFast(const uchar * value, size_t valueStride, size_t width, size_t height,
            uchar * background, size_t backgroundStride);

        void EdgeBackgroundIncrementCount(const uchar * value, size_t valueStride, size_t width, size_t height,
            const uchar * backgroundValue, size_t backgroundValueStride, uchar * backgroundCount, size_t backgroundCountStride);

        void EdgeBackgroundAdjustRange(uchar * backgroundCount, size_t backgroundCountStride, size_t width, size_t height, 
            uchar * backgroundValue, size_t backgroundValueStride, uchar threshold);

        void EdgeBackgroundAdjustRange(uchar * backgroundCount, size_t backgroundCountStride, size_t width, size_t height, 
            uchar * backgroundValue, size_t backgroundValueStride, uchar threshold, const uchar * mask, size_t maskStride);

        void EdgeBackgroundShiftRange(const uchar * value, size_t valueStride, size_t width, size_t height,
            uchar * background, size_t backgroundStride);

        void EdgeBackgroundShiftRange(const uchar * value, size_t valueStride, size_t width, size_t height,
            uchar * background, size_t backgroundStride, const uchar * mask, size_t maskStride);

        void Fill(uchar * dst, size_t stride, size_t width, size_t height, size_t pixelSize, uchar value);

        void FillFrame(uchar * dst, size_t stride, size_t width, size_t height, size_t pixelSize, 
            size_t frameLeft, size_t frameTop, size_t frameRight, size_t frameBottom, uchar value);

        void FillBgra(uchar * dst, size_t stride, size_t width, size_t height, uchar blue, uchar green, uchar red, uchar alpha = 0xFF);

        void GaussianBlur3x3(const uchar * src, size_t srcStride, size_t width, size_t height, 
            size_t channelCount, uchar * dst, size_t dstStride);

        void GrayToBgra(const uchar *gray, size_t width, size_t height, size_t grayStride, uchar *bgra, size_t bgraStride, uchar alpha = 0xFF);

        void AbsSecondDerivativeHistogram(const uchar *src, size_t width, size_t height, size_t stride,
            size_t step, size_t indent, uint * histogram);

        void Histogram(const uchar *src, size_t width, size_t height, size_t stride, uint * histogram);

        void InterleaveBgra(uchar *bgra, size_t size, const int *blue, int bluePrecision, bool blueSigned, 
            const int *green, int greenPrecision, bool greenSigned, const int *red, int redPrecision, bool redSigned, uchar alpha = 0xFF);

        void InterleaveBgra(uchar *bgra, size_t size, const int *gray, int grayPrecision, bool graySigned, uchar alpha = 0xFF);

        void LbpEstimate(const uchar * src, size_t srcStride, size_t width, size_t height, uchar * dst, size_t dstStride);

        void MedianFilterSquare3x3(const uchar * src, size_t srcStride, size_t width, size_t height, 
            size_t channelCount, uchar * dst, size_t dstStride);

        void MedianFilterSquare5x5(const uchar * src, size_t srcStride, size_t width, size_t height, 
            size_t channelCount, uchar * dst, size_t dstStride);
    }
}
#endif//__SimdBase_h__