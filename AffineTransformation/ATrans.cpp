#include<stdio.h>
#include<iostream>
#include<opencv2/opencv.hpp>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
		Mat origin = imread("sysu.jpeg");
		
		if(origin.empty())
		{
				cout << "LOAD IMAGE FAILURE" << endl;
				return -1;
		}

		Mat aft;

		Point2f AffinePoints0[3] = { Point2f(100, 50), Point2f(100, 390), Point2f(600, 50) };
		Point2f AffinePoints1[3] = { Point2f(200, 100), Point2f(200, 300), Point2f(500, 50) };

		Mat Trans = getAffineTransform(AffinePoints0, AffinePoints1);
		warpAffine(origin, aft, Trans, Size(origin.cols, origin.rows));

		imshow("origin", origin);
		imshow("aft", aft);

		waitKey(0);
		return 0;
}
