#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/*
1. sobel 커널

x방향은
Matx<int, 3, 3> sobel(1, 0,-1,
					  2, 0,-2,
					  1, 0,-1)




y방향은
Matx<int, 3, 3> sobel(1, 2, 1,
					  0, 0, 0,
					  -1,-2,-1)

즉, gradient를 적용하는 것. 색의 '변화'가 있는 픽셀에서 anchor point값이 0이 아니게 된다.


2계 미분인 라플라시안을 쓰는 방법도 있다.

소벨 커널의 경우, 프리윗 필터(Prewitt filter)에 비해 대각선에 대한 검출이 좋다.

프리윗 필터는 아래와 같다.


x방향은
Matx<int, 3, 3> sobel(1, 0,-1,
					  1, 0,-1,
					  1, 0,-1)

즉, 수직 수평 방향으로 가우시안(?)을 적용하지 않는 것. 상하좌우로는 엣지 디텍션이 뚜렷하지만
대각선 처리가 좋지 못하다.


한편, 소벨 커널의 경우 커널의 중심에서 멀어질수록 정확도가 떨어지는데, 이를 보완한 것이 샤르 필터(scharr filter)이다.

x방향은
Matx<int, 3, 3> sobel(3, 0, -3,
					  10, 0,-10,
					  3, 0, -3 )


마지막으로 가장 광범위하게 쓰이고 있는 캐니엣지(canny edge)가 있다. 캐니 엣지는 다음의 네 단계를 거친다.

1. 노이즈 제거: 5 x 5 가우시안 블러링 필터로 노이즈 제거
2. 경계 그레디언트 방향 계산: 소벨 필터로 경계 및 그레디언트 방향 검출
3. 비최대치 억제(Non-Maximum Suppression): 그레디언트 방향에서 검출된 경계 중 가장 큰 값만 선택하고 나머지는 제거
4. 이력 스레시홀딩: 두 개의 경계 값(Max, Min)을 지정해서 경계 영역에 있는 픽셀들 중 큰 경계 값(Max) 밖의 픽셀과 연결성이 없는 픽셀 제거
*/



int main()
{
	Mat img = imread("lenna.png", IMREAD_GRAYSCALE);
	imshow("lenna", img);

	Mat low;
	GaussianBlur(img, low, Size(3, 3), 0.0);
	Mat high = img - low;
	Mat sharp = img + high * 5;

	Matx<int, 3, 3> fil(0, -1, 0,
						-1, 4, -1,
						0, -1, 0);   // 현재 픽셀 강조. 엣지 추출하는 필터. 주변과 대상 픽셀의 차이를 구한다.

	Mat high2;
	filter2D(img, high2, -1, fil);
	Mat sharp2 = img + high2;

	imshow("high", high * 10);
	imshow("sharp", sharp);
	imshow("sharp2", sharp2);
	
	waitKey(0);
	destroyAllWindows();

}