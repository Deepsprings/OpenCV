#include <iostream>
using namespace std;

int main(){
	Mat img;
	img.create(Size(3,3),Scalar(0,0,255));
	
	imshow("img",img);
	waitKey(0);
	
	return 0;
}
