//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

int x, y;
Mat gray;
Mat color;
Mat_<uchar> imagem (466, 284, CV_8UC3);

void mouseEvent (int evt, int x, int y, int flags, void* param)
{
    if (evt==CV_EVENT_LBUTTONDOWN)
    {
		imagem.at<uchar>(y,x) = 255;
    }
}


int main ()
{
	color = imread ("imagem2.png");

	cvtColor (color, gray, CV_RGB2GRAY);


	/* Colocar a nova imagem toda em tons de cinza */
	for (y=0; y<466; y++)
	{
		for (x=0; x<284; x++)
		{
			imagem.at<uchar>(y,x) = 0;
		}
	}

	/* Trabalhar com o mouse */
	namedWindow ("IMAGE_GRAY", 1); 
	imshow ("IMAGE_GRAY", gray);
	setMouseCallback ("IMAGE_GRAY", mouseEvent, 0);
    waitKey(0);
    destroyWindow ("IMAGE_GRAY");

	int ca=1, cd = 0;
	while (ca!=cd)
	{
		ca = cd;
		for (y=0; y<466; y++)
		{
			for (x=0; x<284; x++)
			{
				if (imagem.at<uchar>(y,x) == 255) //Achar a semente 
				{
					if (gray.at<uchar>(y-1,x-1) <= 100 && imagem.at<uchar>(y-1,x-1) != 255)  
					{
						imagem.at<uchar>(y-1,x-1) = 255;
						cd++;
					}

					if (gray.at<uchar>(y-1,x) <= 100 && imagem.at<uchar>(y-1,x) != 255)
					{
						imagem.at<uchar>(y-1,x) = 255;
						cd++;
					}

					if (gray.at<uchar>(y-1,x+1) <= 100 && imagem.at<uchar>(y-1,x+1) != 255)
					{
						imagem.at<uchar>(y-1,x+1) = 255;
						cd++;
					}

					if (gray.at<uchar>(y,x-1) <= 100 && imagem.at<uchar>(y,x-1) != 255)
					{
						imagem.at<uchar>(y,x-1) = 255;
						cd++;
					}

					if (gray.at<uchar>(y,x+1) <= 100 && imagem.at<uchar>(y,x+1) != 255)
					{
						imagem.at<uchar>(y,x+1) = 255;
						cd++;
					}

					if (gray.at<uchar>(y+1,x-1) <=100 && imagem.at<uchar>(y+1,x-1) != 255)
					{
						imagem.at<uchar>(y+1,x-1) = 255;
						cd++;
					}

					if (gray.at<uchar>(y+1,x) <=100 && imagem.at<uchar>(y+1,x) != 255)
					{
						imagem.at<uchar>(y+1,x) = 255;	
						cd++;
					}
					
					if (gray.at<uchar>(y+1,x+1) <= 100 && imagem.at<uchar>(y+1,x+1) != 255)
					{
						imagem.at<uchar>(y+1,x+1) = 255;
						cd++;
					}
				}
			}

		}
		imshow ("IMAGEM", imagem);
		waitKey (40);
	}


	waitKey (0);

	system ("Pause");

	return 0;

}