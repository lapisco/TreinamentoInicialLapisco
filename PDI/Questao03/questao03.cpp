//Laborat�rio de Prot�tipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using  namespace cv;
using namespace std;

int main()
 {
     Mat img = imread ("image.jpg", 1);
	 /*Criar um vetor para os tres canais*/
	 Mat channel [3];
	 /*Fun��o para a divis�o dos canais*/
	 split (img, channel);  

	 imshow ("GREEN", channel[0]);
	 imshow ("BLUE", channel[1]);
	 imshow ("RED", channel[2]);

	 imwrite ("image_green.jpg", channel[0]);
	 imwrite ("image_blue.jpg", channel[1]);
	 imwrite ("image_red.jpg", channel[2]);

     cvWaitKey(0);
 }
  
