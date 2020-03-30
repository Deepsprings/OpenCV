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
			gray.at<uchar>(i,j) = 0.2126*red + 0.7152*green + 0.0722*blue;		
		}
	}
	imshow("pic", gray);
	waitKey(0);
	return 0;
}
