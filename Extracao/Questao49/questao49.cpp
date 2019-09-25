#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"    
#include "opencv2/ml/ml.hpp"         
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <time.h>

#include "lbp.h"
#include "histogram.h"

#include <vector>

#define _WIN32_WINNT 0x050

using namespace cv;
using namespace std;

FILE * fp;
int qtdAmostras;
float menorUH, UH,  maiorUH;


vector<float> lbp_extraction_image(Mat image){
    Mat lbp_img = lbp::OLBP(image);
    int quant_tomCinza = 12;//Quantidade de Tons de Cinza
    normalize(lbp_img, lbp_img, 0, quant_tomCinza-1, NORM_MINMAX, CV_8UC1);
    //Parametros da Fun��o Normalize
    //1 - imagem de entrada // 2 - imagem de saida
    //3, 4 - Variacao dos tons de cinza que a imagem vai ter. Neste caso -> 0 ~ 11
    //5 - A funcao NORM_MINMAX serve para normalizar entre os valores do parametros (3,4)
    //6 - CV_8UC1 -> Imagem 8 bits Uchar, 1 canal
    Mat spatial_hist = lbp::spatial_histogram(lbp_img, quant_tomCinza, 3, 3, 0);
    // Parametros da Funcao spatial_hist
    //1 - imagem de entrada // 2 - A variacao entre os parametros (3,4) da funcao Normalize no caso 12
    //3, 4 - Tamanho da mascara(vizinhanca)  3x3
    //
    vector<float> feature_vector;
    for(int j = 0; j < spatial_hist.cols; ++j){
        if(spatial_hist.at<int>(0, j) != -1){
            feature_vector.push_back(spatial_hist.at<int>(0, j));
        }
    }
    return feature_vector;
}
int main()
{
    char name[500];
    
    for(int num=0;num<3; num++)
	{
        sprintf(name, "imagem%d.jpg",num);
        
        Mat img = imread(name, IMREAD_GRAYSCALE);
        int r = 293;
        int c = 293;
        
        Mat imageMat;
        Size sizeMat(c,r);
        resize(img,imageMat,sizeMat);
        
        clock_t Tmp[2];
        
        vector <float> retorno;
        
        Tmp[0]= clock();
        
        retorno = lbp_extraction_image(imageMat);
        
        Tmp[1]= clock();
        
        printf("%d\t",(int)retorno.size());

        double time;
        time = (Tmp[1]-Tmp[0])*1000.0/CLOCKS_PER_SEC;
        FILE * tempos;
        
        tempos = fopen("time.txt","a");
        fprintf(tempos,"%f\n",time);
        fclose(tempos);
        
        FILE *fpOutOpencvGLCM = NULL;
 
        fpOutOpencvGLCM = fopen("LBP.txt","a");
        for (int print = 0; print < retorno.size(); print+=1)
		{
            fprintf(fpOutOpencvGLCM, "%f,",retorno.at(print));
        }
        printf("\n");
        fprintf(fpOutOpencvGLCM,"\n");
        fclose(fpOutOpencvGLCM);

    }

	system ("Pause");
    return 0;
}