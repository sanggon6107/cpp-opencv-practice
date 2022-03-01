#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/* ������ ���� �̹� �ִ� �Լ��� ������, Ŀ���� Ŀ������ ���� �ִ�.

1. filter2D �Լ��� ���� ������� �Լ��� �ƴ϶�, �ڽ��� ���ϴ� Ŀ���� ������� ���� ��ų �� �ִ�.



*/

int main()
{
	Mat img = imread("lenna.png", IMREAD_GRAYSCALE);
	imshow("lenna", img);
	int ksize = 11;

	Mat kx = getGaussianKernel(ksize, 0.0);
	Mat ky = getGaussianKernel(ksize, 0.0);
	Mat kxy = kx * ky.t(); // y Ʈ��������� x�� ���ϸ�, 2������ ����þ� Ŀ�� �ϼ�.

	Mat dst_img;
	
	filter2D(img, dst_img, -1, kxy);
	
	imshow("filter", dst_img);
	waitKey();
	destroyAllWindows();
}