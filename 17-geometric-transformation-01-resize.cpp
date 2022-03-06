#include <opencv2/opencv.hpp>

using namespace cv;

/* resize

1. 
void resize( InputArray src, OutputArray dst,
                          Size dsize, double fx = 0, double fy = 0,
                          int interpolation = INTER_LINEAR );



*/

int main()
{
    Mat img = imread("lenna.png");
    imshow("img", img);
    
    Mat dst_img(320, 240, CV_8U);
    resize(img, dst_img, dst_img.size(), 0, 0, INTER_AREA);
    imshow("dst_img", dst_img);

    Mat dst_img_2;
    resize(img, dst_img_2, Size(), 1.2, 1.4, INTER_LINEAR);
    imshow("dst_img_2", dst_img_2);

    waitKey(0);
    destroyAllWindows();
}