#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


/*

1. ������ �Ʒ��� ����.
double threshold(inputArray src, OutputArray dst, double thresh, double maxval, int type);

2. type�� �������� BINARY(������Ȧ�� �������� ����ȭ), BINARY_INV, TRUNC(������Ȧ�� ������ ��� 0), TOZERO ���� �ִ�.

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