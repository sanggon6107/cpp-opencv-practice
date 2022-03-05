#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* color conversion

1.

void cvtColor( InputArray src, OutputArray dst, int code, int dstCn = 0 );

2. 컬러 코드는 enum으로 정의되어 있다.

ex)
    COLOR_BayerBG2RGB = COLOR_BayerRG2BGR, //!< equivalent to RGGB Bayer pattern
    COLOR_BayerGB2RGB = COLOR_BayerGR2BGR, //!< equivalent to GRBG Bayer pattern
    COLOR_BayerRG2RGB = COLOR_BayerBG2BGR, //!< equivalent to BGGR Bayer pattern

3. RGB <-> GRAY

RGB[A] to gray : Y <- 0.209 * R + 0.587 * G + 0.114 * B

Gray to RGB[A] : R <- Y, G <- Y, B <- Y, A <- max(ChannelRange)


4. 주의

convertTo와 cvtColor는 다르다.

convertTo는 이미지 형식을 바꾸는 것이지, Color구성을 다르게 하는 것이 아니다.

*/



int main()
{
    Mat img = imread("lenna.png");
    
    Mat gray;
    
    cvtColor(img, gray, COLOR_RGB2GRAY);

    imshow("gray", gray);
    
    waitKey(0);
    destroyAllWindows();
}