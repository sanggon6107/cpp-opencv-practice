#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* Mat Ŭ���� ����

1. Mat ���� �� �ʱ�ȭ
���ø� ���ڷ� <������, ����� Ÿ��, �ʱ�ȭ��> �� �޴´�.

2. Mat ��� ����

*/


int main()
{
	// 1.
	Mat a(2, 3, CV_8UC3);
	Mat b(2, 3, CV_8UC3, Scalar(0)); // ���� : Scalar �� Scalar_<double>�� typedef�̴�.
	cout << "b : " << endl
		<< b << endl;

	Mat a_1 = a; // ���� : ���纻�� �ƴ϶� ������ �޴´�.

	Mat b_1(Size(3, 2), CV_8UC3, Scalar(1, 2, 3));
	cout << "b_1 :" << endl
		<< b_1 << endl;

	Vec3b vec1(1, 2, 3);
	Mat c(vec1); // ��ȯ ����.
	
	Mat d(b, Range(0, 1), Range::all()); // Mat ��ü b�� �Ϻθ� �������ڴ�. // Range(a, b) : [a, b)?
	cout << "d : " << endl
		<< d << endl;


	// 2.
	cout << a.rows << endl; // ��
	cout << a.cols << endl; // ��
	cout << a.dims << endl; // dimensionity.

	auto sz = b_1.size();
	cout << "b_1.size() : " << sz << endl;

	cout << "b.data : " << static_cast<void*>(b.data) << endl;
	cout << "b.total() : " << b.total() << endl;
	cout << "b.channels() : " << b.channels() << endl;

}