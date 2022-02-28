#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*
(1, 1), (2, 2.33), (3, 2.88), (4, 4.0), (5, 5.2) ���� ���� ����.
y = ax + b�� �� 5�� �ְ� a, b ���Ѵ�.
*/

int main()
{
	double x[] = { 1,1, 2,1, 3,1, 4,1, 5,1 };
	double y[] = { 1, 2.33, 2.88, 4.0, 5.2 };
	Mat X(5, 2, CV_64F, x);
	Mat Y(5, 1, CV_64F, y);
	Mat fit = X.inv(DECOMP_SVD) * Y; // x���, ���. y = fit[0]*x + fit[1]

	cout << fit << endl;
}