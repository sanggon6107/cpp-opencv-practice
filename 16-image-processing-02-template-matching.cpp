#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*
1. ���� �� �� �ִ� ������Ʈ ���ؼ�. ���� �̹������� ���ø� �̹����� ��ġ�ϴ� ������ ã�� �˰���.

2. ���� �̹��� ���� ���ø� �̹����� ���� ���ݾ� �̵��ذ��� �̹��� ���� ������ ������ ���� ã�ư���.
-> ���ø� �̹����� �����ϰų�, Ȥ�� ���� ������ �̹��� ������ �����Ѵ�.
-> ���ø� �������, ���ø��� ���� �´� �κ��� ���� ��� ���´�.
-> ����, matchTemplate�� ��� Mat���� minMaxLoc���� max value���� �װ��� ��ġ�� max location�� �����Ͽ�
���ø� ��Ī�� ����� ���� �� �ִ�.


3. ������ �ݺ��ǰų� �ʹ� �ܼ��ϸ� ȿ���� ����.
4. test������ template ��� scaling, rotation ���̰� ũ�� ȿ���� ����.

*/



int main()
{
	Mat img = imread("letters.jpg", IMREAD_GRAYSCALE);
	Mat tpl_img = imread("letters-l.jpg", IMREAD_GRAYSCALE);
	Mat dst_img;

	cvtColor(img, dst_img, COLOR_GRAY2BGR); // ��� �̹��� �÷���.

	double minVal, maxVal;
	Point minLoc, maxLoc;
	Mat result;

	matchTemplate(img, tpl_img, result, TM_CCORR_NORMED);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc); // ���� ���� �κ� ����.(�������, ���ø��� �´� �κ��� ���� ��Գ��´�.)
	Point pos(maxLoc.x + tpl_img.cols, maxLoc.y + tpl_img.rows); // ���� ǥ���� �� �簢���� bottom-left ��ġ.
	rectangle(dst_img, maxLoc, pos, Scalar(0, 0, 255));
	minVal = 0;
	imshow("dst_img", dst_img);
	imshow("template image", tpl_img);

	waitKey(0);
	destroyAllWindows();
	
	
}