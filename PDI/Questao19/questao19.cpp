//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

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
  Mat img, gray;
  Mat grad;
  
  img = imread("image.jpg",1);
  imshow("Imagem colorida",img);

  cvtColor( img, gray, CV_RGB2GRAY );

  Mat grad_x, grad_y;
  Mat abs_grad_x, abs_grad_y;

  /// Gradient X
  Sobel(gray, grad_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT );
  convertScaleAbs( grad_x, abs_grad_x );

  /// Gradient Y
  Sobel(gray, grad_y, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT );
 convertScaleAbs( grad_y, abs_grad_y );

  addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );

    imshow ("Gray Image", gray);
	Mat hist_gray = histograma (gray);
	imshow ("name1", hist_gray);
	imwrite ("HIST.jpg", hist_gray);

	imshow ("Equalized Image", grad);
	Mat hist_grad = histograma (grad);
	imshow("name2", hist_grad);
	imwrite ("HISTEQUA.jpg", hist_grad);

  waitKey (0);
  return 0;
}
  
