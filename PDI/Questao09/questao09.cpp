#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

FILE*arquivo;

int main()
 {
	 Mat color = imread("teste.jpg",1);
	 Mat gray;
	 cvtColor(color,gray,CV_RGB2GRAY);

	 arquivo=fopen("Resultado.txt","w");
	 int x,y;
	 for(y = 0; y < gray.rows; y++)
	 {
		 for(x = 0; x < gray.cols; x++)
		 {
			 fprintf(arquivo,"%d  ",gray.at<uchar>(y,x));
		 }
		 fprintf(arquivo,"\n");
	 }

	 imshow("Koala-Cinza",gray);
	 imwrite("Koala-cinza.jpg",gray);
	 fclose(arquivo);
	 cvWaitKey(0);
 }
