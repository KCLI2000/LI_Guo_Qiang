#include<iostream>
#include<stdio.h>
#include<opencv2/opencv.hpp>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argc, char **argv[])
{
		Mat origin = imread("salted.jpeg");
		if(origin.empty())
		{
				cout << "LOAD IMAGE FAILURE" << endl;
				return -1;
		}

		Mat medium;
		//origin.copyTo(medium);
		medianBlur(origin, medium, 3);
		imshow("medium", medium);
		imwrite("median.jpeg", medium);
		waitKey(0);
		return 0;
}
