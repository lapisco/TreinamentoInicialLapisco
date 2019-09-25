//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

int main()
 {
     Mat img = imread ("teste.jpg", 1);
	 Mat HSV;
	 Mat channel [3];

	 cvtColor (img, HSV, CV_RGB2HSV);

	 imshow ("IMAGE", HSV);

	 split (HSV, channel);

	 imshow ("IMAGE (CHANNEL-0)", channel[0]);
	 imshow ("IMAGE (CHANNEL-1", channel[1]);
	 imshow ("IMAGE (CHANNEL-2", channel[2]);

	 imwrite ("teste1.jpg", HSV);
	 imwrite ("teste2.jpg", channel[0]);
	 imwrite ("teste3.jpg", channel[1]);
	 imwrite ("teste4.jpg", channel[2]);

     cvWaitKey(0);
 }
  
