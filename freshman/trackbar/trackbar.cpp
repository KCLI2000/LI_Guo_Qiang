#include<stdio.h>
#include<math.h>
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/***************定义回调函数*************/
void on_trackbar(int pos, void *data)
{

		Mat srcImage = *(Mat*)(data);  //强制类型转换
		Mat dstImage;  

		threshold(srcImage, dstImage, pos, 255, 0);  //二值化
		imshow("threshold", dstImage);
}

int main(int argc, char* argv[])
{
		Mat srcImage = imread("666.jpeg");  //读入数据

		/****判断图片是否读入成功****/
		if (srcImage.empty())
		{
				cout << "LOAD IMAGE FAILURE" << endl;
				return -1;
		}
		
		Mat Gray;
		cvtColor(srcImage, Gray, CV_RGB2GRAY);//灰度化
		namedWindow("threshold");
		imshow("threshold", Gray);

		createTrackbar("pos", "threshold", 0, 255, on_trackbar, &Gray);
		waitKey(0);
		return 0;
}
