#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <array>
#include <string>

using namespace std;
using namespace cv;

/* �̹��� RBG���� �и�(split), �ٽ� ��ġ��(merge), ������(flip)
*/

int main()
{

	Mat sky = imread("sky.jpg");
	vector<Mat> vec;
	split(sky, vec); // RGB���� �и��ؼ� vec�� �ִ´�.


	array<Mat, 4> dstImage;
	merge(vec, dstImage[0]);
	flip(sky, dstImage[1], 0); // ����
	flip(sky, dstImage[2], 1); // �¿�
	flip(sky, dstImage[3], -1); // ����, �¿�
	
	for (int i = 0; i < dstImage.size(); i++)
	{
		string win_name = "image" + to_string(i);
		imshow(win_name, dstImage[i]);
	}


	waitKey();
	destroyAllWindows();


}