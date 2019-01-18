#include<opencv2/core.hpp>
#include<iostream>
#include<opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
		Mat img = imread("sysu.jpeg");
		namedWindow("SYSU");
		imshow("SYSU",img);
		waitKey(10000);
		cout << "HELLO";
		return 0;
}


