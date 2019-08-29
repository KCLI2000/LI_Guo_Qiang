#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void CANNY(Mat img)
{
		Mat edge;
		Canny(img, edge, 3, 9, 3);

		imshow("canny", edge);
		return;
}

void SOBEL(Mat img)
{
		Mat grad_x, grad_y;
		Mat abs_grad_x, abs_grad_y, dst;

		Sobel(img, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
		convertScaleAbs(grad_x, abs_grad_x);
		imshow("x s", abs_grad_x);

		Sobel(img, grad_y, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
		convertScaleAbs(grad_y, abs_grad_y);
		imshow("y s", abs_grad_y);
		
		addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
		imshow("c s", dst);

		return;
}

void LAPLACIAN(Mat img)
{
		Mat dst, abs_dst;
		
		Laplacian(img, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);

		convertScaleAbs(dst, abs_dst);
		imshow("laplace", abs_dst);

		return;
}

int main(int argc, char* argv[])
{
		Mat img = imread(argv[1],1);

		if (argc != 2 || img.empty())
		{
				cerr << "NO IMAGE LOADED" << endl;
				return -1;
		}

		cvtColor(img, img, CV_RGB2GRAY);
		threshold(img, img, 30, 200, CV_THRESH_BINARY);

		CANNY(img);
		SOBEL(img);
		LAPLACIAN(img);

		waitKey(0);
		return 0;
}

