#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;


/*

1. 
Mat getPerspectiveTransform(InputArray src, InputArray dst, int solveMethod = DECOMP_LU);

2. 
void warpPerspective( InputArray src, OutputArray dst,
								   InputArray M, Size dsize,
								   int flags = INTER_LINEAR,
								   int borderMode = BORDER_CONSTANT,
								   const Scalar& borderValue = Scalar());
*/

int main()
{
	Mat img = imread("lenna.png");
	std::vector<Point2f> points_vec_before = 
	{
			Point2f(0.0f, 0.0f),
			Point2f(0.0f, static_cast<float>(img.rows - 1)),
			Point2f(static_cast<float>(img.cols - 1), static_cast<float>(img.rows - 1)),
			Point2f(static_cast<float>(img.cols - 1), 0.0f)
	};

	std::vector<Point2f> points_vec_after =
	{
			Point2f(0.0f, 0.0f),
			Point2f(static_cast<float>(img.cols - 1)*0.3f, static_cast<float>(img.rows - 1)),
			Point2f(static_cast<float>(img.cols - 1)*0.7f, static_cast<float>(img.rows - 1)),
			Point2f(static_cast<float>(img.cols - 1), 0.0f)
	};

	Mat trans_mat = getPerspectiveTransform(points_vec_before, points_vec_after);
	Mat dst_img;
	warpPerspective(img, dst_img, trans_mat, Size(), INTER_LINEAR);
	

	imshow("dst_img", dst_img);

	waitKey(0);
	destroyAllWindows();
}