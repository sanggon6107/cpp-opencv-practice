#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;



int main()
{
	Mat img = imread("sky.jpg");
	
	
	img.convertTo(img, CV_64FC3);
	img /= 255.0;
	Mat img_correction;
	pow(img, 0.5, img_correction); // img to the power of 0.5  // 감마를 2 넣어줬다는 뜻.(감마는 역수)
	img_correction *= 255;
	img_correction.convertTo(img_correction, CV_8UC3);


	imshow("img", img);
	imshow("img_correction", img_correction);
	waitKey();
	destroyAllWindows();
}