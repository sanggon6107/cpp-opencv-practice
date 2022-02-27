#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* Mat 클래스 사용법

1. Mat 생성 및 초기화
템플릿 인자로 <사이즈, 요소의 타입, 초기화값> 을 받는다.

2. Mat 행렬 정보

*/


int main()
{
	// 1.
	Mat a(2, 3, CV_8UC3);
	Mat b(2, 3, CV_8UC3, Scalar(0)); // 복습 : Scalar 는 Scalar_<double>의 typedef이다.
	cout << "b : " << endl
		<< b << endl;

	Mat a_1 = a; // 주의 : 복사본이 아니라 참조로 받는다.

	Mat b_1(Size(3, 2), CV_8UC3, Scalar(1, 2, 3));
	cout << "b_1 :" << endl
		<< b_1 << endl;

	Vec3b vec1(1, 2, 3);
	Mat c(vec1); // 변환 생성.
	
	Mat d(b, Range(0, 1), Range::all()); // Mat 객체 b의 일부만 가져오겠다. // Range(a, b) : [a, b)?
	cout << "d : " << endl
		<< d << endl;


	// 2.
	cout << a.rows << endl; // 행
	cout << a.cols << endl; // 열
	cout << a.dims << endl; // dimensionity.

	auto sz = b_1.size();
	cout << "b_1.size() : " << sz << endl;

	cout << "b.data : " << static_cast<void*>(b.data) << endl;
	cout << "b.total() : " << b.total() << endl;
	cout << "b.channels() : " << b.channels() << endl;

}