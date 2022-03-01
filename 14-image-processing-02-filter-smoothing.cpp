#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/* 블러
1. void medianBlur(InputArray src, OutputArray dst, int ksize);

salt-and-pepper-noise에 효과적. 박스 블러에 비해 확실히 이미지가 뭉개지는 것이 덜하다.

2. void blur(InputArray src, OutputArray dst, Size ksize, Point anchor = Point(-1, -1), int borderType = BORDER_DEFAULT ); : 박스블러이다.

예 : 커널 (1/9) * Matx33f(1, 1, 1,
						 1, 1, 1,
						 1, 1, 1);

3. void Gaussian Blur(InputArray src, OutputArray dst, Size ksize, double sigmaX, 
						double sigmaY = 0, int borderType = BORDER_DEFAULT );

예 : 커널 (1/337) * Matx55(1,  4,  7,  4, 1,
						  4, 20, 33, 20, 4,
						  7, 33, 55, 33, 7
						  4, 20, 33, 20, 4
						  1,  4,  7,  4, 1);
*/


/* 컨볼루션 연산.

커널의 중심부가 현재 계산하는 픽셀. 즉, 3*3 커널이면 중간의 한 개가 현재 연산의 대상이되는 픽셀.
현재 픽셀

Matx33f(1, 2, 3,
		4, 5, 6,
		2, 2, 2);

가 있다고 하자.

현재 연산중인 픽셀은 중간의 픽셀(5)이고, 이것을 박스 블러링으로 연산하면,

5 --------->   1/9  *  (   1*1 + 2*1 + 3*1 + .... 2*1  )   = 27/9 = 3 이된다.
즉 5이던 픽셀이 3이 된다. 이것을 모든 픽셀에 대해 연산하면 블러링이 되는 것.


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