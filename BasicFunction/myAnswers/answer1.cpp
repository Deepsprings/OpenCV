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
	
	for(int i=0; i<img.rows; i++){
		for(int j=0; j<img.cols; j++){
			swap(img.at<Vec3b>(i,j)[0], img.at<Vec3b>(i,j)[2]);
		}
	}
	imshow("pic", img);
	waitKey(0);
	return 0;
}
