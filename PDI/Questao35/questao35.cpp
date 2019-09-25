//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

int main()
{
	Mat color = imread ("entrada1.jpg");

	Mat gray;

	Mat image;

	int elemento = 0;

	int dilation_size = 0;

	cvtColor (color, gray, CV_RGB2GRAY);

	threshold (gray, gray, 127, 255, CV_THRESH_OTSU); // Aplicando a limiarização do tipo otsu 

    int morph_size = 3;

	/* Estrutura para a operacao morfológicas, que é o "dilate" */
	int dilation_type;

	for (elemento = 0; elemento < 3; elemento++)
	{

		if (elemento == 0)
			dilation_type = MORPH_RECT;
		else if (elemento == 1)
			 dilation_type = MORPH_CROSS;
		else if (elemento == 2)
			dilation_type = MORPH_ELLIPSE;
		Mat element = getStructuringElement (dilation_type, Size( 4*morph_size + 1, 2*morph_size+1 ), Point( -1, -1 ) );

		/* Operacao do getStructuringElement
			 1- Forma: MORPH_CROSS, MORPH_RECT, MORPH_ELLIPSE, CV_SHAPE_CUSTOM
			 2- Tamanho
			 3- Para a posição dentro do elemento, (-1,-1) signifiga que tá no centro do elemento */
		// Aplicar a operação dilate

		dilate(gray, image, element );

		imshow( "Dilation Demo", image );

		waitKey (0);

	} 

	return 0;
}
  
