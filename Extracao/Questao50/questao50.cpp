#include <stdio.h>
#include <iostream>
#include "opencv2\core\core.hpp"
#include "opencv2\features2d\features2d.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\nonfree\nonfree.hpp"
#include "opencv2\nonfree\features2d.hpp"
#include "opencv/cv.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace cv;
using namespace std;

int main()
{
 
	char name [500];
	FILE* fp = fopen ("arquivo.txt", "w");

	for (int num = 1; num<11; num++)
	{
		sprintf (name, "%d.jpg", num);
		Mat entrada = imread (name,1);
		Mat cinza;

		cvtColor(entrada, cinza, CV_RGB2GRAY);
    

		float energy=0,contrast=0,homogenity=0;
		float IDM=0,entropy=0,mean1=0, dissimilarity=0;
		float ASM=0, correlation=0;
		float mean2=0, mean3=0, omegai=0, omegaj=0;
		float variance=0, sumEntropy=0, sumVariance=0, sumAverage=0;
		float diferenceEntropy=0, diferenceVariance=0;
    
		int row=cinza.rows,col=cinza.cols;
    
		Mat gl=Mat::zeros(256,256,CV_32FC1);
  
		  for(int i=0;i<row;i++)
		{
			    for(int j=0;j<col-1;j++)
				{
					gl.at<float>(cinza.at<uchar>(i,j),cinza.at<uchar>(i,j+1))++;
				}
		}
    
		gl=gl+gl.t(); 
		gl=gl/sum(gl)[0];
    
		for(int i=0;i<256;i++)
		{
		    for(int j=0;j<256;j++)
			{
          
			    contrast+=(i-j)*(i-j)*gl.at<float>(i,j);

				homogenity=homogenity+gl.at<float>(i,j)/(1+(i-j)*(i-j)); 
				
				dissimilarity+=gl.at<float>(i,j)*(abs(i-j));

				ASM=ASM+(gl.at<float>(i,j)*gl.at<float>(i,j));

				energy=energy+sqrt(ASM);

				if(i!=j)
				{
				    IDM=IDM+gl.at<float>(i,j)/((i-j)*(i-j)); 
				}
				if(gl.at<float>(i,j)!=0)
				{
			        entropy=entropy-gl.at<float>(i,j)*log10(gl.at<float>(i,j));
				}

				mean2+=i*gl.at<float>(i,j);
				mean3+=j*gl.at<float>(i,j);
				omegai+=sqrt(gl.at<float>(i,j)*(i-mean2)*(i-mean2));
				omegaj+=sqrt(gl.at<float>(i,j)*(j-mean3)*(j-mean3));
				if(omegai!=0&&omegaj!=0)
				{
					correlation+=((i*j)*(gl.at<float>(i,j)) - (mean2*mean3)) / (omegai * omegaj);
				}

				variance+=((i-(mean2+mean3)/2)*(i-(mean2+mean3)/2))*gl.at<float>(i,j);

				for (int k = 2; k < 513; k++)
				{
					if (i+j==k && gl.at<float>(k)>0)
					{
						sumEntropy-=(gl.at<float>(k))*log10(gl.at<float>(k));
						sumVariance+=(i-sumEntropy)*(i-sumEntropy)*(gl.at<float>(k));
						sumAverage+=i*gl.at<float>(k);
					}
				}

				for (int k = 0; k < 256; k++)
				{
					if (i-j==k && gl.at<float>(k)>0)
					{
						diferenceEntropy += gl.at<float>(k)*log10(gl.at<float>(k));
						diferenceVariance += (i-(mean2+mean3)/2)*(i-(mean1+mean2)/2)*(gl.at<float>(k));
					}
				}
			}
		}

		fprintf (fp, "%f, ", energy);
		fprintf (fp, "%f, ", contrast);
		fprintf (fp, "%f, ", homogenity);
		fprintf (fp, "%f, ", IDM);
		fprintf (fp, "%f, ", entropy);
		fprintf (fp, "%f, ", dissimilarity);
		fprintf (fp, "%f, ", ASM);
		fprintf (fp, "%f, ", correlation);
		fprintf (fp, "%f, ", diferenceVariance);
		fprintf (fp, "%f, ", diferenceEntropy);
		fprintf (fp, "%f, ", sumEntropy);
		fprintf (fp, "%f, ", sumVariance);
		fprintf (fp, "%f\n", sumAverage);

	}
	fclose (fp);
}
