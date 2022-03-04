#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <type_traits>

using namespace std;
using namespace cv;


/* ���� �ݺ��� : �� �״�� ���� ���� ������ �ϳ��ϳ� �ݺ����ش�.

1. ����δ� ������ ����.
	LineIterator( const Mat& img, Point pt1, Point pt2,
				  int connectivity = 8, bool leftToRight = false )

2. �Ʒ� �ڵ��, ���� ���� �ݺ��ڷ� ���ư��鼭 �� ��ǥ�� RGB���� x���� ���� �м��ϰ� �׷����� ��Ÿ�� ���̴�.
*/

int main()
{
	Mat img = imread("lenna.png");

	Point pt_1(10, 10), pt_2(400, 400);
	LineIterator itr(img, pt_1, pt_2, 8);
	
	cout << "itr.count : " << itr.count << endl // ��� ���� count�� ������ ���Ե� ��ǥ�� �����̴�.
		<< "itr.pos() : " << itr.pos() << endl; // ��� �Լ� pos()�� ���� ���ͷ����Ͱ� ����Ű�� �ִ� ��ǥ�� ��ȯ�Ѵ�.
	
	cout << "type of itr.pos() : " << typeid(itr.pos()).name() << endl; // type of itr.pos() : class cv::Point_<int>


	vector<Vec3b> pts(itr.count); // itr ������ŭ Vec3b ��ü�� ������ ���� ����.
	for (int i = 0; i < itr.count; i++, ++itr)
	{
		auto pos = itr.pos();
		pts[i] = img.at<Vec3b>(pos); // pos��ġ�� Vec3b�� pts�� �ִ´�.
	}
	line(img, pt_1, pt_2, Scalar(255, 255, 255)); // � �� �׾����� ǥ���ϱ�.

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