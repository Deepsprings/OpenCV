#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
#define pi 3.1415926
const int h=12, w=12;
int n=0;

Mat Gray(Mat img){
	cout << img.size();
	Mat out = Mat::zeros(img.size(),CV_8UC1);

	for(int x=0; x<img.rows; x++){
		for(int y=0; y<img.cols; y++){
			out.at<uchar>(x,y) = (int)((float)img.at<Vec3b>(x,y)[0]*0.0722+(float)img.at<Vec3b>(x,y)[1]*0.7152+(float)img.at<Vec3b>(x,y)[0]*0.2126);
		}
	}
	return out;
}

struct fourier{
	complex<double> coef[h][w];
};
fourier s;

void dft(Mat img, fourier &){
	double I, theta;
	complex<double> val;
	
	for(int k=0; k<h; k++){
		for(int l=0; l<w; l++){
			val = 0;
			for(int i=0; i<h; i++){
				for(int j=0; j<w; j++){
				I = img.at<uchar>(i,j);
				theta = -2*pi*((double)k*(double)i/(double)w + (double)l*(double)j/(double)h);
				val += I*complex<double>(cos(theta),sin(theta));
				}
			}
		s.coef[k][l] = val/sqrt(w*h);

		cout << ++n << endl;
		}
	}
}



int main(){
	Mat img = imread("/home/zhangwei/imori.jpg");
	if(img.empty()){
		cout << "Can't load img!" << endl;
		return -1;
	}

	Mat gray = Gray(img);
	Mat out = Mat::zeros(img.size(),CV_8UC1);
	dft(img,s);
	for(int k=0; k<h; k++){
		for(int l=0; l<w; l++){
			out.at<double>(k,l) = abs(s.coef[k][l]);	
}}

	imshow("out",out);
	imshow("pic", img);
	waitKey(0);
	return 0;
}
