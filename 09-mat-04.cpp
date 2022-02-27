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
	mat.at<uchar>(1, 1) = 4;
	cout << "(1, 1) : " << static_cast<double>(mat.at<uchar>(1, 1))<< endl;
}