#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/* ��
1. void medianBlur(InputArray src, OutputArray dst, int ksize);

salt-and-pepper-noise�� ȿ����. �ڽ� ���� ���� Ȯ���� �̹����� �������� ���� ���ϴ�.

2. void blur(InputArray src, OutputArray dst, Size ksize, Point anchor = Point(-1, -1), int borderType = BORDER_DEFAULT ); : �ڽ����̴�.

�� : Ŀ�� (1/9) * Matx33f(1, 1, 1,
						 1, 1, 1,
						 1, 1, 1);

3. void Gaussian Blur(InputArray src, OutputArray dst, Size ksize, double sigmaX, 
						double sigmaY = 0, int borderType = BORDER_DEFAULT );

�� : Ŀ�� (1/337) * Matx55(1,  4,  7,  4, 1,
						  4, 20, 33, 20, 4,
						  7, 33, 55, 33, 7
						  4, 20, 33, 20, 4
						  1,  4,  7,  4, 1);
*/


/* ������� ����.

Ŀ���� �߽ɺΰ� ���� ����ϴ� �ȼ�. ��, 3*3 Ŀ���̸� �߰��� �� ���� ���� ������ ����̵Ǵ� �ȼ�.
���� �ȼ�

Matx33f(1, 2, 3,
		4, 5, 6,
		2, 2, 2);

�� �ִٰ� ����.

���� �������� �ȼ��� �߰��� �ȼ�(5)�̰�, �̰��� �ڽ� �������� �����ϸ�,

5 --------->   1/9  *  (   1*1 + 2*1 + 3*1 + .... 2*1  )   = 27/9 = 3 �̵ȴ�.
�� 5�̴� �ȼ��� 3�� �ȴ�. �̰��� ��� �ȼ��� ���� �����ϸ� ������ �Ǵ� ��.


*/


int main()
{
	Mat img = imread("lenna.png", IMREAD_GRAYSCALE);
	imshow("lenna", img);
	int ksize = 7;

	
	Mat dst_img;
	medianBlur(img, dst_img, ksize);
	imshow("medianBlur", dst_img);


	Mat dst_img2;
	blur(img, dst_img2, Size(ksize, ksize));
	imshow("blur", dst_img2);

	Mat dst_img3;
	GaussianBlur(img, dst_img3, Size(ksize, ksize), 0.0);
	imshow("GaussianBlur", dst_img3);
	
	waitKey(0);
	destroyAllWindows();

}