#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* Vec Ŭ����
1. ���ø� ���ڷ� Ÿ��, ����(rank)�� �޴´�.
2. �ٸ� Ŭ������ ���������� �پ��� ���ø� ���ڿ� ���� typedef �����Ѵ�.

typedef Vec<uchar, 2> Vec2b;
typedef Vec<uchar, 3> Vec3b;
typedef Vec<uchar, 4> Vec4b;

typedef Vec<short, 2> Vec2s;
typedef Vec<short, 3> Vec3s;
typedef Vec<short, 4> Vec4s;

typedef Vec<ushort, 2> Vec2w;
typedef Vec<ushort, 3> Vec3w;
typedef Vec<ushort, 4> Vec4w;

typedef Vec<int, 2> Vec2i;
typedef Vec<int, 3> Vec3i;
typedef Vec<int, 4> Vec4i;
typedef Vec<int, 6> Vec6i;
typedef Vec<int, 8> Vec8i;

typedef Vec<float, 2> Vec2f;
typedef Vec<float, 3> Vec3f;
typedef Vec<float, 4> Vec4f;
typedef Vec<float, 6> Vec6f;

typedef Vec<double, 2> Vec2d;
typedef Vec<double, 3> Vec3d;
typedef Vec<double, 4> Vec4d;
typedef Vec<double, 6> Vec6d;


3. �ٸ� Ŭ������� ���������� �پ��� ������ �����Ѵ�.

*/

/* Scalar_ Ŭ���� : 4-element vecotr

1. The type Scalar is widely used in OpenCV to pass pixel values.


*/



int main()
{
	// Vec Ŭ����.
	// 1.
	Vec<int, 3> vector1(1, 2, 3);
	
	// 2.
	Vec3b rgb(2, 5, 10); // Vec<uchar, 3>

	//3.
	Vec3b rgb2(11, 5, 11);
	Vec3b rgb_mul = rgb.mul(rgb2); // �� ��Ҹ� ���Ѵ�.
	Vec3b rgb_ae = rgb * 5; // ��� ��ҿ� 5 ���Ѵ�.

	cout << "rgb : " << rgb << endl
		<< "sum : " << sum(rgb) << endl;

	Vec3b vec_all = Vec3b::all(0);

	
}