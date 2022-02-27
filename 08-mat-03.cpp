#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* Mat클래스 사용법

1. 대입 연산자.

2. Mat::at()으로 1채널 Mat 행렬 요소 접근.

3. 벡터 기반이므로 포인터 접근도 가능하다. -> ptr<>으로 접근.

*/


int main()
{
	// 1.
	Mat mat1(3, 3, CV_8U, 1); // 3, 3행렬 1로 초기화
	Mat mat2 = mat1; // 복사 생성자.
	Mat mat3 = mat1 + mat2;

	cout << mat3 << endl;

	mat3 = 255; // 모든 요소 255로 바꾸기.

	cout << mat3 << endl;

	// 2.
	Mat mat4(3, 3, CV_32F, Scalar_<float>(0));
	mat4.at<float>(1, 1) = 1; // (1, 1)에 접근.
	mat4.at<float>(Point(1, 2)) = 4;
	cout << "mat4 : " << endl
		<< mat4 << endl;


	Mat mat(Size(3, 3), CV_8U, Scalar(0));
	mat.at<uchar>(1, 1) = 4;
	cout << "(1, 1) : " << static_cast<double>(mat.at<uchar>(1, 1)) << endl; // 특정 요소 프린트.

	
	// 3.
	Mat mat5(3, 3, CV_64FC3, Scalar(0));
	mat5.at<Vec<double, 3>>(2, 2) = Vec3d(0, 3, 0);
	cout << "mat5 : " << endl
		<< mat5 << endl;

}