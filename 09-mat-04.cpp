#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* Mat�� Range, Rect
1. ���� Mat ��ü�� subset�� ������ �� ���δ�.
*/

int main()
{
	Mat mat(Size(3, 3), CV_8U, Scalar(0));
	mat.at<uchar>(1, 1) = 4;
	cout << "(1, 1) : " << static_cast<double>(mat.at<uchar>(1, 1))<< endl;
}