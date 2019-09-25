//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace cv;
using namespace std;

int main()
{
  Mat img, gray;
  Mat grad;
  
  img = imread("image1.jpg",1);
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

  imshow("window_name", grad);

  waitKey(0);

  return 0;
}



