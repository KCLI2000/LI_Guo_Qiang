#include<stdio.h>
#include<iostream>
#include<opencv2/opencv.hpp>
#include<stdlib.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
		Mat origin = imread("salted.jpeg");

		if(origin.empty())
		{
				cout << "LOAD IMAGE FAILURE" << endl;
				return -1;
		}
		
		Mat bilat;

		bilateralFilter(origin, bilat, 200, 200, 200);
		imshow("bilat", bilat);
		//imwrite("bilat.jpeg", bilat);

		waitKey(0);
		return 0;
}

