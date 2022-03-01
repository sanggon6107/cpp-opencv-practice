#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* normalize

1.
원형은 아래와 같다.

void normalize(InputArray src, InputOutputArray dst, double alpha = 1, double beta = 0,
		       int norm_type = NORM_L2, int dtype =-1,
			   InputArray mask = noArray());

2. 0~255 를 0~1로 범위를 바꾼다거나, 이미지를 스트레치 한다거나, 너무 밝거나 너무 어두운 이미지 등을 처리할 때 쓴다.

3. alph : norm value to normalize to or the lower range boundary in case of the range normalization.

4. beta : upper range boundary in case of the range normalization; it is not used for the norm normalization.

5. normType : normalization type.

6. dtype : when negative, the output array has the same type as src; otherwise, it has the same number of channels as src and the depth = CV_DEPTH(dtype).

7. mask : optional operation mask. 조건에 맞는 픽셀만 normalize 하겠다.

*/


int main()
{
	Mat img1 = imread("lenna.png", IMREAD_GRAYSCALE);
	Mat img2 = img1 / 2 + 100; // 하얗게 붕 뜬 이미지.
	imshow("img1", img1);

	Mat img3;
	normalize(img2, img3, 0, 255, NORM_MINMAX); // 0 ~ 255의 범위로 스트레치한다. 
	imshow("img3", img3);

	Mat img4 = img1 / 50;
	Mat img5;
	normalize(img4, img5, 0, 255, NORM_MINMAX); // 50으로 한번 나누었기 때문에, 이미지 손상이 있다. 스트레치해도 완벽하게는 복원되지 않는다.
												// 시각적 효과를 위해서 나누기 -> 정규화 일부러 하는 경우도 있다.
	imshow("img5", img5);
	
	waitKey(0);
	destroyAllWindows();
}