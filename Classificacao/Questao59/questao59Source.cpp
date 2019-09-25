#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "classificacao.h"

using namespace cv;
using namespace std;

int atributos, num_linhas, classes, config=0, N;
char endereco [200];

int main ()
{
	sprintf (endereco, "teste_5.txt");

	file_configuration (atributos, num_linhas, classes, endereco);

	Mat lable (num_linhas, 1, CV_32FC1);

	Mat normalizado (num_linhas, atributos, CV_32FC1);

	normalizacao (normalizado, lable, atributos, classes, num_linhas, endereco);
	
	int tamanho_teste = 0;
	int tamanho_treino = 0;

	float percent_treino;

	printf ("Insira o percentual de treino: ");
	scanf ("%f", &percent_treino);

	int* vet_classe;
	int* vet_classe_treino;
	int* vet_classe_teste;

	tamanho (lable,percent_treino, classes, num_linhas, tamanho_teste, tamanho_treino, vet_classe, vet_classe_treino, vet_classe_teste);

	Mat teste (tamanho_teste, atributos, CV_32FC1);
	Mat treino (tamanho_treino, atributos, CV_32FC1);
	Mat treino_lable (tamanho_treino, 1, CV_32FC1);
	Mat teste_lable (tamanho_teste, 1, CV_32FC1);

	int opcao;

	printf ("Insira a opcao da classificacao: ");
	printf ("\n0 -> houd_out");
	printf ("\n1 -> leave_one_out");
	printf ("\nDigite: ");
	scanf ("%d", &opcao);
	
	if (opcao == 0)
	{
		int* temp = new int[classes];

		for (int i=0; i<classes; i++)
		{
			temp [i] = vet_classe_treino[i];
		}
		houd_out (normalizado, treino, teste, teste_lable, treino_lable, classes, num_linhas, tamanho_teste, tamanho_treino, vet_classe, vet_classe_treino, atributos, lable);
		delete [] temp;
	}
	if (opcao == 1)
	{
		leave_one_out(normalizado,lable,teste,teste_lable,treino,treino_lable,vet_classe_treino,classes,num_linhas,atributos);
	}

	int tipo;

	printf ("Opcoes de classificacao\n");
	printf ("1 - KNN manual\n");
	printf ("2 - K-means\n");
	printf ("3 - KNN Opencv\n");
	printf ("4 - MLP\n");
	printf ("5 - SVM\n");
	printf ("6 - KNN-N\n");
	printf ("7 - Bayes\n");
	printf ("Digite: ");
	scanf ("%d", &tipo);

	Mat matrizConfusao (classes, classes, CV_32FC1);

	int x, y;
	for (y=0; y<classes; y++)
	{
		for (x=0; x<classes; x++)
		{
			matrizConfusao.at<float>(y, x) = 0;
		}
	}


	switch (tipo)
	{
		case 1:
			Knn_1 (matrizConfusao, normalizado, lable, teste,teste_lable,treino, treino_lable, atributos,tamanho_teste,tamanho_treino,classes,num_linhas,opcao, vet_classe, vet_classe_treino);
		break;
		case 2: 
			k_means (matrizConfusao, teste, treino, teste_lable, treino_lable, classes, num_linhas,  tamanho_teste, tamanho_treino, vet_classe, vet_classe_treino, atributos, lable);
		break;
		case 3:
			KNN (matrizConfusao, treino, treino_lable, teste, teste_lable, tamanho_teste, classes);
		break;
		case 4:
			MLP_Opencv (matrizConfusao, normalizado,lable,teste,teste_lable,treino,treino_lable, config, atributos, tamanho_teste, tamanho_treino, classes, num_linhas, opcao, vet_classe, vet_classe_treino);
		break;
		case 5:
			SVM_funcao (matrizConfusao, classes, treino, treino_lable, teste, teste_lable, tamanho_teste);
		break;
		case 6:
			printf ("Quantos vizinhos: ");
			scanf ("%d\n", &N);
			Knn_N(matrizConfusao,normalizado,lable,teste,teste_lable,treino,treino_lable,atributos,tamanho_teste,tamanho_treino,classes,num_linhas,opcao,N,vet_classe,vet_classe_treino);
		break;
		case 7:
			bayes (matrizConfusao, classes, treino, treino_lable, teste, teste_lable, tamanho_teste);
		break;
	}


	delete [] vet_classe;
	delete [] vet_classe_teste;
	delete [] vet_classe_treino;

	system ("Pause");
	printf ("\n");
	return 0;

}