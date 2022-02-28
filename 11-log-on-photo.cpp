#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 연습.
사진에 글자 새겨보기.
*/


int main()
{
	// 사진 1280 853
	// 알파벳 640 392

	Mat sky = imread("sky.jpg");
	Mat alpha = imread("alphabet.jpg");
	Mat alpha_gray = imread("alphabet.jpg", IMREAD_GRAYSCALE); // 이진화하여 이미지 붙일 영역 결정하기 위해 그레이스케일로 불러온다.

	Rect rect_roi(sky.cols - alpha.cols - 1, 0, alpha.cols, alpha.rows); // region of interest 그리기 위한 사각형. x, y, width, height.
	Mat roi = sky(rect_roi); // region of interest. 그림의 오른쪽 위로 붙여서 그린다.
	
	Mat mask = alpha_gray > 15; // 15 이상만 true(=255)로 남겨서 이진화한다.
	Mat mask_inv = 255 - mask; // 그 반대.

	Mat roi_bg, roi_fg;
	bitwise_and(roi, roi, roi_bg, mask_inv); // 알파벳 이외의 영억에 대해서는 roi의 그림 그대로 그려야 한다.
	bitwise_and(alpha, alpha, roi_fg, mask); // 알파벳의 영역에 한해서는 alph의 이미지를 그린다.
	
	Mat result = sky.clone();
	add(roi_bg, roi_fg, result(rect_roi)); // result(rect_roi)의 영역에 roi_bg, roi_fg 더한다.
	
	imshow("result", result);

	waitKey();
	destroyAllWindows();
	

}