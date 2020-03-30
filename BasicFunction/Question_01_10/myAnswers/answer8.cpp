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
	
	int x = 8, y=8;
	int x0 =0, y0=0;

	for(x0=0; x0<img.rows; x0+=x){
	for(y0=0; y0<img.cols; y0+=y){
	double s1=0,s2=0,s3=0;

	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			int red = img.at<Vec3b>(x0+i,y0+j)[2];
			s1 = s1>red ? s1 : red;	
			int green = img.at<Vec3b>(x0+i,y0+j)[1];
			s2 = s2>green ? s2 : green;
			int blue = img.at<Vec3b>(x0+i,y0+j)[0];
			s3 = s3>blue ? s3 : blue;
		}
	}
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			img.at<Vec3b>(x0+i,y0+j)[2] = s1;
			img.at<Vec3b>(x0+i,y0+j)[1] = s2;
			img.at<Vec3b>(x0+i,y0+j)[0] = s3;
		}
	}
	}}
	
	imshow("pic", img);
	waitKey(0);
	return 0;
}
