#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*
1. 쉽게 쓸 수 있는 오브젝트 디텍션. 원본 이미지에서 템플릿 이미지와 일치하는 영역을 찾는 알고리즘.

2. 원본 이미지 위에 템플릿 이미지를 놓고 조금씩 이동해가며 이미지 끝에 도달할 때까지 비교해 찾아간다.
-> 템플릿 이미지와 동일하거나, 혹은 가장 유사한 이미지 영역을 검출한다.
-> 템플릿 결과에서, 템플릿에 가장 맞는 부분이 가장 밝게 나온다.
-> 따라서, matchTemplate의 결과 Mat에서 minMaxLoc으로 max value값과 그것의 위치인 max location을 검출하여
템플릿 매칭의 결과를 얻을 수 있다.


3. 패턴이 반복되거나 너무 단순하면 효과가 없다.
4. test영상이 template 대비 scaling, rotation 차이가 크면 효과가 없다.

*/



int main()
{
	Mat img = imread("letters.jpg", IMREAD_GRAYSCALE);
	Mat tpl_img = imread("letters-l.jpg", IMREAD_GRAYSCALE);
	Mat dst_img;

	cvtColor(img, dst_img, COLOR_GRAY2BGR); // 출력 이미지 컬러로.

	double minVal, maxVal;
	Point minLoc, maxLoc;
	Mat result;

	matchTemplate(img, tpl_img, result, TM_CCORR_NORMED);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc); // 가장 밝은 부분 검출.(결과에서, 템플릿에 맞는 부분이 가장 밝게나온다.)
	Point pos(maxLoc.x + tpl_img.cols, maxLoc.y + tpl_img.rows); // 검출 표시할 때 사각형의 bottom-left 위치.
	rectangle(dst_img, maxLoc, pos, Scalar(0, 0, 255));
	minVal = 0;
	imshow("dst_img", dst_img);
	imshow("template image", tpl_img);

	waitKey(0);
	destroyAllWindows();
	
	
}