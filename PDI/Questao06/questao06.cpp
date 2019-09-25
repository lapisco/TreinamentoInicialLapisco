#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

int main()
 {
    Mat img = imread ("teste.jpg");
	Mat img_gray;
	Mat img_filter;
	cvtColor (img, img_gray, CV_BGR2GRAY);
	imshow ("IMAGE", img_gray);
	Canny (img_gray, img_filter, 120, 100, 3);

	imshow ("IMAGEM COM FILTRO", img_filter);
    cvWaitKey(0);
 }
  
