#include <stdio.h>
#include <iostream>
#include "opencv2\core\core.hpp"
#include "opencv2\features2d\features2d.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\nonfree\nonfree.hpp"
#include "opencv2\nonfree\features2d.hpp"

using namespace cv;
using namespace std;

int main(){

  Mat img_1 = imread("imagem1.jpg",CV_LOAD_IMAGE_GRAYSCALE);
  Mat img_2 = imread("imagem2.jpg",CV_LOAD_IMAGE_GRAYSCALE);

  Mat img_keypoints_1;
  Mat img_keypoints_2;

  SiftFeatureDetector detector1(100);
  
  vector<KeyPoint> keypoints_1;
  vector<KeyPoint> keypoints_2;
  
  detector1.detect(img_1,keypoints_1);
  detector1.detect(img_2,keypoints_2);

  SiftDescriptorExtractor extractor1;

  Mat descriptors_1, descriptors_2;

  extractor1.compute( img_1, keypoints_1, descriptors_1 );
  extractor1.compute( img_2, keypoints_2, descriptors_2 );

  BFMatcher matcher(NORM_L2);
  vector<DMatch> matches;
  matcher.match( descriptors_1, descriptors_2, matches );

  Mat result;
  drawMatches( img_1, keypoints_1, img_2, keypoints_2, matches, result);

  imshow ("RESULTADO", result );
  imwrite ("Resultado.jpg", result);

  waitKey(0);
  return 0;
}
