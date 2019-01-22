#include<iostream>
#include<stdio.h>
#include<opencv2/opencv.hpp>
#include<math.h>

using namespace std;
using namespace cv;


/*void on_trackbar(int pos, void *data)
{
		Mat origin = *(Mat*)(data);

		threshold(origin, bin, pos, 255, 0);
		imshow("threshold", bin);
}
*/

int main(int argc, char* argv[])
{
		Mat origin = imread(argv[1],1);

		if(argc != 2 || origin.empty())
		{
				cerr << "LOAD IMAGE FAILED" << endl;
				return -1;
		}

		Mat gray, bin, binori;
		cvtColor(origin, gray, CV_RGB2GRAY);
		namedWindow("threshold");
		imshow("threshold", gray);

		threshold(gray, bin, 120, 255, CV_THRESH_BINARY);

		vector<vector<Point>> contours;
		vector<Vec4i>hierarchy;

		findContours(bin, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
		bin = Scalar::all(0);
		drawContours(bin, contours, -1, Scalar(255, 255, 255));
	
//		imwrite("original.jpeg", origin);
//		imwrite("binary_original.jpeg", binori);
//		imwrite("contours.jpeg", bin);

		imshow("original.jpeg", origin);
		imshow("binary_original.jpeg", binori);
		imshow("contours.jpeg", bin);

		waitKey(0);
		return 0;
}

		
