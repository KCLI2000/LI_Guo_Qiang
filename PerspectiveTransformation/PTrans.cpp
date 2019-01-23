/* Perspective Transformation
 * 透视变换
 * *EXAMPLE*
 * Date:2019/1/22
 */

#include<iostream>
#include<opencv2/opencv.hpp>
#include<stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
		Mat src, dst;
		src = imread("test.png");

		if(src.empty())
		{
				cerr << "NO IMAGE LOADED" << endl;
				return -1;
		}

		Point2f objPoint[4];
		Point2f imgPoint[4];

		imgPoint[0].x = 10.0; imgPoint[0].y = 457.0;
		imgPoint[1].x = 395.0; imgPoint[1].y = 291.0;
		imgPoint[2].x = 624.0; imgPoint[2].y = 291.0;
		imgPoint[3].x = 1000.0; imgPoint[3].y = 457.0;

		double moveValueX = 0.0;
		double moveValueY = 0.0;
		
		objPoint[0].x = 46.0 + moveValueX; imgPoint[0].y = 920.0 + moveValueY;
		objPoint[1].x = 46.0 + moveValueX; imgPoint[1].y = 100.0 + moveValueY;
		objPoint[2].x = 600.0 + moveValueX; imgPoint[2].y = 100.0 + moveValueY;
		objPoint[3].x = 600.0 + moveValueX; imgPoint[3].y = 920.0 + moveValueY;

		Mat transform = getPerspectiveTransform(objPoint, imgPoint);

		warpPerspective(src, dst, transform, Size(src.rows, src.cols), INTER_LINEAR);

		imshow("dst", dst);

		waitKey(0);
		return 0;
}
		
