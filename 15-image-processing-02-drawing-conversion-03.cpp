#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;


/* 직선 반복자 : 말 그대로 직선 위의 점들을 하나하나 반복해준다.

1. 선언부는 다음과 같다.
	LineIterator( const Mat& img, Point pt1, Point pt2,
				  int connectivity = 8, bool leftToRight = false )

2. 아래 코드는, 직선 위를 반복자로 나아가면서 각 좌표의 RGB값을 x값에 따라 분석하고 그래프로 나타낸 것이다.
*/

int main()
{
	Mat img = imread("lenna.png");

	Point pt_1(10, 10), pt_2(400, 400);
	LineIterator itr(img, pt_1, pt_2, 8);
	
	vector<Vec3b> pts(itr.count);
	for (int i = 0; i < itr.count; i++, ++itr)
	{
		auto pos = itr.pos();
		pts[i] = img.at<Vec3b>(pos);
	}
	line(img, pt_1, pt_2, Scalar(255, 255, 255)); // 어떤 곳 그엇는지 표시하기.

	Mat dst_img(512, 512, CV_8UC3, Scalar(255, 255, 255));


	// B
	pt_1 = Point(0, dst_img.cols - pts[0](0));
	for (int i = 1; i < (int)pts.size(); i++, ++itr)
	{
		pt_2 = Point(i, dst_img.cols - pts[i][0]);
		line(dst_img, pt_1, pt_2, Scalar(255), 2);
		pt_1 = pt_2;
	}


	// G
	pt_1 = Point(0, dst_img.cols - pts[0](1));
	for (int i = 1; i < (int)pts.size(); i++, ++itr)
	{
		pt_2 = Point(i, dst_img.cols - pts[i][1]);
		line(dst_img, pt_1, pt_2, Scalar(0, 255, 0), 2);
		pt_1 = pt_2;
	}

	// R
	pt_1 = Point(0, dst_img.cols - pts[0](2));
	for (int i = 1; i < (int)pts.size(); i++, ++itr)
	{
		pt_2 = Point(i, dst_img.cols - pts[i][2]);
		line(dst_img, pt_1, pt_2, Scalar(0, 0, 255), 2);
		pt_1 = pt_2;
	}



	imshow("img", img);
	imshow("dst_img", dst_img);
	
	waitKey(0);
	destroyAllWindows();

}