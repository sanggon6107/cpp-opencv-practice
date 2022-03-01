#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;



int main()
{
	Mat img = imread("lenna.png", IMREAD_GRAYSCALE);
	imshow("lenna", img);

	Mat low;
	GaussianBlur(img, low, Size(3, 3), 0.0);
	Mat high = img - low;
	Mat sharp = img + high * 5;

	Matx<int, 3, 3> fil(0, -1, 0,
						-1, 4, -1,
						0, -1, 0);   // ���� �ȼ� ����. ���� �����ϴ� ����. �ֺ��� ��� �ȼ��� ���̸� ���Ѵ�.

	Mat high2;
	filter2D(img, high2, -1, fil);
	Mat sharp2 = img + high2;

	imshow("high", high * 10);
	imshow("sharp", sharp);
	imshow("sharp2", sharp2);
	
	waitKey(0);
	destroyAllWindows();

}