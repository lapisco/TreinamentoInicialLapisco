#include <math.h>
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include <Windows.h>
#include "opencv2/ml/ml.hpp"

using namespace cv;
using namespace std;

void leave_one_out (Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable,int *vet_classe_treino,int classes,int num_linhas,int atributos);

void houd_out (Mat normalizado, Mat &treino, Mat &teste, Mat &teste_lable, Mat &treino_lable, int classes, int num_linhas, int tamanho_teste, int tamanho_treino, int* vet_classe, int* vet_classe_treino, int atributos, Mat &lable);

void tamanho (Mat &lable, float &percent_treino,int classes,int num_linhas,int &tamanho_teste,int &tamanho_treino,int *&vet_classe,int *&vet_classe_treino,int *&vet_classe_teste);

void normalizacao (Mat &normalizado, Mat &lable,int atributos,int classes,int num_linhas,char endereco[200]);

void file_configuration(int &atributos,int &num_linhas,int &classes,char endereco[200]);

void Knn_1(Mat matrizConfusao, Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable, int atributos,int tamanho_teste,int tamanho_treino,int classes,int num_linhas,int opcao,int *&vet_classe,int *&vet_classe_treino);

void KNN (Mat matrizConfusao, Mat treino, Mat treino_lable, Mat teste, Mat teste_lable, int tamanho_teste, int classes);

void MLP_Opencv (Mat matrizConfusao, Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable, int config,int atributos,int tamanho_teste,int tamanho_treino,int classes,int num_linhas,int opcao,int *&vet_classe,int *&vet_classe_treino);

void SVM_funcao (Mat matrizConfusao, int classes, Mat treino, Mat treino_lable, Mat teste, Mat teste_lable, int tamanho_teste);

void bayes (Mat matrizConfusao, int classes, Mat treino, Mat treino_lable, Mat teste, Mat teste_lable, int tamanho_teste);

void Knn_N (Mat &matrizConfusao,Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable,int atributos,int tamanho_teste,int tamanho_treino,int classes,int num_linhas,int opcao,int N, int *&vet_classe,int *&vet_classe_treino);

void k_means (Mat matrizConfusao, Mat teste, Mat treino, Mat teste_lable, Mat treino_lable, int classes, int num_linhas,  int tamanho_teste, int tamanho_treino, int* vet_classe, int* temp, int atributos, Mat &lable);