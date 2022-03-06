#include <opencv2/opencv.hpp>

using namespace cv;

/* Affine transform
1. ���״�� ���� ��ȯ.

2. Ư�� ���� �߽����� ȸ����Ű�� ���� ȿ���� ���� �� �ִ�.

3. ���� getRotationMatrix2D �Լ��� ���� ��ȯ ����� ��´�.

4. �״��� warpAffine �Լ��� ��ȯ�Ѵ�.

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