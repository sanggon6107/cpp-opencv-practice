#define _USE_MATH_DEFINES
#include <math.h>
#include <opencv2/opencv.hpp>
using namespace cv;

/* remap
1. 앞서 배웠던 변환보다 더욱 광범위한 개념. 모든 픽셀의 변환 자체를 직접 지정할 수 있다.


2. 
void remap( InputArray src, OutputArray dst,
						 InputArray map1, InputArray map2,
						 int interpolation, int borderMode = BORDER_CONSTANT,
						 const Scalar& borderValue = Scalar());

map1 : x방향 변환 행렬.
map2 : y방향 변환 행렬.
*/


int main()
{
	Mat img = imread("lenna.png", IMREAD_GRAYSCALE);

	Mat map_dst_x, map_dst_y;
	map_dst_x.create(img.size(), CV_32FC1);
	map_dst_y.create(img.size(), CV_32FC1);

	for (int y = 0; y < img.rows; y++)
	{
		for (int x = 0; x < img.cols; x++)
		{
			float angle = static_cast<float>(y * 2.0f );
			float s = sin(angle * static_cast<float>(M_PI) / 180.0f) + 2.0f;
			float rx = static_cast<float>(x) * 1.1f - s * 10.0f;
			map_dst_x.at<float>(y, x) = rx;                     // x는 사인파로 일렁이듯이 바꾼다.
			map_dst_y.at<float>(y, x) = y; // y는 그대로.
		}
	}

	Mat dst_img;
	remap(img, dst_img, map_dst_x, map_dst_y, INTER_LINEAR);
	imshow("img", img);
	imshow("dst_img", dst_img);
	
	waitKey(0);
	destroyAllWindows();
}