#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* MatŬ���� ����

1. ���� ������.

2. Mat::at()���� 1ä�� Mat ��� ��� ����.

3. ���� ����̹Ƿ� ������ ���ٵ� �����ϴ�. -> ptr<>���� ����.

*/


int main()
{
	// 1.
	Mat mat1(3, 3, CV_8U, 1); // 3, 3��� 1�� �ʱ�ȭ
	Mat mat2 = mat1; // ���� ������.
	Mat mat3 = mat1 + mat2;

	cout << mat3 << endl;

	mat3 = 255; // ��� ��� 255�� �ٲٱ�.

	cout << mat3 << endl;

	// 2.
	Mat mat4(3, 3, CV_32F, Scalar_<float>(0));
	mat4.at<float>(1, 1) = 1; // (1, 1)�� ����.
	mat4.at<float>(Point(1, 2)) = 4;
	cout << "mat4 : " << endl
		<< mat4 << endl;


	Mat mat(Size(3, 3), CV_8U, Scalar(0));
	mat.at<uchar>(1, 1) = 4;
	cout << "(1, 1) : " << static_cast<double>(mat.at<uchar>(1, 1)) << endl; // Ư�� ��� ����Ʈ.

	
	// 3.
	Mat mat5(3, 3, CV_64FC3, Scalar(0));
	mat5.at<Vec<double, 3>>(2, 2) = Vec3d(0, 3, 0);
	cout << "mat5 : " << endl
		<< mat5 << endl;

}