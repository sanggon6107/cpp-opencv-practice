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

	cout << "mat[0:1, 0:3] : " << endl
		<< mat(Range(0, 1), Range(0, 3)) << endl;

	cout << "mat[all, 0:2] : " << endl
		<< mat(Range::all(), Range(0, 2)) << endl;

	cout << "mat[0:2, 0:1] : " << endl
		<< mat(Rect(0, 0, 1, 2)) << endl;
}