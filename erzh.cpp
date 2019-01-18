#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
		Mat img, imgGray, result;
		img = imread("sysu.jpeg");
		if(!img.data)
		{
				cout<<"ERROR"<<endl;
				return 0;
		}
		imshow("原图",img);
		cvtColor(img, imgGray, COLOR_RGB2GRAY);
		imshow("huidutu",imgGray);
		threshold(imgGray, result, 100,255, CV_THRESH_BINARY);
		imshow("erzhihua",result);
		imwrite("erzhihua.jpeg",result);
		cout<<"saved"<<endl;
		waitKey();

		return 0;
}

