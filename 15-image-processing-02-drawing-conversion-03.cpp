#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


/* ���� �ݺ��� : ������ �׾, �� ���� ���� �ִ� �� �м�.

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