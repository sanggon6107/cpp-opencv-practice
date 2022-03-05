#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* color conversion

1.

void cvtColor( InputArray src, OutputArray dst, int code, int dstCn = 0 );

2. �÷� �ڵ�� enum���� ���ǵǾ� �ִ�.

ex)
    COLOR_BayerBG2RGB = COLOR_BayerRG2BGR, //!< equivalent to RGGB Bayer pattern
    COLOR_BayerGB2RGB = COLOR_BayerGR2BGR, //!< equivalent to GRBG Bayer pattern
    COLOR_BayerRG2RGB = COLOR_BayerBG2BGR, //!< equivalent to BGGR Bayer pattern

3. RGB <-> GRAY

RGB[A] to gray : Y <- 0.209 * R + 0.587 * G + 0.114 * B

Gray to RGB[A] : R <- Y, G <- Y, B <- Y, A <- max(ChannelRange)


4. ����

convertTo�� cvtColor�� �ٸ���.

convertTo�� �̹��� ������ �ٲٴ� ������, Color������ �ٸ��� �ϴ� ���� �ƴϴ�.

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