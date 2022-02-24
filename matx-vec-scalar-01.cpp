#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* Matx Ŭ���� : ������ ���� ũ���� ����� ǥ���ϴ� ���ø�.
* 
1. ���� �������� ����̴�. ū ũ���� ����� Mat�� ����ȣȯ ����.

2. Point_, Size_, Rect_ó�� ���� ���ø� ���ڿ� ���� typedef �Ǿ��ִ�.


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
	Matx<float, 2, 3> AA(1, 2, 3, 4, 5, 6); // 2 x 3�� float ���.
	Matx<float, 2, 3> Z(7, 8, 9, 10, 11, 12);
	Matx12f B(1.0f, 2.2f);
	Matx13f C = AA.row(0);
	Matx13f D = AA.row(1);
	Matx13f E = C + D;

	cout << "rows : " << AA.rows << "cols : " << AA.cols << endl; // rows : �� ��, cols : �� ��.
	
	Matx23f U = Matx23f::all(10.0f);
	Matx23f F;
	F = AA * 5;

	Matx23f H = AA.mul(Z); // �� ���Ҹ� ���Ѵ�. �ط� ������ �ƴԿ� �����Ѵ�.
	cout << H << endl;
	float dotAB = AA.dot(Z); // dot product.  ����� ����.
	cout << dotAB << endl;

	cout << AA.t() << endl;  // transpose
	// Matx22f G = A * B.t();
	

	Matx16f rand = Matx16f::randu(1.0, 2.0); // ���� �� ����.
	cout << "rand : " << rand << endl;  

	Matx33f mati(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matx23f rand_to23 = rand.reshape<2, 3>(); // reshape. (1, 6)�̾��µ� (2, 3) ��ķ� �ٲٰڴ�.
	Matx33f matinv = mati.inv();              // inverse. �����

	// ������ Ǯ���.
	
	Matx33d A(2, -1, 1, 3, 3, 9, 3, 3, 5);
	Matx31d b(-1, 0, 4);
	Matx31d X = A.solve(b);

	cout << "X : " << endl
		<< X << endl;

}