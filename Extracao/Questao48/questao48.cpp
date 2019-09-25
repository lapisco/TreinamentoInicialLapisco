#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

FILE *arquivo;

void main ()
{ 
	char name[500]; 

	int x, y;
	arquivo = fopen("Momentos.txt","a");
	
	for(int num=0;num<7; num++)
	{
        sprintf(name, "imagem%d.png",num);
        
        Mat img = imread(name);
	
		Mat_<uchar> gray (img.rows, img.cols, CV_8UC3);

		cvtColor (img, gray, CV_RGB2GRAY);

		Mat_<uchar> image (img.rows, img.cols, CV_8UC3);

		Mat contour, contour_bin;
		vector<vector<Point> > contours;

		Laplacian (gray, image, CV_8UC1, 3);
					
		threshold (image,contour_bin,127,255,CV_THRESH_BINARY);

		findContours (contour_bin, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

		double hu[7];
 
		std::vector<std::vector<cv::Point>>::const_iterator itc= contours.begin();  
		while (itc!=contours.end())
		{     
			Moments mom = moments(cv::Mat(*itc++));
			HuMoments(mom, hu);
				
			hu[0]=mom.nu02;
			hu[1]=mom.nu03;
			hu[2]=mom.nu11;
			hu[3]=mom.nu12;
			hu[4]=mom.nu20;
			hu[5]=mom.nu21;
			hu[6]=mom.nu30;

			for(int i=0; i<7; i++)
			{
				fprintf(arquivo, "%f, ", hu[i]);		
			}
			fprintf (arquivo, "%d\n", num);
		}

	}  

	fclose(arquivo);
}


