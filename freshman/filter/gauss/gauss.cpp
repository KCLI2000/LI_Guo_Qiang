#include<iostream>
#include<stdio.h>
#include<math.h>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv[])
{
		Mat origin = imread("salted.jpeg");
		if(origin.empty())
		{
				cout << "LOAD IMAGE FAILURE" <<endl;
				return -1;
		}

		Mat g_img;
		GaussianBlur(origin, g_img, Size(3,3), 100);
		imshow("origin",origin);
		imshow("gauss",g_img);
		imwrite("gauss.jpeg", g_img);
		waitKey(0);
		return 0;
}
