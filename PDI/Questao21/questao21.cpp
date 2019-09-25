//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

Mat_<uchar> imagem (240, 320, CV_8UC3);

void mouseEvent (int evt, int x, int y, int flags, void* param)
{
    if (evt==CV_EVENT_LBUTTONDOWN)
    {
		imagem.at<uchar>(y,x) = 255;
    }
}

int main ()
{

	Mat color = imread ("circulo.jpg",1); 

	Mat gray; 

	cvtColor (color, gray, CV_RGB2GRAY);


	for (int y=0; y<gray.rows; y++)
	{
		for (int x=0; x<gray.cols; x++)
		{
			gray.at<uchar>(y,x);
		}
	}

	//Mat_<uchar> imagem (240, 320, CV_8UC3);

	for (int y=0; y<240; y++)
	{
		for (int x=0; x<320; x++)
		{
			imagem.at<uchar>(y,x) = 0;
		}
	}

	namedWindow ("IMAGE_GRAY", 1); 
	imshow ("IMAGE_GRAY", gray);
	setMouseCallback ("IMAGE_GRAY", mouseEvent, 0);
    waitKey(0);
    destroyWindow ("IMAGE_GRAY");

	int k = 130;
	while (k!=0)
	{
		for (int y=0; y<240; y++)
		{
			for (int x=0; x<320; x++)
			{
				if (imagem.at<uchar>(y,x) == 255)
				{
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