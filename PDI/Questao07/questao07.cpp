//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

int main()
 {
	 Mat img = imread ("teste.jpg");
	 Mat gray;
	 Mat thresh1;
	 Mat thresh2;
	 Mat thresh3;
	 Mat thresh4;
	 Mat thresh5;

	 cvtColor (img, gray, CV_RGB2GRAY);

	 threshold (gray, thresh1, 127, 255, CV_THRESH_BINARY);
	 threshold (gray, thresh2, 127, 255, CV_THRESH_BINARY_INV);
	 threshold (gray, thresh3, 127, 255, CV_THRESH_TRUNC);
	 threshold (gray, thresh4, 127, 255, CV_THRESH_TOZERO);
	 threshold (gray, thresh5, 127, 255, CV_THRESH_TOZERO_INV);

	 imshow ("IMAGE 1", thresh1);
	 imshow ("IMAGE 2", thresh2);
	 imshow ("IMAGE 3", thresh3);
	 imshow ("IMAGE 4", thresh4);
	 imshow ("IMAGE 5", thresh5);

	/* imwrite ("teste1.jpg", thresh1);
	 imwrite ("teste2.jpg", thresh2);
	 imwrite ("teste3.jpg", thresh3);
	 imwrite ("teste4.jpg", thresh4);
	 imwrite ("teste5.jpg", thresh5);
	 */
     cvWaitKey(0);
	 return 0;
 }
  
