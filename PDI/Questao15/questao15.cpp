//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

Mat gray; 
Mat frame;
Mat filter;

int main()
{
    VideoCapture cap(0); //Abrir a camera

	if(!cap.isOpened()) //Proteção para abertura da camera
		return 0;

    while (1) 
	{

		cap >> frame; //Capturar a imagem 

		cvtColor (frame, gray, CV_RGB2GRAY); //Converter a imagem para tons de cinza
		Canny(gray, filter, 120, 100, 3);
		imshow ("Video", filter); //Mostrar a imagem

		if(waitKey(30) >= 0) //Dúvida
			break;
	}

	return 0;
}
 
