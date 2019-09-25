#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

int main ()
{

	int x, y, x1, y1;
	int r, g, b;

	Mat color = imread ("entrada.jpg"); //Imagem de entrada

	Mat gray; //Imagem em tons de cinza para ser trabalhado

	Mat_<uchar>imagem (color.rows, color.cols, 1);

	Mat_<Vec3b>colorida (color.rows, color.cols, 1);

	cvtColor (color, gray, CV_RGB2GRAY);
	
	/* Coloca toda a nova imagem para preto */
	for (y=0; y<color.rows; y++)
	{
		for (x=0; x<color.cols; x++)
		{
			imagem.at<uchar>(y,x) = 0;
			colorida (y, x) [0] = 0;
			colorida (y, x) [1] = 0;
			colorida (y, x) [2] = 0; 
		}
	}

	imshow ("IMG", color); 
	int cont=0;
	for (y1=0; y1 <gray.rows ; y1++)
	{
		for (x1=0; x1<gray.cols; x1++)
		{
			if (gray.at<uchar>(y1,x1) == 0 && imagem.at<uchar>(y1,x1) == 0 )
			{
				cont++;
				imagem.at<uchar>(y1,x1) = 255;
				
				srand ( unsigned (NULL) );
				if (cont==0)
				{
					r = (rand () %256)/2;
					g += rand () %256;
					b = rand () %256;
				}
				if (cont%2 == 0)
				{
					r += rand () %256;
					g -= rand () %256;
					b += rand () %256;
				}
				if (cont%2 != 0)
				{
					r -= rand () %256;
					g -= rand () %256;
					b -= rand () %256;
				}

				int ca=1, cd = 0;
				while (ca != cd)
				{
					ca = cd;
					for (y=0; y<gray.rows; y++)
					{
						for (x=0; x<gray.cols; x++)
						{
							if (imagem.at<uchar>(y,x) == 255)
							{
								if (gray.at<uchar>(y-1,x-1) < 127 && imagem.at<uchar>(y-1,x-1) != 255)
								{
									colorida(y-1,x-1)[0] = r;
									colorida(y-1,x-1)[1] = g;
									colorida(y-1,x-1)[2] = b;
									imagem.at<uchar>(y-1,x-1) = 255;
									cd++;
								}

								if (gray.at<uchar>(y-1,x) < 127 && imagem.at<uchar>(y-1,x) != 255)
								{
									colorida(y-1,x)[0] = r;
									colorida(y-1,x)[1] = g;
									colorida(y-1,x)[2] = b;
									imagem.at<uchar>(y-1,x) = 255;
									cd++;
								}

								if (gray.at<uchar>(y-1,x+1) < 127 && imagem.at<uchar>(y-1,x+1) != 255)
								{
									colorida(y-1,x+1)[0] = r;
									colorida(y-1,x+1)[1] = g;
									colorida(y-1,x+1)[2] = b;
									imagem.at<uchar>(y-1,x+1) = 255;
									cd++;
								}

								if (gray.at<uchar>(y,x-1) < 127 && imagem.at<uchar>(y,x-1) != 255)
								{
									colorida(y,x-1)[0] = r;
									colorida(y,x-1)[1] = g;
									colorida(y,x-1)[2] = b;
									imagem.at<uchar>(y,x-1) = 255;
									cd++;
								}
	
								if (gray.at<uchar>(y,x+1) < 127  && imagem.at<uchar>(y,x+1) != 255)
								{
									colorida(y,x+1)[0] = r;
									colorida(y,x+1)[1] = g;
									colorida(y,x+1)[2] = b;
									imagem.at<uchar>(y,x+1) = 255;
									cd++;
								}
	
								if (gray.at<uchar>(y+1,x-1) < 127  && imagem.at<uchar>(y+1,x-1) != 255)
								{
									colorida(y+1,x-1)[0] = r;
									colorida(y+1,x-1)[1] = g;
									colorida(y+1,x-1)[2] = b;
									imagem.at<uchar>(y+1,x-1) = 255;
									cd++;
								}

								if (gray.at<uchar>(y+1,x) < 127  && imagem.at<uchar>(y+1,x) != 255)
								{
									colorida(y+1,x)[0] = r;
									colorida(y+1,x)[1] = g;
									colorida(y+1,x)[2] = b;
									imagem.at<uchar>(y+1,x) = 255;
									cd++;
								}
					
								if (gray.at<uchar>(y+1,x+1) < 127  && imagem.at<uchar>(y+1,x+1) != 255)
								{
									colorida(y+1,x+1)[0] = r;
									colorida(y+1,x+1)[1] = g;
									colorida(y+1,x+1)[2] = b;
									imagem.at<uchar>(y+1,x+1) = 255;
									cd++;
								}
							}
						}
					}
				    //Rect roi = Rect (0, 0, 100, 100);
					//Mat region = colorida (roi);
					imshow ("IMAGEM", colorida); 
					waitKey(30);
				}
			}
		}
	}
	printf("%d",cont);
	waitKey (0);
	return 0;

}
