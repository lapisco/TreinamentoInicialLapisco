//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

int main()
{
	Mat color = imread("entrada.png");
	Mat gray;
	cvtColor (color, gray, CV_RGB2GRAY);
	threshold (gray, gray, 127, 255, CV_THRESH_OTSU);
	Mat image;
	int tipo_dilatacao;
	int i;
	Mat element;
	for (i = 0; i < 3; i++)
	{
		if (i == 0)
			tipo_dilatacao = MORPH_RECT;
		else if (i == 1)
			tipo_dilatacao = MORPH_CROSS;
		else if (i == 2)
			tipo_dilatacao = MORPH_ELLIPSE;
		element = getStructuringElement (tipo_dilatacao, Size(30,50), Point( -1, -1 ) );
		dilate (gray, image, element);
		imshow ("SAIDA", image);
		waitKey (0);
	}
	waitKey (0);
	return 0;
}
