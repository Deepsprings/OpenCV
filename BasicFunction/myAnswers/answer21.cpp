#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
#define pi 3.1415926


int main(){
	Mat img = imread("/home/zhangwei/imori_dark.jpg");
	if(img.empty()){
		cout << "Can't load img!" << endl;
		return -1;
	}
	Mat out = img.clone();	
	int c = img.at<Vec3b>(0,0)[0];
	int d = c;
	for(int i=0; i<img.rows; i++){
		for(int j=0; j<img.cols; j++){
			for(int k=0; k<img.channels(); k++){
				c = c<img.at<Vec3b>(i,j)[k] ? c : img.at<Vec3b>(i,j)[k];
				d = d>img.at<Vec3b>(i,j)[k] ? d : img.at<Vec3b>(i,j)[k];  
			}
		}
	}
	cout << c << endl << d << endl;
	for(int i=0; i<img.rows; i++){
		for(int j=0; j<img.cols; j++){
			for(int k=0; k<img.channels(); k++){
				int val = img.at<Vec3b>(i,j)[k];
				if(val<c) img.at<Vec3b>(i,j)[k]=0;
				else if(val<d) img.at<Vec3b>(i,j)[k]=(uchar)255/(d-c)*(val-c);
				else img.at<Vec3b>(i,j)[k]=255;
			}
		}
	}


	imshow("out",out);
	imshow("pic", img);
	waitKey(0);
	return 0;
}
