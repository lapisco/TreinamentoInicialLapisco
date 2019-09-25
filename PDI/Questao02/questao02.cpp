//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

int main()
{
     Mat img = imread ("teste.jpg", 1);
	 Mat img_gray;
	 cvtColor (img, img_gray, CV_BGR2GRAY);
	 imshow ("IMAGE", img_gray);
	 imwrite ("teste_filtro.jpg", img_gray);
	 waitKey(0);
	 return 0;
}
  
