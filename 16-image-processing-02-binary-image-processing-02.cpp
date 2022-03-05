#include <opencv2/opencv.hpp>

using namespace cv;

/* blob

1.
이미지에서 이물 등의 픽셀 덩어리(?)  (connected components)를 검출한다.

2. connectedComponents 선언부.
int connectedComponents(InputArray image, OutputArray labels,
									 int connectivity = 8, int ltype = CV_32S);

3. connectedComponentsWithStats 선언부.  WIthStats는 detect된 객체들의 다양한 정보를 담고 있다.

int connectedComponentsWithStats(InputArray image, OutputArray labels,
											  OutputArray stats, OutputArray centroids,
											  int connectivity = 8, int ltype = CV_32S);


stats : statistics output for each label, including the background label.
*/


int main()
{
	// blob detection

	Mat img = imread("blob.png", IMREAD_GRAYSCALE);
	Mat bin_1, bin_2;

	// threshold로 이진화.
	// threshold(img, bin_1, 100, 255, THRESH_BINARY_INV);
	threshold(img, bin_2, 100, 255, THRESH_BINARY_INV + THRESH_OTSU);
	
	// connectedComponentsWithStats의 인자들.
	Mat stats, centroid, label;

	// connectedComponents의 반환값은 blob의 개수.
	int cnt = connectedComponentsWithStats(bin_2, label, stats, centroid); 

	Mat img_color;
	
	cvtColor(img, img_color, COLOR_GRAY2BGR); 


	for (int i = 1; i < cnt; i++)  // 첫 번째 요소가 전체이다.
	{
		int l = stats.at<int>(i, CC_STAT_LEFT);
		int t = stats.at<int>(i, CC_STAT_TOP);
		int w = stats.at<int>(i, CC_STAT_WIDTH);
		int h = stats.at<int>(i, CC_STAT_HEIGHT);
		rectangle(img_color, Rect(l, t, w, h), Scalar(0, 0, 255)); // detect된 물체 사각형 표시.

		double cx = centroid.at<double>(i, 0);
		double cy = centroid.at<double>(i, 1);
		drawMarker(img_color, Point2d(cx, cy), Scalar(0, 255, 0));  // centroid(무게중심) 표시.
	}


	imshow("bin_2", bin_2);

	imshow("img_color", img_color);

	// imshow("stats", stats); // error.

	waitKey(0);
	destroyAllWindows();
}