#include <iostream>
using namespace std;

#if (defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__) || (defined(__APPLE__) & defined(__MACH__)))
#include <opencv\cv.h>
#include <opencv\highgui.h>
#else
#include <opencv/cv.h>
#include <opencv/highgui.h>
#endif

#include <cvblob.h>
using namespace cvb;

/* 
   ABRIR UMA IMAGEM COLORIDA
   TRANSFORMAR PARA TONS DE CINZA
   TRANSFORMADA DE CANNY
   QUANTIDADE DE CONTORNOS COM BLOB
*/

int main()
{
	IplImage *color = cvLoadImage("image1.jpg", 1);

	IplImage *gray = cvCreateImage(cvGetSize(color),8,1);
	

	IplImage *thresholded = cvCreateImage(cvGetSize(color), 8, 1);
	
	cvCvtColor(color,gray,CV_RGB2GRAY);
	cvCanny(gray,gray, 127, 255, 3);
	cvThreshold(gray,thresholded,127,255,CV_THRESH_BINARY);


	IplImage *labelImg = cvCreateImage(cvGetSize(thresholded),IPL_DEPTH_LABEL,1);

    CvBlobs blobs; 

    IplImage *output_blob = cvCreateImage(cvGetSize(color), IPL_DEPTH_8U, 3);
 

    unsigned int result = cvLabel(thresholded, labelImg, blobs);
           
	cvFilterByArea(blobs,1,100000);
  
	printf("%d contornos", blobs.size());

	cvShowImage("Input Image", color);

  cvReleaseImage(&output_blob);
  cvReleaseImage(&gray);
  cvReleaseImage(&labelImg);
  
  cvReleaseBlobs(blobs);

  cvWaitKey(0);
}