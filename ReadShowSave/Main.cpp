#include <iostream>
#include <opencv2\opencv.hpp>
using namespace std;
using namespace cv;
const char * source_window = "source";
const char* canny_window = "canny";
int main() {
	Mat source = imread("fifth.jpg", 1);
	Mat temp(source.rows, source.cols, CV_8UC1);
	cvtColor(source, temp, COLOR_BGR2GRAY);
	Canny(temp, temp, 50, 200);
	imwrite("fifth_canny.jpg", temp);
	cvNamedWindow(source_window);
	cvNamedWindow(canny_window);
	imshow(source_window, source);
	imshow(canny_window, temp);
	waitKey(0);
	cvDestroyWindow(source_window);
	cvDestroyWindow(canny_window);
	return 0;
}