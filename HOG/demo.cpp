#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace std;
using namespace cv;

int main(){

/* step1: preprocessing */
	// Read image
	Mat img = imread("/home/zhangwei/workfiles/git/OpenCV/HOG/test.jpg");
	int width = img.cols;
	int height = img.rows;
	int channel = img.channels();
	cout << img.type() << endl << channel << endl;
	if(! img.data){
		cout << "fail to load img" << endl;
		return 0;
	}
	// crop
	Rect rect(550, 110, 160, 420);
	//rectangle(img , rect, Scalar(255,0,0), 1, LINE_8, 0);
	Mat crop(img, rect);
	// resize
	resize(crop, crop, Size(64,128), INTER_NEAREST);


/* Calculate gradient */
	// gx gy
	Mat gx, gy;
	Sobel(crop, gx, CV_32F, 1, 0, 1);
	Sobel(crop, gy, CV_32F, 0, 1, 1);
	
	// mag, angle
	Mat mag, angle;
	gx.convertTo(gx, CV_8U);
	resize(gx, gx, Size(0,0), 3,3, INTER_NEAREST);

	imshow("img", gx);
	waitKey(0);

	return 0;
}

