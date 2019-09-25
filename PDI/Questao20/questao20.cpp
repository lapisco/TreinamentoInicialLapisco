//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

int main ()
{

	Mat color = imread ("imagem2.png",1); 

	Mat gray; 

	cvtColor (color, gray, CV_RGB2GRAY);


	for (int y=0; y<gray.rows; y++)
	{
		for (int x=0; x<gray.cols; x++)
		{
			gray.at<uchar>(y,x);
		}
	}

	Mat_<uchar> imagem (gray.rows, gray.cols, CV_8UC3);

	for (int y=0; y<gray.rows; y++)
	{
		for (int x=0; x<gray.cols; x++)
		{
			imagem.at<uchar>(y,x) = 0;
		}
	}
	

	imagem.at<uchar>(150,200) = 255;

	int k = 130;
	while (k!=0)
	{
		for (int y=0; y<gray.rows; y++)
		{
			for (int x=0; x<gray.cols; x++)
			{
				if (imagem.at<uchar>(y,x) == 255)
				{
					//imagem.at<uchar>(160,120) = 255;
					if (gray.at<uchar>(y-1,x-1) < 127)
					{
						imagem.at<uchar>(y-1,x-1) = 255;
					}

					if (gray.at<uchar>(y-1,x) < 127)
					{
						imagem.at<uchar>(y-1,x) = 255;
					}

					if (gray.at<uchar>(y-1,x+1) < 127)
					{
						imagem.at<uchar>(y-1,x+1) = 255;
					}

					if (gray.at<uchar>(y,x-1) < 127)
					{
						imagem.at<uchar>(y,x-1) = 255;
					}

					if (gray.at<uchar>(y,x+1) < 127)
					{
						imagem.at<uchar>(y,x+1) = 255;
					}

					if (gray.at<uchar>(y+1,x-1) < 127)
					{
						imagem.at<uchar>(y+1,x-1) = 255;
					}

					if (gray.at<uchar>(y+1,x) < 127)
					{
						imagem.at<uchar>(y+1,x) = 255;	
					}
					
					if (gray.at<uchar>(y+1,x+1) < 127)
					{
						imagem.at<uchar>(y+1,x+1) = 255;
					}
				}
			}
			imshow ("IMAGEM1", imagem);
			waitKey (10);
		}
	
		k--;
	}

	waitKey (0);

	system ("Pause");

	return 0;

}