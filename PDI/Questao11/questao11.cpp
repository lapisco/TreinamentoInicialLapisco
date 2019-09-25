//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

Mat img;
Mat gray;
int y, x, num;
float xc=0, yc=0;

int main()
 {
     img = imread ("teste.jpg");

	 cvtColor (img, gray, CV_RGB2GRAY);
	 
	 for (y=0; y<gray.rows; y++)
	 {
		 for (x=0; x<gray.cols; x++)
		 {
			 gray.at<uchar>(y,x);
			 if (gray.at<uchar>(y,x) < 127)
				 gray.at<uchar>(y,x) = 1;
			 else 
				 gray.at<uchar>(y,x) = 0;
			 if (gray.at<uchar>(y,x) == 0)
			 {
				 xc += x;
				 yc += y;
				 num++;
			 }
		 }
	 }

	 /*Calculo do centroide*/
	 xc = xc/num;
	 yc = yc/num; 

	 printf ("X - %d\nY - %d\n", xc, yc);

	 circle (img, Point(xc , yc), 10, CV_RGB(0,255,0), -1 , 8, 0);
	 /*Descrever a função circle:
	       Imagem onde se quer desenhar o circulo
		   O centro do circulo
		   O raio do circulo
		   A cor do circulo
		   A espessura da linha do circulo: caso positivo - tracejado, se negativo - preenchido
		   Tipo de linha
		   Número de bits fracionários nas coordenadas do centro e no valor do raio
	 */

	 imshow ("IMAGEM", img);
	 imshow ("IMAGEM EM TONS DE CINZA", gray);

	 imwrite ("image-circle.jpg", img);
	 imwrite ("image-gray.jpg", gray);

	 waitKey(0);

	 system ("Pause");
	 return 0;

 }
  
