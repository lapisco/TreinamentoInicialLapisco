#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

void main ()
{ 
	char name[500];

	int cont=0, num=0;
	int x, y;

	FILE *arquivo;
	arquivo = fopen("Centrais.txt","w");
	
	for(int num=0;num<7; num++)
	{
        sprintf(name, "imagem%d.png",num);
        
        Mat img = imread(name);

		Mat_<uchar> gray (img.rows, img.cols, CV_8UC3);

		cvtColor (img, gray, CV_RGB2GRAY);

		Mat_<uchar> image (img.rows, img.cols, CV_8UC3);

		Mat contour, contour_bin;
		vector<vector<Point> > contours;

		Laplacian(gray, contour, CV_8UC1, 3);
							
		threshold(contour,contour_bin,127,255,CV_THRESH_BINARY);

		findContours(contour_bin, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

		vector<std::vector<cv::Point>>::const_iterator itc= contours.begin();  

		while (itc!=contours.end()) 
		{     
			Moments mom =  moments(cv::Mat(*itc++));

			double central[7];

			central[0] = mom.mu20;
			central[1] = mom.mu11;
			central[2] = mom.mu02;
			central[3] = mom.mu30;
			central[4] = mom.mu21;
			central[5] = mom.mu12;
			central[6] = mom.mu03;

			for(int i=0; i<7; i++)
			{
				fprintf(arquivo, "%f, ", central[i]);					
			}
			fprintf(arquivo, "%d\n", num);
		}					

	} 

	fclose(arquivo);
}


