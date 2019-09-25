//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

/* adaptiveThreshold calcula um limite de pixel por pixel, 
enquanto limiar calcula-la para toda a imagem - ela mede toda a imagem por uma régua, 
enquanto que o outro faz uma nova "régua" para cada pixel. */

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
	   imagem de saída
	   valor diferente de zero atribuída aos pixels para que a condição é satisfeita
	   algoritmo de limiar adaptativo de usar
	   tipo: observação bem interessante 
	   tamanho para vizinhança para o calculo do pixel
	   constante subtraida da media e da media ponderada */

	imshow ("IMAGEM COM LIMIARIZAÇÃO AUTOMATICA", imagem);

	waitKey (0);

	return 0;
}