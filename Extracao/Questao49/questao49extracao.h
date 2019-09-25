#include"opencv\cv.h"
#include"opencv\highgui.h"
#include "opencv2\opencv.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

using namespace cv;
using namespace std;

//void segmentacao (Mat &imagem, Mat &gray, Mat &color, Mat &img, Mat &image);

void escolha (Mat &img, int &num);

//void segmentacao (Mat &gray, Mat &imagem);

void segmentacao (Mat &gray, Mat &img,Mat &teste, Mat &image);