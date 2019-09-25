//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

int main()
 {
    Mat img = imread ("teste.jpg");
	Mat gray;
	Mat Tamanho1;
	Mat Tamanho2;

	cvtColor (img, gray, CV_RGB2GRAY);

	imshow ("IMAGEM EM TONS DE CINZA", gray);

	/*A dimensão das imagens*/
	Size redimensionamento1 (160, 120);
	Size redimensionamento2 (640, 480);

	/*FUNCAO PARA REDIMENSIONAR A IMAGEM*/
	resize (gray, Tamanho1, redimensionamento1);
	resize (gray, Tamanho2, redimensionamento2);

	imshow ("IMAGEM EM TAMANHO 1", Tamanho1);
	imwrite ("imagemmenor.jpg", Tamanho1);
	imshow ("IMAGEM EM TAMANHO 2", Tamanho2);
	imwrite ("imagemaior.jpg", Tamanho2);

    cvWaitKey(0);

	return 0;
 }
  
