#include<stdio.h>
#include<iostream>
#include<opencv2/opencv.hpp>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv[])
{
		Mat origin = imread("salted.jpeg");

		if(origin.empty())
		{
				cout << "LOAD IMAGE FAILURE" << endl;
				return -1;
		}

		Mat bluri;
		blur(origin, bluri, Size(10,10), Point(-1,-1));
		imshow("bluri.jpeg", bluri);
		imwrite("bluri.jpeg", bluri);

		waitKey(0);
		return 0;
}

