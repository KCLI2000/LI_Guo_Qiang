#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <stdio.h>

using namespace std;
using namespace cv;

void salt(Mat &image, int n)
{
		for(int k=0; k<n; k++)
		{
				int i=rand()%image.cols;
				int j=rand()%image.rows;
				
				if(image.channels() == 1)
				{
						image.at<uchar>(j,i)=255;
				}
				else if(image.channels() == 3)
				{
						image.at<Vec3b>(j,i)[0]=0;
						image.at<Vec3b>(j,i)[1]=0;
						image.at<Vec3b>(j,i)[2]=0;
				}
		}
}

int main(int argc, char **argv[])
{
		Mat origin;
		origin = imread("sysu.jpeg");
		
		if(origin.empty())
		{
				cout << "LOAD IMAGE FAILURE" << endl;
				return -1;
		}

		Mat salted;
		origin.copyTo(salted);
		salt(salted,3000);
		imshow("SALTED",salted);
		imwrite("salted.jpeg",salted);
		waitKey(0);
		return 0;
}
