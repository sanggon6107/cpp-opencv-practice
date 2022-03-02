#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/*
1. sobel Ŀ��

x������
Matx<int, 3, 3> sobel(1, 0,-1,
					  2, 0,-2,
					  1, 0,-1)




y������
Matx<int, 3, 3> sobel(1, 2, 1,
					  0, 0, 0,
					  -1,-2,-1)

��, gradient�� �����ϴ� ��. ���� '��ȭ'�� �ִ� �ȼ����� anchor point���� 0�� �ƴϰ� �ȴ�.


2�� �̺��� ���ö�þ��� ���� ����� �ִ�.

�Һ� Ŀ���� ���, ������ ����(Prewitt filter)�� ���� �밢���� ���� ������ ����.

������ ���ʹ� �Ʒ��� ����.


x������
Matx<int, 3, 3> sobel(1, 0,-1,
					  1, 0,-1,
					  1, 0,-1)

��, ���� ���� �������� ����þ�(?)�� �������� �ʴ� ��. �����¿�δ� ���� ���ؼ��� �ѷ�������
�밢�� ó���� ���� ���ϴ�.


����, �Һ� Ŀ���� ��� Ŀ���� �߽ɿ��� �־������� ��Ȯ���� �������µ�, �̸� ������ ���� ���� ����(scharr filter)�̴�.

x������
Matx<int, 3, 3> sobel(3, 0, -3,
					  10, 0,-10,
					  3, 0, -3 )


���������� ���� �������ϰ� ���̰� �ִ� ĳ�Ͽ���(canny edge)�� �ִ�. ĳ�� ������ ������ �� �ܰ踦 ��ģ��.

1. ������ ����: 5 x 5 ����þ� ���� ���ͷ� ������ ����
2. ��� �׷����Ʈ ���� ���: �Һ� ���ͷ� ��� �� �׷����Ʈ ���� ����
3. ���ִ�ġ ����(Non-Maximum Suppression): �׷����Ʈ ���⿡�� ����� ��� �� ���� ū ���� �����ϰ� �������� ����
4. �̷� ������Ȧ��: �� ���� ��� ��(Max, Min)�� �����ؼ� ��� ������ �ִ� �ȼ��� �� ū ��� ��(Max) ���� �ȼ��� ���Ἲ�� ���� �ȼ� ����
*/



int main()
{
	Mat img = imread("lenna.png", IMREAD_GRAYSCALE);
	imshow("lenna", img);

	Mat low;
	GaussianBlur(img, low, Size(3, 3), 0.0);
	Mat high = img - low;
	Mat sharp = img + high * 5;

	Matx<int, 3, 3> fil(0, -1, 0,
						-1, 4, -1,
						0, -1, 0);   // ���� �ȼ� ����. ���� �����ϴ� ����. �ֺ��� ��� �ȼ��� ���̸� ���Ѵ�.

	Mat high2;
	filter2D(img, high2, -1, fil);
	Mat sharp2 = img + high2;

	imshow("high", high * 10);
	imshow("sharp", sharp);
	imshow("sharp2", sharp2);
	
	waitKey(0);
	destroyAllWindows();

}