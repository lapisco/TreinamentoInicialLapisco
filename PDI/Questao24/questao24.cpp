//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"
//#include "pdi.h"

using namespace cv;
using namespace std;


 Mat_<Vec3b> color = imread("entrada.jpg",1);
 Mat_<uchar> grow (color.rows, color.cols, 1);

void mouseEvent (int evt, int x, int y, int flags, void* param)
{
    if (evt==CV_EVENT_LBUTTONDOWN)
    {
		grow.at<uchar>(y,x) = 255;
    }
}


int main()
 {
	
	int x,y;
	 int ca=0,cd=1;

	
	 //Mat grow (240, 320,CV_8UC3);;
	 //cvtColor(entrada,grow,CV_RGB2GRAY);

	 
	 for(y=0;y<grow.rows;y++)
	 {
		 for(x=0;x<grow.cols;x++)
		 {
			 grow.at<uchar>(y,x) = 0;
		 }
	 }

	namedWindow ("IMAGE_GRAY", 1); 
	imshow ("IMAGE_GRAY", color);
	setMouseCallback ("IMAGE_GRAY", mouseEvent, 0);
    waitKey(0);
    destroyWindow ("IMAGE_GRAY");
	
	 /*val_b=color(y,x)[0];
	 val_r=color(y,x)[2];
	 val_g=color(y,x)[1];*/




	 while(ca!=cd)
	 {
		 ca=cd;
		 for(y=0;y<grow.rows;y++)
		 {
			 for(x=0;x<grow.cols;x++)
			 {
				 if(grow.at<uchar>(y,x) == 255)
				 {

					if(color.at<Vec3b>(y-1, x-1)[0] > 200 && color.at<Vec3b>(y-1, x-1)[1] > 127 && color.at<Vec3b>(y-1, x-1)[2] >127 && grow.at<uchar>(y-1,x-1) != 255)
					{
						grow.at<uchar>(y-1,x-1)=255;
						cd++;
					}
					if(color.at<Vec3b>(y-1, x)[0] > 127 && color.at<Vec3b>(y-1, x)[1] > 127 && color.at<Vec3b>(y-1, x)[2] >127 && grow.at<uchar>(y-1,x)!= 255)
					{
						grow.at<uchar>(y-1,x)=255;
						cd++;
					}
					if(color.at<Vec3b>(y-1, x+1)[0] > 127 && color.at<Vec3b>(y-1, x+1)[1] > 127 && color.at<Vec3b>(y-1, x+1)[2] >127 && grow.at<uchar>(y-1,x+1) != 255)
					{
						grow.at<uchar>(y-1,x+1)=255;
						cd++;
					}
					if(color.at<Vec3b>(y, x-1)[0] > 127 && color.at<Vec3b>(y, x-1)[1] > 127 && color.at<Vec3b>(y, x-1)[2] >127 && grow.at<uchar>(y,x-1)!= 255)
					{
						grow.at<uchar>(y,x-1)=255;
						cd++;
					}
					if(color.at<Vec3b>(y, x+1)[0] > 127 && color.at<Vec3b>(y, x+1)[1] > 127 && color.at<Vec3b>(y, x+1)[2] >127 && grow.at<uchar>(y,x+1)!= 255)
					{
						grow.at<uchar>(y,x+1)=255;
						cd++;
					}
					if(color.at<Vec3b>(y+1, x-1)[0] > 127 && color.at<Vec3b>(y+1, x-1)[1] > 127 && color.at<Vec3b>(y+1, x-1)[2] >127 && grow.at<uchar>(y+1,x-1)!= 255)
					{
						grow.at<uchar>(y+1,x-1)=255;
						cd++;
					}
					if(color.at<Vec3b>(y+1, x)[0] > 127 && color.at<Vec3b>(y+1, x)[1] > 127 && color.at<Vec3b>(y+1, x)[2] >127 && grow.at<uchar>(y+1,x)!= 255)
					{
						grow.at<uchar>(y+1,x)=255;
						cd++;
					}
					if(color.at<Vec3b>(y+1, x+1)[0] > 127 && color.at<Vec3b>(y+1, x+1)[1] > 127 && color.at<Vec3b>(y+1, x+1)[2] >127 && grow.at<uchar>(y+1,x+1)!= 255)
					{
						grow.at<uchar>(y+1,x+1)=255;
						cd++;
					}
				}
			 }
		 }
		 imshow("Grow-region",grow);
		 waitKey(30);
	 }
	 
	 //imwrite("Grow-region.jpg",grow);
	 waitKey(0);

	 return 0;
}