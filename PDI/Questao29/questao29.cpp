//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;


int main ()
{
	Mat color = imread ("entrada.jpg", 1); //Imagem colorida 

	Mat gray; //Imagem em tons de cinza

	cvtColor (color, gray, CV_RGB2GRAY); //Converter para tons de cinza

	GaussianBlur( gray, gray, Size(9, 9), 2, 2 ); //Retirar o ruido da imagem

	vector<Vec3f> circles; 

	HoughCircles (gray, circles, CV_HOUGH_GRADIENT, 1, 30, 200, 50, 0, 0); //Aplicar o filtro
//                   vetor             tipo         razao da resolucao, distancia minima dos centros, 
	 
	//Desenhar o circulo

	for( size_t i = 0; i < circles.size(); i++ )
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1])); //Pega um numero float para um numero inteiro mais proximo
		int radius = cvRound(circles[i][2]);
               //Desenhar o ponto no centro
		circle (color, center, 3, Scalar(0,255,0), -1, 8, 0 );
              //Desenhar as linhas no contorno
		circle (color, center, radius, Scalar(0,0,255), 3, 8, 0 );
	}

	imshow( "IMAGEM COM OS CIRCULOS", color);

	waitKey(0);

	system ("Pause");

	return 0;
}