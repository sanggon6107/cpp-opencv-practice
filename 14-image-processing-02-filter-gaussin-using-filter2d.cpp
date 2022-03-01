#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/* 기존의 블러는 이미 있는 함수를 썼지만, 커널을 커스텀할 수도 있다.

1. filter2D 함수를 쓰면 만들어진 함수가 아니라, 자신이 원하는 커널을 컨볼루션 연산 시킬 수 있다.



*/

int main()
{
	Mat img = imread("lenna.png", IMREAD_GRAYSCALE);
	imshow("lenna", img);
	int ksize = 11;

	Mat kx = getGaussianKernel(ksize, 0.0);
	Mat ky = getGaussianKernel(ksize, 0.0);
	Mat kxy = kx * ky.t(); // y 트랜스포즈와 x를 곱하면, 2차원의 가우시안 커널 완성.

	Mat dst_img;
	
	filter2D(img, dst_img, -1, kxy);
	
	imshow("filter", dst_img);
	waitKey();
	destroyAllWindows();
}