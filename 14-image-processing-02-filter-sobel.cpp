#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;



int main()
{
	Mat img = imread("lenna.png", IMREAD_GRAYSCALE);
	imshow("lenna", img);

	Mat dst_x, dst_y, dst_xy;

	Sobel(img, dst_x, CV_32F, 1, 0, 3); // x방향 엣지 디텍션
	Sobel(img, dst_y, CV_32F, 0, 1, 3); // y방향 엣지 디텍션
	magnitude(dst_x, dst_y, dst_xy);    // 두 개 더한다.

	imshow("x", dst_x);
	imshow("y", dst_y);
	imshow("xy", dst_xy);

	waitKey(0);
	destroyAllWindows();
}