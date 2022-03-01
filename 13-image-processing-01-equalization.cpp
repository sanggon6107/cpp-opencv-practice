#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* equalization

1. Ư�� �������� ���ִ� �ȼ���(������� 100~150���� ���ִٸ�)��,
������� 0 ~ 255 ������ ��Ʈ��ġ ���ش�.
�� ��, ������׷��� ���� ��ġ�� ���̴� ������ �� �е��ְ� �׸���. (��� ����.)

*/


int main()
{
	Mat src_img = imread("lenna.png", IMREAD_GRAYSCALE);
	Mat dst_img;
	equalizeHist(src_img, dst_img);
	imshow("dst_img", dst_img);


	int hist_size = 256;
	float value_range[] = { 0, 255 };
	const float* ranges[] = { value_range };
	int channels = 0;
	int dims = 1;

	Mat hist;
	calcHist(&dst_img, 1, &channels, Mat(), hist, dims, &hist_size, ranges);


	// �׷��� �׸���.
	Mat hist_image(512, 512, CV_8U);
	normalize(hist, hist, 0, hist_image.rows, NORM_MINMAX, CV_32F); // histogram �� row �ȼ� ����ŭ ����ȭ �ؾ��Ѵ�.(�׷��� �׸��� ���ؼ�)

	hist_image = Scalar(255); // �������.
	int bin_w = cvRound((double)hist_image.cols / hist_size);
	int x1, y1, x2, y2;
	for (int i = 0; i < hist_size; i++)
	{
		x1 = i * bin_w;
		y1 = hist_image.rows;
		x2 = (i + 1) * bin_w;
		y2 = hist_image.rows - cvRound(hist.at<float>(i));
		rectangle(hist_image, Point(x1, y1), Point(x2, y2),   // hist_image�� �� ĭ �� ĭ �׸� �׷��� ��Ÿ����.
			Scalar(0), -1);
	}
	imshow("hist_image", hist_image);


	waitKey(0);
	destroyAllWindows();



}