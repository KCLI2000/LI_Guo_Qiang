#include<iostream>
#include<stdio.h>
#include<opencv2/opencv.hpp>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
		Mat origin = imread("sysu.jpeg");
		Mat gray, bin, binori;

		cvtColor(origin, gray, CV_RGB2GRAY);
		threshold(gray, bin, 120, 255, CV_THRESH_BINARY);
		
		bin.copyTo(binori);

		vector<vector<Point>> contours;
		vector<Vec4i>hierarchy;

		findContours(bin, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
		bin = Scalar::all(0);
		drawContours(bin, contours, -1, Scalar(255, 255, 255));
	
		imwrite("original.jpeg", origin);
		imwrite("binary_original.jpeg", binori);
		imwrite("contours.jpeg", bin);

		waitKey(0);
		return 0;
}

		
