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




int main(){
	Mat img = imread("/home/zhangwei/imori.jpg");
	if(img.empty()){
		cout << "Can't load img!" << endl;
		return -1;
	}

	Mat img2 = imread("/home/zhangwei/thorino.jpg");
	//cout << img.data << endl;
	Mat out(Size(3,3),CV_8UC3,Scalar(0,100,255));
//	cout << out << endl;
	cout << out.data << endl;

	imshow("pic", out);
	waitKey(0);
	return 0;
}
