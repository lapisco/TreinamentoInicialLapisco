//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

FILE* fp;
Mat img;
Mat gray;

int main()
 {
	 
     img = imread ("Teste.jpg");
	 fp = fopen ("resultado.xls", "w");

	 ////////////CONVERTER PARA TONS DE CINZA/////////////
	 cvtColor (img, gray, CV_RGB2GRAY);

	 ///////////APLICANDO A LIMIARIZAÇÃO COM OS VALORES DOS PIXELS DA IMAGEM/////////////////
	 for (int y=0; y<gray.rows; y++)
	 {
		 for (int x=0; x<gray.cols; x++)
		 {
			 gray.at<uchar>(y,x);
			 if (gray.at<uchar>(y,x) < 127)
				 fprintf (fp, "1 ");
			 else 
				 fprintf (fp, "0 ");
		 }
		 fprintf (fp, "\n");
	 }

	 imshow ("IMAGEM EM TONS DE CINZA", gray);
	// imwrite ("Teste_cinza.jpg", gray);

	 fclose (fp);
     cvWaitKey(0);

	 return 0;

 }
  
