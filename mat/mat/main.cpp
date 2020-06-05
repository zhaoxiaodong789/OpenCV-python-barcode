#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	
	Mat src = imread("C:/Users/xiaodong/Desktop/opencv/123.jpg");
	//Mat dst = Mat(src.size(), src.type());
	//dst = Scalar(0, 255, 255);
	
	//Mat dst;
	//src.copyTo(dst);

	Mat dst = src.clone();
	cvtColor(src, dst, CV_BGR2GRAY);

	printf("src channel: %d\n", src.channels());
	printf("dst channel: %d\n", dst.channels());

	if (!src.data) {
		printf("error\n");
		return -1;
	}
	const uchar* f1 = src.ptr<uchar>(0);
	const uchar* f2 = dst.ptr<uchar>(0);

	Mat m1= Mat(300, 300, CV_8UC3, Scalar(0, 255, 255));
	//cout << "M:" << endl << m1 << endl;
	
	Mat m2;
	m2.create(src.size(), src.type());
	m2 = Scalar(0, 255, 255);

	Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dst, -1, kernel);

	printf("src ptr: %d\n", *f1);
	printf("dst ptr: %d\n", *f2);
	printf("src row: %d, col: %d\n", src.rows, src.cols);
	printf("dst row: %d, col: %d\n", dst.rows, dst.cols);
	namedWindow("src1", CV_WINDOW_AUTOSIZE);
	imshow("src1",m2);
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);
	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	imshow("dst", dst);
	waitKey(0);


	
	
	
	
	return 0;
}