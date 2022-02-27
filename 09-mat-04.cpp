#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* Mat과 Range, Rect
1. 기존 Mat 객체의 subset을 가져올 때 쓰인다.
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