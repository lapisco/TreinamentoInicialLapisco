#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;
//
//void picture (int &r, int &g, int &b, int cont)
//{
//			srand ( unsigned (NULL) );
//			if (cont==0) 
//			{
//				r = (rand () %256)/2;
//				g += rand () %256;
//				b = rand () %256;
//			}
//			else if (cont%2 == 0)
//			{
//				r += rand () %256;
//				g -= rand () %256/2;
//				b += rand () %256;
//			}
//			else if (cont%2 != 0)
//			{
//				r -= rand () %256;
//				g += rand () %256;
//				b -= rand () %256/2;
//			}
//}

using namespace cv;
using namespace std;


int main ()
{ 
	char name[100];
	int x, y, x1, y1;
	int Xmin , Xmax , Ymin , Ymax ;
	int r=255, g=255, b=255;
	
	Mat img = imread ("imagem3.png");

	Mat gray; 

	cvtColor (img, gray, CV_RGB2GRAY);

	Mat_<uchar>imagem (img.rows, img.cols, 1);

	Mat_<Vec3b>color (gray.rows, gray.cols, 1);
			
	for (y=0; y<gray.rows; y++)
	{
		for (x=0; x<gray.cols; x++)
		{
			imagem.at<uchar>(y,x) = 0;
			color (y, x) [0] = 0;
			color (y, x) [1] = 0;
			color (y, x) [2] = 0; 
		}
	}

	imshow ("IMG", img); 

	int cont=0; // Contador usados para mostrar o numero de objetos encontrados na imagem

	for (y1=0; y1 < gray.rows ; y1++) // "FOR" GERAL PARA PERCORRER TODA A IMAGEM
	{
		for (x1 = 0; x1 < gray.cols; x1++)
		{
			
			if (gray.at<uchar>(y1,x1) == 0  && imagem.at<uchar>(y1,x1) == 0) 
			{
				imagem.at<uchar>(y1,x1) = 255;

				/*picture (r, g, b, cont);*/
				
				/*Inicialmente consideramos Xmin,Ymin,Xmax,Ymax na coordenada onde a semente é colocada*/
				Xmin = x1;
				Ymin = y1;
				Xmax = x1;
				Ymax = y1;

				cont ++; // Contagem do numero de objetos de uma imagem

				int ca = 1;
				int cd = 0;

				while (ca != cd)
				{					
					ca = cd;
					for (y = 0; y<imagem.rows; y++)
					{
						for (x = 0; x<imagem.cols; x++)
						{
							if (imagem.at<uchar>(y,x) == 255 )// Encontar semente				
							{								
									/*if (x > Xmax)
										Xmax = x;
									if (y > Ymax)
										Ymax = y;	*/														

								if (gray.at<uchar>(y-1,x-1) < 127 && imagem.at<uchar>(y-1,x-1) != 255)
								{
									color (y-1,x-1)[0] = r;
									color (y-1,x-1)[1] = g;
									color (y-1,x-1)[2] = b;	

									imagem.at<uchar>(y-1,x-1) = 255;

									if (x-1 < Xmin){Xmin = x - 1;} // Encontrar o Xmin de cada objeto
									if (x -1 > Xmax){Xmax = x-1;}
									if (y-1 > Ymax){Ymax = y-1;}
									cd++;
								}

								if (gray.at<uchar>(y-1,x) < 127 && imagem.at<uchar>(y-1,x) != 255)
								{
									color (y-1,x)[0] = r;
									color (y-1,x)[1] = g;
									color (y-1,x)[2] = b;

									imagem.at<uchar>(y-1,x) = 255;

									if (x < Xmin){Xmin = x;}// Encontrar o Xmin de cada objeto
									if (x > Xmax){Xmax = x;}
									if (y - 1 > Ymax){Ymax = y;}

									cd++;
								}

								if (gray.at<uchar>(y-1,x+1) < 127 && imagem.at<uchar>(y-1,x+1) != 255)
								{
									color (y-1,x+1)[0] = r;
									color (y-1,x+1)[1] = g;
									color (y-1,x+1)[2] = b;

									imagem.at<uchar>(y-1,x+1) = 255;

									if(x+1 < Xmin){Xmin = x+1;} // Encontrar o Xmin de cada objeto
									if (x+1> Xmax){Xmax = x+1;}
									if (y-1 > Ymax){Ymax = y-1;}
									cd++;
								}

								if (gray.at<uchar>(y,x-1) < 127 && imagem.at<uchar>(y,x-1) != 255)
								{ 
									color (y,x-1)[0] = r;
									color (y,x-1)[1] = g;
									color (y,x-1)[2] = b;

									imagem.at<uchar>(y,x-1) = 255;

									if (x-1 < Xmin){Xmin = x-1;}// Encontrar o Xmin de cada objeto
									if (x-1 > Xmax){Xmax = x-1;}
									if (y > Ymax){Ymax = y;}
									cd++;
								}
	
								if (gray.at<uchar>(y,x+1) < 127  &&  imagem.at<uchar>(y,x+1) != 255)
								{
									color (y,x+1)[0] = r;
									color (y,x+1)[1] = g;
									color (y,x+1)[2] = b;

									imagem.at<uchar>(y,x+1) = 255;

									if (x+1 < Xmin){Xmin = x+1;}// Encontrar o Xmin de cada objeto
									if (x+1 > Xmax){Xmax = x;}
									if (y > Ymax){Ymax = y;}
									cd++;
								}
	
								if (gray.at<uchar>(y+1,x-1) < 127  && imagem.at<uchar>(y+1,x-1) != 255)
								{
									color (y+1,x-1)[0] = r;
									color (y+1,x-1)[1] = g;
									color (y+1,x-1)[2] = b;

									imagem.at<uchar>(y+1,x-1) = 255;

									if (x-1 < Xmin){Xmin = x-1;}// Encontrar o Xmin de cada objeto
									if (x-1> Xmax){Xmax = x-1;}
									if (y+1> Ymax){Ymax = y+1;}
									cd++;
								}

								if (gray.at<uchar>(y+1,x) < 127  && imagem.at<uchar>(y+1,x)!= 255)
								{
									color (y+1,x)[0] = r;
									color (y+1,x)[1] = g;
									color (y+1,x)[2] = b;

									imagem.at<uchar>(y+1,x) = 255;

									if (x < Xmin){Xmin = x;}// Encontrar o Xmin de cada objeto
									if (x > Xmax){Xmax = x;}
									if (y+1 > Ymax){Ymax = y+1;}
									cd++;
								}
					
								if (gray.at<uchar>(y+1,x+1) < 127  && imagem.at<uchar>(y+1,x+1)!= 255)
								{
									color (y+1,x+1)[0] = r;
									color (y+1,x+1)[1] = g;
									color (y+1,x+1)[2] = b;

									imagem.at<uchar>(y+1,x+1) = 255;

									if (x+1 < Xmin){Xmin = x+1;}// Encontrar o Xmin de cada objeto
									if (x +1> Xmax){Xmax = x+1;}
									if (y+1 > Ymax){Ymax = y+1;}
									cd++;
								}

							} // FIM DO IF GERAL
						} //FIM DO FOR INTERNO
					}			
					//FIM DO FOR EXTERNO 
					imshow ("IMAGEM_1", color); 
					/*imshow ("IMAGEM_2", imagem);*/ 
					waitKey(30);
				} 
				// FIM DO WHILE 
				sprintf(name,"imagem %d",cont);

				Rect region = Rect (Xmin,Ymin, Xmax-Xmin, Ymax-Ymin);
			    Mat image = color(region);
				imshow (name, image);	
				Xmin = 0; Xmax = 0; Ymin = 0; Ymax = 0;
				}
			}	
	}
	printf("Numero de imagens = %d",cont);
	waitKey (0);
	return 0;

}