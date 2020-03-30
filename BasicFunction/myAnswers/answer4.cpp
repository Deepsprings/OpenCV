#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(){
	Mat img = imread("/home/zhangwei/imori.jpg");
	if(img.empty()){
		cout << "Can't load img!" << endl;
		return -1;
	}
	
	Mat gray = Mat::zeros(img.size(), CV_8UC1);
	for(int i=0; i<img.rows; i++){
		for(int j=0; j<img.cols; j++){
			float red = img.at<Vec3b>(i,j)[2];
			float green = img.at<Vec3b>(i,j)[1];
			float blue = img.at<Vec3b>(i,j)[0];
			int b= 0.2126*red + 0.7152*green + 0.0722*blue;		
			gray.at<uchar>(i,j) = b; 	
		}
	}
	int max = 0, th;
	for(int k=0; k<255; k++){
		int a=0,b=0,s1=0,s2=0;
		for(int i=0; i<img.rows; i++){
			for(int j=0; j<img.cols; j++){
				if(gray.at<uchar>(i,j)<k) {a++; s1+=gray.at<uchar>(i,j);}
				else {b++; s2+=gray.at<uchar>(i,j);}
			}
		}
		float w0 = float(a)/(a+b);
		float w1 = float(b)/(a+b);
		float m0 = float(s1)/a;
		float m1 = float(s2)/b;
		float ans = w0*w1*pow((m0-m1),2);
		if(ans > max){
			max = ans;
			th = k;
		}
	}
	cout << "th=" << th << endl;

	imshow("pic", gray);
	waitKey(0);
	return 0;
}
