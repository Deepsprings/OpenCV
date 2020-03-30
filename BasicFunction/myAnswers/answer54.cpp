#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

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


vector<int> SSD(Mat img, Mat part){
	int a,b;
	int w = img.cols - part.cols;
	int h = img.rows - part.rows;
	int s,min=1000000;
	for(int i=0; i<w; i++){
	for(int j=0; j<h; j++){
		s  = 0 ;
		for(int x=0; x<part.rows; x++){
		for(int y=0; y<part.cols; y++){
			s += pow(img.at<uchar>(i+x,j+y)- part.at<uchar>(x,y),2);
		}
		}
		cout << i << " " << j << " " << s << endl;
		if(s<=min){
			min = s;
			a = i;
			b = j;
			cout << a << " " << b << endl;
		}
	}
	}
	return {a,b};
}



int main(){
	Mat img = imread("/home/zhangwei/imori.jpg");
	if(img.empty()){
		cout << "Can't load img!" << endl;
		return -1;
	}

	Mat part0 = imread("/home/zhangwei/imori_part.jpg");
	Mat part = Gray(part0);
	Mat gray = Gray(img);
	//Mat out = Mat::zeros(img.size(),img.type());
//	vector<int> p;
	int aa,bb;
	vector<int> re;
	re =	SSD(gray, part);
	aa = re[0];
	bb = re[1];
	cout << aa << " " << bb << endl;
	rectangle(img,Point(aa,bb),Point(aa+part.rows,bb+part.cols),Scalar(0,0,225),2);
	imshow("out",part);
	imshow("pic", img);
	waitKey(0);
	return 0;
}
