//QRCODE DETECT
//QRT.CPP
//
//DATE:2019/1/18
//VERSION:1.0.0
//

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

bool isCorner(Mat &image);
Mat transformCorner(Mat &image, RotateRect &rect);

int main(int argc, char** argv)
{
		Mat src = imread('sample.jpeg');
		if (src.empty())
		{
				cout << "Load image failed" << endl;
				return -1;
		}
		namedWindow('input image', CV_WINDOW_AUTOSIZE);
		//imshow(input image', src);


		Mat gray, binary;
		
		cvtColor(src, gray, COLOR_BGR2GRAY);
		imwrite('gray.jpeg', gray);

		threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
		imwrite('bin.jpeg', binary);

		/***********************DETECT NOW**************************/

		vector<</span>vector<</span>Point>> contours;
		vector<</span>Vec4i> hireachy;

		Moments monents;
		findContours(binary.clone(), contours, hireachy, RETR_LIST, CHAIN_APPROX_SIMPLE, Point());
		
		

