#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* Matx 클래스 : 고정된 작은 크기의 행렬을 표현하는 템플릿.
* 
1. 작은 사이즈의 행렬이다. 큰 크기의 행렬인 Mat의 하위호환 개념.

2. Point_, Size_, Rect_처럼 여러 템플릿 인자에 대해 typedef 되어있다.


typedef Matx<float, 1, 2> Matx12f;
typedef Matx<double, 1, 2> Matx12d;
typedef Matx<float, 1, 3> Matx13f;
typedef Matx<double, 1, 3> Matx13d;
typedef Matx<float, 1, 4> Matx14f;
typedef Matx<double, 1, 4> Matx14d;
typedef Matx<float, 1, 6> Matx16f;
typedef Matx<double, 1, 6> Matx16d;
...



*/


int main()
{
	Matx<float, 2, 3> AA(1, 2, 3, 4, 5, 6); // 2 x 3의 float 행렬.
	Matx<float, 2, 3> Z(7, 8, 9, 10, 11, 12);
	Matx12f B(1.0f, 2.2f);
	Matx13f C = AA.row(0);
	Matx13f D = AA.row(1);
	Matx13f E = C + D;

	cout << "rows : " << AA.rows << "cols : " << AA.cols << endl; // rows : 행 수, cols : 열 수.
	
	Matx23f U = Matx23f::all(10.0f);
	Matx23f F;
	F = AA * 5;

	Matx23f H = AA.mul(Z); // 각 원소를 곱한다. 해렬 곱셈이 아님에 주의한다.
	cout << H << endl;
	float dotAB = AA.dot(Z); // dot product.  행렬의 연산.
	cout << dotAB << endl;

	cout << AA.t() << endl;  // transpose
	// Matx22f G = A * B.t();
	

	Matx16f rand = Matx16f::randu(1.0, 2.0); // 범위 내 랜덤.
	cout << "rand : " << rand << endl;  

	Matx33f mati(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matx23f rand_to23 = rand.reshape<2, 3>(); // reshape. (1, 6)이었는데 (2, 3) 행렬로 바꾸겠다.
	Matx33f matinv = mati.inv();              // inverse. 역행렬

	// 방정식 풀어보기.
	
	Matx33d A(2, -1, 1, 3, 3, 9, 3, 3, 5);
	Matx31d b(-1, 0, 4);
	Matx31d X = A.solve(b);

	cout << "X : " << endl
		<< X << endl;

}