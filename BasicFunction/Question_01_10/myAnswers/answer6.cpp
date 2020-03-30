#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int compress(int var){
	if(0<=var & var<64) return 32;
	if(64<=var & var<128) return 96;
	if(128<=var & var<192) return 160;
	if(192<=var & var<256) return 224;
}


int main(){
	Mat img = imread("/home/zhangwei/imori.jpg");
	if(img.empty()){
		cout << "Can't load img!" << endl;
		return -1;
	}
	
	for(int i=0; i<img.rows; i++){
		for(int j=0; j<img.cols; j++){
			int red = img.at<Vec3b>(i,j)[2];
			img.at<Vec3b>(i,j)[2] = compress(red);
			float green = img.at<Vec3b>(i,j)[1];
			img.at<Vec3b>(i,j)[1] = compress(green);
			float blue = img.at<Vec3b>(i,j)[0];
			img.at<Vec3b>(i,j)[0] = compress(blue);
		}
	}

	imshow("pic", img);
	waitKey(0);
	return 0;
}
