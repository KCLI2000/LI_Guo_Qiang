/***********************************
 *Author:Ken李国锵
 *Date: 2019/1/22
 *Abstarct: Examples of using function cornerHarris()
 *
 *Reference:[Opencv] http://doc.opencv.org/3.1.0/d4/d7d/tutorial_harris_detector.html
 ***********************************/
#include<iostream>
#include<stdio.h>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//Global var
Mat src, gray;
int thresh = 200;
int maxt = 255;

/* Function Header*/
void cornerHarris_demo(int ,void*);


int main(int argc, char* argv[])
{
		src = imread(argv[1], 1);

		if(src.empty())
		{
				cerr << "NO IMAGE LOADED" << endl;
				return -1;
		}

		cvtColor(src, gray, CV_BGR2GRAY);
	
		namedWindow("Source image", CV_WINDOW_AUTOSIZE);
		createTrackbar("Threshold:", "Source image", &thresh, maxt, cornerHarris_demo);

		imshow("Source image", src);
		cornerHarris_demo(0,0);

		waitKey(0);
		return 0;
}

void cornerHarris_demo(int, void*)
{
		Mat dst, norm, scaled;
		dst = Mat::zeros(src.size(), CV_32FC1);

		int blocksize = 2;
		int aperturesize = 3;
		double k = 0.04;

		cornerHarris(gray, dst, blocksize, aperturesize, k, BORDER_DEFAULT);

		normalize(dst, norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
		convertScaleAbs(norm, scaled);

		for(int j=0; j<norm.rows; j++)
		{
				for(int i=0; i<norm.cols; i++)
				{
						if((int) norm.at<float>(j,i) > thresh)
						{
								circle(scaled, Point(i,j), 5, Scalar(0), 2, 8, 0);
						}
				}
		}
		namedWindow("Corners detected", WINDOW_AUTOSIZE);
		imshow("Corners detected", scaled);

		return;
}
