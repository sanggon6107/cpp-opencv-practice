#include <opencv2/opencv.hpp>

using namespace cv;

/* Affine transform
1. 말그대로 선형 변환.

2. 특정 점을 중심으로 회전시키는 등의 효과를 얻을 수 있다.

3. 먼저 getRotationMatrix2D 함수로 선형 변환 행렬을 얻는다.

4. 그다음 warpAffine 함수로 변환한다.

*/

int main()
{
	Mat img = imread("lenna.png");
	
	Point2f center(img.cols/2.0f, img.rows/2.0f);
	double angle = 45.0;
	double scale = 1.0;
	Mat rotMat = getRotationMatrix2D(center, angle, scale);
	
	Mat dst_img;
	int flag = INTER_LINEAR;
	warpAffine(img, dst_img, rotMat, Size(), flag);
	imshow("dst_img", dst_img);

	waitKey(0);
	destroyAllWindows();
	
}