/* Mat 클래스 : 모든 것을 표현하는 n차원의 행렬 클래스. 다양한 인자를 받도록 생성자가 오버로딩 되어있다.

1. 가장 쉬운 생성자는
Mat::Mat(int rows, int cols, int type)
Mat::Mat(Size size, int type)

2. 다른 이미지(Mat)의 일부만 가져와서 생성하는(일종의 복사 생성?) 생성자도 있는데, 기본적으로 Mat은 참조로 가져온다.
즉, 생성자의 인자를 복사본이 아니라 원본으로(참조) 가져오는 경우가 많다. 만약 복사본을 쓰고싶다면 copy를 써야한다.


3. 사칙연산부터 역행렬(pseudo-inversion 등), 비교 등을 계산하는 Mat expression을 제공한다.


4. 인자로 넣는 type은 매크로 정의되어있다.

#define CV_8U   0
#define CV_8S   1
#define CV_16U  2
#define CV_16S  3
#define CV_32S  4
#define CV_32F  5
#define CV_64F  6
#define CV_16F  7


#define CV_32FC1 CV_MAKETYPE(CV_32F,1)           32비트 float, channel 1개.
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
