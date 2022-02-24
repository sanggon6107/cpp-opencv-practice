#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* Point_ 객체. 기본 2D 좌표 템플릿 클래스. x, y 주소를 멤버 데이터로 가진다.

1.
typedef Point_<int> Point2i;
typedef Point_<int64> Point2l;
typedef Point_<float> Point2f;
typedef Point_<double> Point2d;
typedef Point2i Point;


2. 기본적으로 Point_<> 클래스이지만 각 템플릿 인자별로 typedef 되어있다.

3. 3차원 좌표를 나타내는  Point3_<Type>도 있다.

*/

/* Size_ 클래스 : 크기를 표현하는 템플릿 클래스. (width, height)
1. +, << 와 같은 다양한 연산자가 오버로딩 되어있다.

2. area() 멤버 함수로 넓이 구할 수 있다.

3. 기본적으로는 Size_<Type> 형태이다.

typedef Size_<int> Size2i;
typedef Size_<int64> Size2l;
typedef Size_<float> Size2f;
typedef Size_<double> Size2d;
typedef Size2i Size;

*/


/* Rect_ 클래스

1. 
typedef Rect_<int> Rect2i;
typedef Rect_<float> Rect2f;
typedef Rect_<double> Rect2d;
typedef Rect2i Rect;

2. 생성자의 인자로 x, y, width, height를 가진다.

3. 다양한 연산자 오버로딩과 멤버 함수를 제공한다.(contain, tl(), br() 등.)

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

	
	// Size_ 클래스

	Size_<int> size1(320, 240);
	Size size2(640, 480);
	Size size3 = size1 + size2;
	
	cout << "size1.area : " << size1.area() << endl; // 넓이
	cout << "width : " << size1.width << endl;
	cout << "height : " << size1.height << endl;

	
	// Rect_ 클래스
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