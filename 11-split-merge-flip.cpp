#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <array>
#include <string>

using namespace std;
using namespace cv;

/* 이미지 RBG별로 분리(split), 다시 합치기(merge), 뒤집기(flip)
*/

int main()
{

	Mat sky = imread("sky.jpg");
	vector<Mat> vec;
	split(sky, vec); // RGB별로 분리해서 vec에 넣는다.


	array<Mat, 4> dstImage;
	merge(vec, dstImage[0]);
	flip(sky, dstImage[1], 0); // 상하
	flip(sky, dstImage[2], 1); // 좌우
	flip(sky, dstImage[3], -1); // 상하, 좌우
	
	for (int i = 0; i < dstImage.size(); i++)
	{
		string win_name = "image" + to_string(i);
		imshow(win_name, dstImage[i]);
	}


	waitKey();
	destroyAllWindows();


}