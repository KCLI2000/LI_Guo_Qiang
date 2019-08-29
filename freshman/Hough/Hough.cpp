#include<stdio.h>
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat gsrc, gdst, gmid;
vector<Vec4i> glines;
int gthreshold = 100;

static void on_HoughLines(int, void*)
{

		Mat dst = gdst.clone();
		Mat mid = gmid.clone();

		vector<Vec4i> mylines;
		HoughLinesP(mid, mylines, 1, CV_PI / 180, gthreshold + 1, 50, 10);

		for(size_t i=0; i<mylines.size();i++)
		{
				Vec4i l = mylines[i];
				line(dst, Point(l[0],l[1]), Point(l[2],l[3]), Scalar(23,180,55), 1, CV_AA);
		}

		imshow("image",dst);
}

int main(int argc, char* argv[])
{
		Mat gsrc = imread(argv[1],1);
		
		if(gsrc.empty())
		{
				cerr << "NO IMAGE LOAD" << endl;
				return -1;
		}
		
		namedWindow("img", 1);
		createTrackbar("value", "img", &gthreshold, 200, on_HoughLines);

		Canny(gsrc, gmid, 50, 200, 3);
		cvtColor(gmid, gdst, CV_GRAY2BGR);

		on_HoughLines(gthreshold, 0);
		HoughLinesP(gmid, glines, 1, CV_PI / 180, 80, 50, 10);

		imshow("img", gdst);
		waitKey(0);
		return 0;
}

