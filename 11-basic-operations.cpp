#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 기본 연산 함수
1.
abs(A);
convertScaleAbs(A, D, 2.0, 1.0);
abs(A*2.0 + 1);
absdiff(C, D, dst); // dst = abs(C-D);

2.
add(A, B, dst) // dst = A + B
add(A, B, dst, mask) // dst= A+B if mask != 0
add(A, 100, dst) // dst = A + 100
addWeighted(A, 2.0, B, 3.0, dst) dst = A*2 + B*3   // 이미지 두개를 반투명하게 섞을 수 있다. ex. 0.7, 0.3 으로 웨이트 두는 경우.
ScaleAdd(A, 2.0, B, dst) // dst = A * 2.0 + B
subtract(A, B, dst)
multiply(A, B, dst)
divide(A, B, dst) // dst = A/B
divide(A, 10, dst) // dst = A/10

3.
bitwise_and(A, B, dst) // dst = A & B
bitwise_or(A, B, dst)
bitwise_xor(a, b,  dst)
bitwise_and(A, B, dst, mast) // dst = A & B if mast != 0 

*/

int main()
{
	Mat mat1(Matx33f(1, 2, 3, 4, 5, 6, 7, 8, 9));
	Mat mat2(Matx33f(10, 11, 12, 13, 14, 15, 16, 17, 18));

	mat1 = mat1 > 4;
	cout << mat1 << endl;
}