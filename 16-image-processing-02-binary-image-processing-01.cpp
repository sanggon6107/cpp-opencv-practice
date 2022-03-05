#include <opencv2/opencv.hpp>

using namespace cv;

/* morphological operation

1. elode : ��´�.

void erode( InputArray src, OutputArray dst, InputArray kernel,
						 Point anchor = Point(-1,-1), int iterations = 1,
						 int borderType = BORDER_CONSTANT,
						 const Scalar& borderValue = morphologyDefaultBorderValue() );



2. dilate : ��Ǯ����.



*/



int main()
{
	Mat img = imread("erode.png", IMREAD_GRAYSCALE);

	Size size(5, 5);
	int iterations = 3;
	Point anchor(-1, -1);

	Mat rectKernel = getStructuringElement(MORPH_RECT, size);  // �簢������ elode/dilate�ϴ� Ŀ��. zeros�� ���� ����̴�.
															   // �̿ܿ� ���׶��� erode/dilate�ϴ� MORPH_ELLPSE, ���ڰ� ����� MORPH_CROSS ���� �ִ�.
	Mat erode_img;
	erode(img, erode_img, rectKernel, anchor, iterations);

	

	Mat img_2 = imread("dilate.png", IMREAD_GRAYSCALE);
	Mat img_dilate;

	dilate(img_2, img_dilate, rectKernel, anchor, iterations);

	imshow("img", img);
	imshow("erode_img", erode_img);

	imshow("img_2", img_2);
	imshow("img_dilate", img_dilate);

	waitKey(0);
	destroyAllWindows();
	


}