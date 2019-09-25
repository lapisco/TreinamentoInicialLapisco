#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

FILE *fp;

void main ()
{ 

	char name[500];
	int cont = 0;
	int num = 0;	

	fp = fopen("Momentos_Estatisticos.txt","a");
	
	for (int num=0; num<7; num++)
	{
		
		sprintf(name, "imagem%d.png",num);
        
        Mat img = imread(name);
		
		Mat_<uchar>image (img.rows, img.cols, CV_8UC3);

		cvtColor (img, image, CV_RGB2GRAY);
	
		Mat contour, contour_bin;

		vector<vector<Point>> contours;

		Laplacian (image, contour, CV_8UC1, 3);
							
		threshold(contour,contour_bin,127,255,CV_THRESH_BINARY);

		findContours(contour_bin, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

		double hu[10]; 

		vector<vector<Point>>::const_iterator itc= contours.begin();  

		while (itc!=contours.end())
		{     
			Moments mom = moments(Mat(*itc++));

			hu[0]=mom.m00;
			hu[1]=mom.m01;
			hu[2]=mom.m02;
			hu[3]=mom.m03;
			hu[4]=mom.m10;
			hu[5]=mom.m11;
			hu[6]=mom.m12;
			hu[7]=mom.m20;
			hu[8]=mom.m21;
			hu[9]=mom.m30;
									
			for(int i=0; i<10; i++) //momentos da imagem
			{
				fprintf(fp, "%f, ", hu[i]);		
			}
			fprintf (fp, "%d\n", num);
		}

	}

	fclose(fp);
}


