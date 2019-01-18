// QR CODE
// QR_DETECT.hpp
//


#ifndef QR_detect.hpp
#define QR_detect.hpp

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
using namespace cv;

class QR_detecter{
private:
		bool compare_sample(Mat &roi);
		bool isXCorner(Mat &image);
		bool isYCorner(Mat &image);
		Mat transformCorner(Mat &image, RotatedRect &rect);
		Mat output;
public:
		QR_detecter(){

		}
		void detect(Mat &src);
		void showCorners(double time);
};

#endif /* QR_detect_hpp*/

