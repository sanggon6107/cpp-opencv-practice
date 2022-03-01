#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* normalize

1.
������ �Ʒ��� ����.

void normalize(InputArray src, InputOutputArray dst, double alpha = 1, double beta = 0,
		       int norm_type = NORM_L2, int dtype =-1,
			   InputArray mask = noArray());

2. 0~255 �� 0~1�� ������ �ٲ۴ٰų�, �̹����� ��Ʈ��ġ �Ѵٰų�, �ʹ� ��ų� �ʹ� ��ο� �̹��� ���� ó���� �� ����.

3. alph : norm value to normalize to or the lower range boundary in case of the range normalization.

4. beta : upper range boundary in case of the range normalization; it is not used for the norm normalization.

5. normType : normalization type.

6. dtype : when negative, the output array has the same type as src; otherwise, it has the same number of channels as src and the depth = CV_DEPTH(dtype).

7. mask : optional operation mask. ���ǿ� �´� �ȼ��� normalize �ϰڴ�.

*/


int main()
{
	Mat img1 = imread("lenna.png", IMREAD_GRAYSCALE);
	Mat img2 = img1 / 2 + 100; // �Ͼ�� �� �� �̹���.
	imshow("img1", img1);

	Mat img3;
	normalize(img2, img3, 0, 255, NORM_MINMAX); // 0 ~ 255�� ������ ��Ʈ��ġ�Ѵ�. 
	imshow("img3", img3);

	Mat img4 = img1 / 50;
	Mat img5;
	normalize(img4, img5, 0, 255, NORM_MINMAX); // 50���� �ѹ� �������� ������, �̹��� �ջ��� �ִ�. ��Ʈ��ġ�ص� �Ϻ��ϰԴ� �������� �ʴ´�.
												// �ð��� ȿ���� ���ؼ� ������ -> ����ȭ �Ϻη� �ϴ� ��쵵 �ִ�.
	imshow("img5", img5);
	
	waitKey(0);
	destroyAllWindows();
}