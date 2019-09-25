#include <stdio.h>
#include <stdlib.h>
#include "opencv\cv.h"
#include <windows.h>
#include "opencv\highgui.h"
#include <time.h>
#include <math.h>

using namespace cv;
using namespace std;

void Knn_1(Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable, int atributos,int tamanho_teste,int tamanho_treino,int classes,int num_linhas,int opcao,int *&vet_classe,int *&vet_classe_treino);

void leave_one_out(Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable,int *&vet_classe_treino,int classes,int num_linhas,int atributos);

void houd_out (Mat normalizado, Mat &treino, Mat &teste, Mat &teste_lable, Mat &treino_lable, int classes, int num_linhas, int tamanho_teste, int tamanho_treino, int* vet_classe, int* vet_classe_treino, int atributos, Mat &lable);

void tamanho (Mat &lable, float &percent_treino,int classes,int num_linhas,int &tamanho_teste,int &tamanho_treino,int *&vet_classe,int *&vet_classe_treino,int *&vet_classe_teste);

void normalizacao (Mat &normalizado, Mat &lable,int atributos,int classes,int num_linhas,char endereco[200]);

void file_configuration(int &atributos,int &num_linhas,int &classes,char endereco[200]);

void Knn_N (Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable,int atributos,int tamanho_teste,int tamanho_treino,int classes,int num_linhas,int opcao,int N, int *&vet_classe,int *&vet_classe_treino);