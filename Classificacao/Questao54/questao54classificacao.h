#include <math.h>
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include <Windows.h>

using namespace cv;
using namespace std;

void leave_one_out (Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable,int *vet_classe_treino,int classes,int num_linhas,int atributos);

void houd_out (Mat normalizado, Mat &treino, Mat &teste, Mat &teste_lable, Mat &treino_lable, int classes, int num_linhas, int tamanho_teste, int tamanho_treino, int* vet_classe, int* vet_classe_treino, int atributos, Mat &lable);

void tamanho (Mat &lable, float &percent_treino,int classes,int num_linhas,int &tamanho_teste,int &tamanho_treino,int *&vet_classe,int *&vet_classe_treino,int *&vet_classe_teste);

void normalizacao (Mat &normalizado, Mat &lable,int atributos,int classes,int num_linhas,char endereco[200]);

void file_configuration(int &atributos,int &num_linhas,int &classes,char endereco[200]);

void k_means (Mat teste, Mat treino, Mat teste_lable, Mat treino_lable, int classes, int num_linhas,  int tamanho_teste, int tamanho_treino, int* vet_classe, int* temp, int atributos, Mat &lable);

