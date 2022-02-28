#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* ����.
������ ���� ���ܺ���.
*/


int main()
{
	// ���� 1280 853
	// ���ĺ� 640 392

	Mat sky = imread("sky.jpg");
	Mat alpha = imread("alphabet.jpg");
	Mat alpha_gray = imread("alphabet.jpg", IMREAD_GRAYSCALE); // ����ȭ�Ͽ� �̹��� ���� ���� �����ϱ� ���� �׷��̽����Ϸ� �ҷ��´�.

	Rect rect_roi(sky.cols - alpha.cols - 1, 0, alpha.cols, alpha.rows); // region of interest �׸��� ���� �簢��. x, y, width, height.
	Mat roi = sky(rect_roi); // region of interest. �׸��� ������ ���� �ٿ��� �׸���.
	
	Mat mask = alpha_gray > 15; // 15 �̻� true(=255)�� ���ܼ� ����ȭ�Ѵ�.
	Mat mask_inv = 255 - mask; // �� �ݴ�.

	Mat roi_bg, roi_fg;
	bitwise_and(roi, roi, roi_bg, mask_inv); // ���ĺ� �̿��� ���￡ ���ؼ��� roi�� �׸� �״�� �׷��� �Ѵ�.
	bitwise_and(alpha, alpha, roi_fg, mask); // ���ĺ��� ������ ���ؼ��� alph�� �̹����� �׸���.
	
	Mat result = sky.clone();
	add(roi_bg, roi_fg, result(rect_roi)); // result(rect_roi)�� ������ roi_bg, roi_fg ���Ѵ�.
	
	imshow("result", result);

	waitKey();
	destroyAllWindows();
	

}