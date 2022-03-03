#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


/* 그리기 함수 : 직선, 사각형, 다각형

1. 직선

void line(InputOutputArray img, Point pt1, Point pt2, const Scalar& color, int thickness = 1, int lineType = LINE_8, int shift = 0);

2. 사각형

void rectangle(InputOutputArray img, Point pt1, Point pt2, const Scalar& color, int thickness = 1, int lineType = LINE_8, int shift = 0);

void rectangle(CV_IN_OUT Mat& img, Rect rec, const Scalar& color, int thickness = 1, int lineType = LINE_8, int shift = 0);

3. 다각형

void polylines(Mat& img, const Point* const* pts, const int* npts, int ncontours, bool isClosed,
				const Scalar& color, int thickness = 1, int lineType = LINE_8, int shift = 0);

pts : 다각형의 꼭지점 집합.
npts : 표시할 다각형의 각형수
int ncontours : 표시할 다각형의 수


*/


int main()
{
	Mat dst_img(512, 512, CV_8UC3, Scalar(255, 255, 255));
	Mat dst_img_2(512, 512, CV_8UC3, Scalar(255, 255, 255));

	Point pts_1[3] = { Point(300, 200), Point(400, 100), Point(400, 200) };
	Point pts_2[4] = { Point(100, 100), Point(200, 100), Point(200, 200), Point(100, 200) };

	int npts[2] = { 3, 4 };
	const Point* pts[2] = { pts_1, pts_2 };

	polylines(dst_img, pts, npts, 2, true, Scalar(0, 0, 255));
	fillConvexPoly(dst_img_2, pts[0], npts[0], Scalar(0, 0, 255));

	imshow("dst_img", dst_img);
	imshow("dst_img_2", dst_img_2);

	waitKey(0);
	destroyAllWindows();

}