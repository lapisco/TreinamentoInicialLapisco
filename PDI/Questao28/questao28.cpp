//Laborat�rio de Prot�tipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

/* adaptiveThreshold calcula um limite de pixel por pixel, 
enquanto limiar calcula-la para toda a imagem - ela mede toda a imagem por uma r�gua, 
enquanto que o outro faz uma nova "r�gua" para cada pixel. */

using namespace cv;
using namespace  std;

int main ()
{
	Mat color = imread ("frutas.jpg");
	Mat gray;
	Mat imagem;

	cvtColor (color, gray, CV_RGB2GRAY);

	//adaptiveThreshold ( imagem , imagem , 255 , ADAPTIVE_THRESH_GAUSSIAN_C , CV_THRESH_BINARY , 15 , - 5 );

	adaptiveThreshold (gray, imagem, 255, ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY_INV, 7, -5);
	/* imagem de entrada
	   imagem de sa�da
	   valor diferente de zero atribu�da aos pixels para que a condi��o � satisfeita
	   algoritmo de limiar adaptativo de usar
	   tipo: observa��o bem interessante 
	   tamanho para vizinhan�a para o calculo do pixel
	   constante subtraida da media e da media ponderada */

	imshow ("IMAGEM COM LIMIARIZA��O AUTOMATICA", imagem);

	waitKey (0);

	return 0;
}