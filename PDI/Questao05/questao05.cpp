//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

int main()
 {
     Mat img = imread ("image.jpg", 1);
	 Mat gray;
	 Mat media;
	 Mat mediana;

	 cvtColor (img, gray, CV_RGB2GRAY);

	 medianBlur (gray, media, 5);

	 imshow ("Original", img);

	 imshow ("Media", media);

	 imwrite ("media.jpg", media);
	 waitKey(0);
	 return 0;
}
  
