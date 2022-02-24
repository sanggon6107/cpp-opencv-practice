#include <iostream>
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;
int main()
{
    VideoCapture stream1(0); //0 is the id of video device.0 if you have only one camera
    if (!stream1.isOpened()) { //check if video device has been initialised
        cout << "cannot open camera";
    }

    namedWindow("Processing");
    namedWindow("Origin");

    //unconditional loop
    while (true) {
        Mat cameraFrame;
        stream1.read(cameraFrame); //get one frame form video
        imshow("Origin", cameraFrame);
        Sobel(cameraFrame, cameraFrame, CV_8U, 1, 0); //sobel processing
        imshow("Processing", cameraFrame);

        if (waitKey(30) >= 0)
            break;
    }

    destroyAllWindows();
    return 0;
}