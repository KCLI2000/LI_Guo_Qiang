#include<stdio.h>
#include<math.h>
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void on_trackbar(int pos, void *data)
{

		Mat srcImage = *(Mat*)(data);
		Mat dstImage;

		threshold(srcImage, dstImage, pos, 255, 0);
		imshow("threshold", dstImage);
}

int main(int argc, char* argv[])
{
		Mat srcImage = imread("666.jpeg");
		if (srcImage.empty())
		{
				cout << "LOAD IMAGE FAILURE" << endl;
				return -1;
		}

		Mat Gray;
		cvtColor(srcImage, Gray, CV_RGB2GRAY);
		namedWindow("threshold");
		imshow("threshold", Gray);

		createTrackbar("pos", "threshold", 0, 255, on_trackbar, &Gray);
		waitKey(0);
		return 0;
}
