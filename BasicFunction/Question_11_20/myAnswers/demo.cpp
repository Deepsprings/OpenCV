#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
#define pi 3.1415926

Mat GaussianFilter(Mat img, int size, double sig){
	float kenel[size][size];
	int pad = floor(size/2);
	double s;
	Mat out = Mat::zeros(img.size(),img.type());
	for(int x=0; x<size; x++){
		for(int y=0; y<size; y++){
			int _x = x -pad;
			int _y = y-pad;
			kenel[x][y] = exp(-(_x*_x+_y*_y)/(2*sig*sig))/(2*pi*sig*sig);
			s += kenel[x][y];
		}
	}
	for(int x=0; x<size; x++){
		for(int y=0; y<size; y++){
			kenel[x][y] /= s;
			cout << kenel[x][y] << " ";}
			cout << endl;
	}
	
	double sum;
	for(int x=0; x<img.rows; x++){
		for(int y=0; y<img.cols; y++){
			for(int z=0; z<img.channels(); z++){
			sum = 0;
			for(int i=-pad; i<pad+1; i++){
				for(int j=-pad; j<pad+1; j++){
				if((x+i)>=0 && (y+j)>=0 && (x+i)<=img.rows-1 && (y+j)<=img.cols)
				sum += (double)img.at<Vec3b>(x+i,y+j)[z]*kenel[i+pad][j+pad];
				}
			}
			out.at<Vec3b>(x,y)[z] = sum;
		}}
	}
	return out;
}


int main(){
	Mat img = imread("/home/zhangwei/imori.jpg");
	if(img.empty()){
		cout << "Can't load img!" << endl;
		return -1;
	}
	img = GaussianFilter(img, 3, 1.3);	

	imshow("pic", img);
	waitKey(0);
	return 0;
}
