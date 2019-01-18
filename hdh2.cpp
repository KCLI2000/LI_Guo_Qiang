#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
		Mat src;
		Mat src_gray;
		
		Mat image = imread("/home/kcli/G++project/sysu.jpeg");

		Mat grayImage;
		cvtColor(image, grayImage, COLOR_RGB2GRAY);

		imshow("shili", grayImage);
        imwrite("hdhsysu.jpeg",grayImage,src_gray);

		waitKey(0);
		return 0;

}


