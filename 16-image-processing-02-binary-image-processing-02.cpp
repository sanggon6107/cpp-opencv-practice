#include <opencv2/opencv.hpp>

using namespace cv;

/* blob

1.
�̹������� �̹� ���� �ȼ� ���(?)  (connected components)�� �����Ѵ�.

2. connectedComponents �����.
int connectedComponents(InputArray image, OutputArray labels,
									 int connectivity = 8, int ltype = CV_32S);

3. connectedComponentsWithStats �����.  WIthStats�� detect�� ��ü���� �پ��� ������ ��� �ִ�.

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

	// threshold�� ����ȭ.
	// threshold(img, bin_1, 100, 255, THRESH_BINARY_INV);
	threshold(img, bin_2, 100, 255, THRESH_BINARY_INV + THRESH_OTSU);
	
	// connectedComponentsWithStats�� ���ڵ�.
	Mat stats, centroid, label;

	// connectedComponents�� ��ȯ���� blob�� ����.
	int cnt = connectedComponentsWithStats(bin_2, label, stats, centroid); 

	Mat img_color;
	
	cvtColor(img, img_color, COLOR_GRAY2BGR); 


	for (int i = 1; i < cnt; i++)  // ù ��° ��Ұ� ��ü�̴�.
	{
		int l = stats.at<int>(i, CC_STAT_LEFT);
		int t = stats.at<int>(i, CC_STAT_TOP);
		int w = stats.at<int>(i, CC_STAT_WIDTH);
		int h = stats.at<int>(i, CC_STAT_HEIGHT);
		rectangle(img_color, Rect(l, t, w, h), Scalar(0, 0, 255)); // detect�� ��ü �簢�� ǥ��.

		double cx = centroid.at<double>(i, 0);
		double cy = centroid.at<double>(i, 1);
		drawMarker(img_color, Point2d(cx, cy), Scalar(0, 255, 0));  // centroid(�����߽�) ǥ��.
	}


	imshow("bin_2", bin_2);

	imshow("img_color", img_color);

	// imshow("stats", stats); // error.

	waitKey(0);
	destroyAllWindows();
}