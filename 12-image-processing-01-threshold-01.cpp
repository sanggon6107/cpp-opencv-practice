#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


/*

1. 원형은 아래와 같다.
double threshold(inputArray src, OutputArray dst, double thresh, double maxval, int type);

2. type의 종류에는 BINARY(쓰레시홀드 기준으로 이진화), BINARY_INV, TRUNC(쓰레시홀드 밑으로 모두 0), TOZERO 등이 있다.

*/


int main()
{
	Mat img = imread("sky.jpg", IMREAD_GRAYSCALE);
	Mat dst_img;
	double th1 = threshold(img, dst_img, 100, 255, THRESH_BINARY);
	Mat dst_img2;
	double th2 = threshold(img, dst_img2, 100, 255, THRESH_BINARY + THRESH_OTSU);
	Mat dst_img3;
	double th3 = threshold(img, dst_img3, 100, 255, THRESH_BINARY_INV);

	imshow("img", img);
	imshow("dst_img", dst_img);
	imshow("dst_img2", dst_img2);
	imshow("dst_img3", dst_img3);

	waitKey(0);
	destroyAllWindows();
}