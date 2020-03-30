#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
#define pi 3.1415926


int main(){
	Mat img = imread("/home/zhangwei/imori.jpg");
	if(img.empty()){
		cout << "Can't load img!" << endl;
		return -1;
	}
	float times = 1.5;
	int row = img.rows;
	int col = img.cols;
	int channel = img.channels();
	Mat out = Mat::zeros(Size(times*row,times*col),img.type());

	for(float i=0; i<row*times; i++){
		for(float j=0; j<col*times; j++){
			for(float k=0; k<channel; k++){
				out.at<Vec3b>(i,j)[k] = img.at<Vec3b>(floor(i/times),floor(j/times))[k];
			}
		}
	}

	imshow("out",out);
	imshow("pic", img);
	waitKey(0);
	return 0;
}
