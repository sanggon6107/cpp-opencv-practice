#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


/* 원, 타원

1. 원
void circle(InputOutputArray img, Point center, int radius,
					   const Scalar& color, int thickness = 1,
					   int lineType = LINE_8, int shift = 0);

2. 타원
CV_EXPORTS_W void ellipse(InputOutputArray img, Point center, Size axes,
						double angle, double startAngle, double endAngle,
						const Scalar& color, int thickness = 1,
						int lineType = LINE_8, int shift = 0);

*/

int main()
{
	Mat dst_img(512, 512, CV_8UC3, Scalar(255, 255, 255));
	rectangle(dst_img, Point(100, 100), Point(400, 400), Scalar(0, 0, 255));
	line(dst_img, Point(100, 250), Point(400, 250), Scalar(0, 0, 255));
	line(dst_img, Point(250, 100), Point(250, 400), Scalar(0, 0, 255));
	
	circle(dst_img, Point(250, 250), 30, Scalar(255, 0, 0), -1);  // 두께 -1 : 채운 원.
	circle(dst_img, Point(250, 250), 150, Scalar(0, 255, 0));

	ellipse(dst_img, Point(250, 250), Size(200, 100), 45, 45, 360, Scalar(0, 0, 250), 2);


	imshow("dst_img", dst_img);
	waitKey(0);
	destroyAllWindows();

}