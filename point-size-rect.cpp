#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* Point_ ��ü. �⺻ 2D ��ǥ ���ø� Ŭ����. x, y �ּҸ� ��� �����ͷ� ������.

1.
typedef Point_<int> Point2i;
typedef Point_<int64> Point2l;
typedef Point_<float> Point2f;
typedef Point_<double> Point2d;
typedef Point2i Point;


2. �⺻������ Point_<> Ŭ���������� �� ���ø� ���ں��� typedef �Ǿ��ִ�.

3. 3���� ��ǥ�� ��Ÿ����  Point3_<Type>�� �ִ�.

*/

/* Size_ Ŭ���� : ũ�⸦ ǥ���ϴ� ���ø� Ŭ����. (width, height)
1. +, << �� ���� �پ��� �����ڰ� �����ε� �Ǿ��ִ�.

2. area() ��� �Լ��� ���� ���� �� �ִ�.

3. �⺻�����δ� Size_<Type> �����̴�.

typedef Size_<int> Size2i;
typedef Size_<int64> Size2l;
typedef Size_<float> Size2f;
typedef Size_<double> Size2d;
typedef Size2i Size;

*/


/* Rect_ Ŭ����

1. 
typedef Rect_<int> Rect2i;
typedef Rect_<float> Rect2f;
typedef Rect_<double> Rect2d;
typedef Rect2i Rect;

2. �������� ���ڷ� x, y, width, height�� ������.

3. �پ��� ������ �����ε��� ��� �Լ��� �����Ѵ�.(contain, tl(), br() ��.)

*/


int main()
{
	Point_<int> pt1(100, 100);
	Point2i pt2(20, 20);
	
	Point pt3 = pt1 + pt2;
	
	cout << "pt3 : " << pt3.x << ", " << pt3.y << endl;

	Point3_<int> point_3d(1, 2, 3);

	Rect rect(0, 0, 200, 200); // x, y, width, height
	if (pt1.inside(rect)) { cout << "pt1 inside rect" << endl; }

	
	// Size_ Ŭ����

	Size_<int> size1(320, 240);
	Size size2(640, 480);
	Size size3 = size1 + size2;
	
	cout << "size1.area : " << size1.area() << endl; // ����
	cout << "width : " << size1.width << endl;
	cout << "height : " << size1.height << endl;

	
	// Rect_ Ŭ����
	Rect_<int> r1(100, 100, 320, 240);
	Rect r2(200, 200, 320, 240);
	
	Point pt1(120, 120);
	Size size(100, 100);

	Rect r3 = r2 + size;
	Rect r4 = r1 + pt1;

	Point top_left = r1.tl();
	Point bottom_right = r1.br();

	Rect rt5 = r1 & r2; // intersection
	Rect rt6 = r1 | r2; // minimum area rectagle containing r1 and r2.

	if (r1.contains(pt1)) { cout << "r1 contains pt1" << endl; }


	
}