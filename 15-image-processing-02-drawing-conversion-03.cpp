#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


/* 직선 반복자 : 직선을 그어서, 그 직선 위에 있는 값 분석.

	LineIterator( const Mat& img, Point pt1, Point pt2,
				  int connectivity = 8, bool leftToRight = false )


*/

int main()
{
	Mat img = imread("lenna.png");

	Point pt_1(10, 10), pt_2(400, 400);
	LineIterator itr(img, pt_1, pt_2, 8);
	

	waitKey(0);
	destroyAllWindows();

}