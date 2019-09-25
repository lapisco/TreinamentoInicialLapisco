//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

/*SEMPRE TEM QUE TER*/
using namespace std; 
using namespace cv;

int main()
 {
	 Mat img = cv::imread ("image.jpg", 1);
	 imshow ("IMAGE", img);
	 imwrite ("image-save.jpg", img);
     waitKey(0);
	 return 0;
 }
  
