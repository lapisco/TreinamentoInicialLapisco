//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

int main()
{
	Mat color = imread ("entrada.png");

	Mat gray;

	Mat image;

	cvtColor (color, gray, CV_RGB2GRAY);

	threshold (gray, gray, 127, 255, CV_THRESH_OTSU); // Aplicando a limiarização do tipo otsu 

	int i;

	int erosion_type;

	for (i = 0; i < 3; i++)
	{

		if (i == 0)
			erosion_type = MORPH_RECT;
		else if (i == 1)
			erosion_type = MORPH_CROSS;
		else if (i == 2)
			erosion_type = MORPH_ELLIPSE;
		Mat element = getStructuringElement (erosion_type, Size(3,1), Point( -1, -1 ) );

		/* Operacao do getStructuringElement
			 1- Forma: MORPH_CROSS, MORPH_RECT, MORPH_ELLIPSE, CV_SHAPE_CUSTOM
			 2- Tamanho
			 3- Para a posição dentro do elemento, (-1,-1) signifiga que tá no centro do elemento */
		// Aplicar a operação erode

		erode (gray, image, element);

		imshow( "Erosion Demo", image);

		waitKey (0);

	} 

	return 0;
}
  
