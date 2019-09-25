//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

int main ()
{
	Mat color = imread ("teste1.jpg", 1);
	Mat_<uchar> gray (240, 320, 1);
	Mat dst;

	GaussianBlur( color, color, Size(3,3), 0, 0, BORDER_DEFAULT );

	cvtColor (color, gray, CV_RGB2GRAY);
	Mat abs_dst;
	Laplacian (gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT );
	convertScaleAbs( dst, abs_dst );

	int max = gray.at<uchar>(0, 0);
	int min = gray.at<uchar>(0, 0);
	int x, y;
	for (y=0; y<240; y++)
	{
		for (x=0; x<320; x++)
		{
			if (gray.at<uchar>(y, x) < max)
				max = gray.at<uchar>(y, x);
			if (gray.at<uchar>(y, x) > min)
				min = gray.at<uchar>(y, x);
		}
	}

	Mat_<uchar> equalizada (240, 320, 1);
	for (y=0; y<240; y++)
	{
		for (x=0; x<320; x++)
		{
			equalizada.at<uchar>(y,x) = (gray.at<uchar>(y, x) - max)*255/(min-max);
		}
	}

	imshow ("IMAGEM EQUALIZADA", equalizada);
	imshow ("Imagem", abs_dst);
	waitKey (0);
	return 0;
}