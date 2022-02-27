/* Mat Ŭ���� : ��� ���� ǥ���ϴ� n������ ��� Ŭ����. �پ��� ���ڸ� �޵��� �����ڰ� �����ε� �Ǿ��ִ�.

1. ���� ���� �����ڴ�
Mat::Mat(int rows, int cols, int type)
Mat::Mat(Size size, int type)

2. �ٸ� �̹���(Mat)�� �Ϻθ� �����ͼ� �����ϴ�(������ ���� ����?) �����ڵ� �ִµ�, �⺻������ Mat�� ������ �����´�.
��, �������� ���ڸ� ���纻�� �ƴ϶� ��������(����) �������� ��찡 ����. ���� ���纻�� ����ʹٸ� copy�� ����Ѵ�.


3. ��Ģ������� �����(pseudo-inversion ��), �� ���� ����ϴ� Mat expression�� �����Ѵ�.


4. ���ڷ� �ִ� type�� ��ũ�� ���ǵǾ��ִ�.

#define CV_8U   0
#define CV_8S   1
#define CV_16U  2
#define CV_16S  3
#define CV_32S  4
#define CV_32F  5
#define CV_64F  6
#define CV_16F  7


#define CV_32FC1 CV_MAKETYPE(CV_32F,1)           32��Ʈ float, channel 1��.
#define CV_32FC2 CV_MAKETYPE(CV_32F,2)
#define CV_32FC3 CV_MAKETYPE(CV_32F,3)
#define CV_32FC4 CV_MAKETYPE(CV_32F,4)
#define CV_32FC(n) CV_MAKETYPE(CV_32F,(n))

#define CV_64FC1 CV_MAKETYPE(CV_64F,1)
#define CV_64FC2 CV_MAKETYPE(CV_64F,2)
#define CV_64FC3 CV_MAKETYPE(CV_64F,3)
#define CV_64FC4 CV_MAKETYPE(CV_64F,4)
#define CV_64FC(n) CV_MAKETYPE(CV_64F,(n))


*/
