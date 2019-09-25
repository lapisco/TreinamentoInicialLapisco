//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

Mat_<Vec3b> imagem (480, 640, CV_8UC3); //Imagem que iremos trabalhar

void mouseEvent (int evt, int x, int y, int flags, void* param)
{
    if (evt==CV_EVENT_LBUTTONDOWN)
    {
		imagem(y,x)[0] = 255;
		imagem(y,x)[1] = 0;
		imagem(y,x)[2] = 0;
    }
}


int main ()
{
	int x,y;

	Mat color = imread ("entrada.jpg"); //Imagem de entrada

	Mat gray; //Imagem em tons de cinza para ser trabalhado

	cvtColor (color, gray, CV_RGB2GRAY);

	///////////////Mat_<Vec3b> imagem (240, 320, CV_8UC3); //Imagem que iremos trabalhar
	
	/* Coloca toda a nova imagem para preto */
	for (y=0; y<color.rows; y++)
	{
		for (x=0; x<color.cols; x++)
		{
			imagem(y,x)[0] = 0;
			imagem(y,x)[1] = 0;
			imagem(y,x)[2] = 0;
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
		cd=0;
		for (y=0; y<color.rows; y++)
		{
			for (x=0; x<color.cols; x++)
			{
				if (imagem(y,x)[0] == 255)
				{
					if (gray.at<uchar>(y-1,x-1) < 127)
					{
						imagem(y-1,x-1)[0] = 255;
						imagem(y-1,x-1)[1] = 0;
						imagem(y-1,x-1)[2] = 0;
						cd++;
					}

					if (gray.at<uchar>(y-1,x) < 127)
					{
						imagem(y-1,x)[0] = 255;
						imagem(y-1,x)[1] = 0;
						imagem(y-1,x)[2] = 0;
						cd++;
					}

					if (gray.at<uchar>(y-1,x+1) < 127)
					{
						imagem(y-1,x+1)[0] = 255;
						imagem(y-1,x+1)[1] = 0;
						imagem(y-1,x+1)[2] = 0;
						cd++;
					}

					if (gray.at<uchar>(y,x-1) < 127)
					{
						imagem(y,x-1)[0] = 255;
						imagem(y,x-1)[1] = 0;
						imagem(y,x-1)[2] = 0;
						cd++;
					}

					if (gray.at<uchar>(y,x+1) < 127)
					{
						imagem(y,x+1)[0] = 255;
						imagem(y,x+1)[1] = 0;
						imagem(y,x+1)[2] = 0;
						cd++;
					}

					if (gray.at<uchar>(y+1,x-1) < 127)
					{
						imagem(y+1,x-1)[0] = 255;
						imagem(y+1,x-1)[1] = 0;
						imagem(y+1,x-1)[2] = 0;
						cd++;
					}

					if (gray.at<uchar>(y+1,x) < 127)
					{
						imagem(y+1,x)[0] = 255;
						imagem(y+1,x)[1] = 0;
						imagem(y+1,x)[2] = 0;
						cd++;
					}
					
					if (gray.at<uchar>(y+1,x+1) < 127)
					{
						imagem(y+1,x+1)[0] = 255;
						imagem(y+1,x+1)[1] = 0;
						imagem(y+1,x+1)[2] = 0;
						cd++;
					}
				}
			}
		}
		imshow ("IMAGEM1", imagem);
		waitKey (40);
	}


	/* Calculo do centroide */

	float xc = 0;
	float yc = 0;
	int num = 0;
	for (y=0; y<color.rows; y++)
	{
		 for (x=0; x<color.cols; x++)
		 {
			  xc += x;
			  yc += y;
			  num++;
		 }
	}
 
	xc = xc/num;
	yc = yc/num;
	circle (imagem, Point(xc, yc), 10, CV_RGB(0, 255, 0), 1, 8, 0);
	imshow ("IMAGEM1", imagem);

	waitKey (50);

	system ("Pause");

	return 0;

}