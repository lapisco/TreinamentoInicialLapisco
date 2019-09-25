//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

int main()
{
	Mat color = imread ("entrada.jpg");

	Mat gray;

	Mat image;

	cvtColor (color, gray, CV_RGB2GRAY);

	threshold (gray, gray, 127, 255, CV_THRESH_OTSU); // Aplicando a limiarização do tipo otsu 

	int elemento;

    int morph_size = 3;

	int erosion_type;

	for (elemento = 0; elemento < 3; elemento++)
	{

		if (elemento == 0)
			erosion_type = MORPH_RECT;
		else if (elemento == 1)
			erosion_type = MORPH_CROSS;
		else if (elemento == 2)
			erosion_type = MORPH_ELLIPSE;
		Mat element = getStructuringElement (erosion_type, Size( 4*morph_size + 1, 2*morph_size+1 ), Point( -1, -1 ) );

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
  
