#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


/* adaptive threshold

1. 원형은 아래와 같다.
void adaptiveThreshold(InputArray src, OutputArray dst, double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double C);

adaptiveMethod : ADAPTIVE_THRESH_MEAN_C, ADAPTIVE_THESH_GAUSSIAN_C.
			   : 쓰레시홀드의 값을 어떻게 정할 것인가? mean인가 gaussian인가?

thresholdType : adaptive threshod에서는 BINARY와 BINARY_INV만 지원한다.

2. C에는 보통 0, 3, 5가 들어간다. 클 수록 GAUSSIAN, MEAN에서 많이 뺀다. constant offset이 커지는 것.

*/


int main()
{
	Mat img = imread("sky.jpg", IMREAD_GRAYSCALE);
	
	Mat dst_img;
	adaptiveThreshold(img, dst_img, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 21, 5); // 평균값에서 5 뺌.

	Mat dst_img2;
	adaptiveThreshold(img, dst_img2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 21, 5);

	imshow("dst_img", dst_img);
	imshow("dst_img2", dst_img2);


	waitKey(0);
	destroyAllWindows();
}