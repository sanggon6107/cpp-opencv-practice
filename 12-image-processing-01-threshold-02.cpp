#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


/* adaptive threshold

1. ������ �Ʒ��� ����.
void adaptiveThreshold(InputArray src, OutputArray dst, double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double C);

adaptiveMethod : ADAPTIVE_THRESH_MEAN_C, ADAPTIVE_THESH_GAUSSIAN_C.
			   : ������Ȧ���� ���� ��� ���� ���ΰ�? mean�ΰ� gaussian�ΰ�?

thresholdType : adaptive threshod������ BINARY�� BINARY_INV�� �����Ѵ�.

2. C���� ���� 0, 3, 5�� ����. Ŭ ���� GAUSSIAN, MEAN���� ���� ����. constant offset�� Ŀ���� ��.

*/


int main()
{
	Mat img = imread("sky.jpg", IMREAD_GRAYSCALE);
	
	Mat dst_img;
	adaptiveThreshold(img, dst_img, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 21, 5); // ��հ����� 5 ��.

	Mat dst_img2;
	adaptiveThreshold(img, dst_img2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 21, 5);

	imshow("dst_img", dst_img);
	imshow("dst_img2", dst_img2);


	waitKey(0);
	destroyAllWindows();
}