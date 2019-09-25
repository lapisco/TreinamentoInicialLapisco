//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

Mat img; //Imagem de entrada
Mat_<uchar> gray (194, 259, CV_8UC3); //Imagem em tons de cinza
Mat_<uchar> equalized (194, 259, CV_8UC3); //Imagem equalizada
Mat hist_gray;
Mat hist_equalized;

Mat histograma (Mat &imagem)
{

	// Definir as barras do histograma
    int bins = 256; //Quantidade de barras
    int histSize[] = {bins}; //Tamanho do histograma

    // O intervalo do histograma
    float lranges[] = {0, 256};
    const float* ranges[] = {lranges};

	Mat hist;
	int channels [] = {0}; //Numeros de canais, como a imagem de entrada é só de um canal, vem 0

	int const hist_height = 256;
    Mat3b hist_image = Mat3b::zeros(hist_height, bins);
	
	calcHist(&imagem, 1, channels, Mat(), hist, 1, histSize, ranges, true, false); //Função para criar o histograma

	double max_val=0;
    minMaxLoc(hist, 0, &max_val);

	// Visualizar cada barra
    for(int b = 0; b < bins; b++) 
	{
        float const binVal = hist.at<float>(b);
        int   const height = cvRound(binVal*hist_height/max_val);
        line (hist_image, Point(b, hist_height-height), Point(b, hist_height), Scalar::all(255)); 
		//    imagem      ponto inicial                 ponto final            
    }
	return hist_image;
}

int main()
{

	//Imagem de entrada
	img = imread("teste.jpg");
	//Converter pra cinza
	cvtColor (img, gray, CV_RGB2GRAY);

	int max = gray.at<uchar>(0, 0); 
	int min = gray.at<uchar>(0, 0);
	int x, y;
	for (y=0; y<194; y++)
	{
		for (x=0; x<259; x++)
		{
			if (gray.at<uchar>(y, x) < max)
				max = gray.at<uchar>(y, x);
			if (gray.at<uchar>(y, x) > min)
				min = gray.at<uchar>(y, x);
		}
	}


	for (y=0; y<194; y++)
	{
		for (x=0; x<259; x++)
		{
			equalized.at<uchar>(y,x) = (gray.at<uchar>(y, x) - max)*255/(min-max);
		}
	}

	imshow ("Gray Image", gray);
	Mat hist_gray = histograma (gray);
	imshow("name1", hist_gray);
	imshow ("Equalized Image", equalized);
	Mat hist_equalized = histograma (equalized);
	imshow("name2", hist_equalized);

    waitKey(0);
	return 0;
}
