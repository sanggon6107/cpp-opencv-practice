#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* equalization

1. 특정 영역에만 모여있는 픽셀들(예를들어 100~150에만 모여있다면)을,
예를들어 0 ~ 255 범위로 스트레치 해준다.
이 때, 히스토그램상 낮은 수치를 보이는 영역을 더 밀도있게 그린다. (결과 참고.)

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


	// 그래프 그리기.
	Mat hist_image(512, 512, CV_8U);
	normalize(hist, hist, 0, hist_image.rows, NORM_MINMAX, CV_32F); // histogram 의 row 픽셀 수만큼 정규화 해야한다.(그래프 그리기 위해서)

	hist_image = Scalar(255); // 흰색으로.
	int bin_w = cvRound((double)hist_image.cols / hist_size);
	int x1, y1, x2, y2;
	for (int i = 0; i < hist_size; i++)
	{
		x1 = i * bin_w;
		y1 = hist_image.rows;
		x2 = (i + 1) * bin_w;
		y2 = hist_image.rows - cvRound(hist.at<float>(i));
		rectangle(hist_image, Point(x1, y1), Point(x2, y2),   // hist_image에 한 칸 한 칸 네모 그려서 나타낸다.
			Scalar(0), -1);
	}
	imshow("hist_image", hist_image);


	waitKey(0);
	destroyAllWindows();



}