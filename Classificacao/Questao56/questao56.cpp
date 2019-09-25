#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "classificacao.h"

using namespace cv;
using namespace std;

int atributos, num_linhas, classes;
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

	int config = 0;

	if (opcao == 0)
	{
		int* temp = new int[classes];

		for (int i=0; i<classes; i++)
		{
			temp [i] = vet_classe_treino[i];
		}
		houd_out (normalizado, treino, teste, teste_lable, treino_lable, classes, num_linhas, tamanho_teste, tamanho_treino, vet_classe, vet_classe_treino, atributos, lable);
		MLP_Opencv (normalizado,lable,teste,teste_lable,treino,treino_lable, config, atributos, tamanho_teste, tamanho_treino, classes, num_linhas, opcao, vet_classe, vet_classe_treino);
		delete [] temp;
	}
	if (opcao == 1)
	{
		leave_one_out(normalizado,lable,teste,teste_lable,treino,treino_lable,vet_classe_treino,classes,num_linhas,atributos);
		MLP_Opencv (normalizado,lable,teste,teste_lable,treino,treino_lable, config, atributos, tamanho_teste, tamanho_treino, classes, num_linhas, opcao, vet_classe, vet_classe_treino);
	}

	delete [] vet_classe;
	delete [] vet_classe_teste;
	delete [] vet_classe_treino;

	system ("Pause");
	printf ("\n");
	return 0;

}