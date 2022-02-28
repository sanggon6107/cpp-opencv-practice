#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*
1.
Mat clone() const;
2.
void copyTo(OutputArray m) const;
3.
void copyTo(OutputArray m, InputArray mask) const;
4.
void convertTo(OutputArray m, int rtype, double alpha = 1, double beta = 0) const;
5.
void assignTo(Mat& m, int type = -1) const;
6.
Mat& operator= (const Scalar& s);
7.
Mat& setTo(InputArray value, InputArray mast = noArray());
8.
Mat reshape(int cn, int rows = 0) const;
*/


int main()
{
	// 1.
	Mat mat1(Matx33f(1, 2, 3, 4, 5, 6, 7, 8, 9));
	cout << "mat1 : " << endl
		<< mat1 << endl;

	// 1. 
	Mat mat2 = mat1.clone();
	cout << "mat2 : " << endl
		<< mat2 << endl;
	// 2.
	Mat mat3;
	mat1.copyTo(mat3);
	cout << "mat3 : " << endl
		<< mat3 << endl;

	mat1.at<float>(1, 1) = 100;
	mat2.at<float>(0, 0) = 101;
	mat3.at<float>(2, 2) = 300;

	// 2�� ��� ��� ���纻�� ���´�.(���� �ƴ�)
	cout << endl
		<< mat1 << endl
		<< mat2 << endl
		<< mat3 << endl
		<< endl;
	// 2-1.
	Mat mat4;
	mat1.row(1).copyTo(mat4);
	cout << "mat4 : mat1.row(1).copyTo(mat4)" << endl
		<< mat4 << endl;

	// mask�� 7 ����.
	Mat mask1(3, 3, CV_8U, Scalar(0));
	mask1.row(1).setTo(Scalar::all(1));
	cout << "mask1 : " << endl
		<< mask1 << endl;

	// 3. copyTo�� mask �����.
	Mat mat5;
	mat1.copyTo(mat5, mask1);
	cout << "mat5 : mat1.copyTo(mat5)" << endl
		<< mat5 << endl;

	// 4. convetTo
	Mat mat6;
	mat1.convertTo(mat6, CV_8U);
	cout << "mat6 : " << endl
		<< mat6 << endl;

	Mat mat7;
	mat1.convertTo(mat7, CV_8U, 10.0, 1.0); // 10 ���ϰ� 1 ���Ѵ�?
	cout << "mat7 : " << endl
		<< mat7 << endl;

	// 5.
	Mat mat8;
	mat1.assignTo(mat8, CV_8U); // Ÿ�Ը� �ٲٰ� ���� ��. Ÿ�� �Է����� ������ �׳� copy�� �Ѵ�.
	cout << "mat8 : " << endl   // convetTo�� ���� �� �ƴѰ�?
		<< mat8 << endl;

	// 7.
	Mat mat9(Matx33d(1, 2, 3, 4, 5, 6, 7, 8, 9));
	
	mat9.setTo(Scalar::all(0), mat9 < 5); // 5���� ���� ���ҿ� ���� 0���� �ٲ۴�.
	cout << "mat9 : " << endl
		<< mat9 << endl;

	// 8. ����� ��ġ�� �ٲ��ش�. ù ��° ���ڴ� ä���̴�. �� ��° ���ڴ� row�̴�.
	Mat mat10(Matx33d(1, 2, 3, 4, 5, 6, 7, 8, 9));
	Mat mat11 = mat10.reshape(0, 1);
	cout << "mat11 : " << endl
		<< mat11 << endl;
	mat11 = mat10.reshape(0, 9);
	cout << "mat11 : " << endl
		<< mat11 << endl;
	mat11 = mat10.reshape(3, 3);
	cout << "mat11 : " << endl
		<< mat11 << endl;
	
}