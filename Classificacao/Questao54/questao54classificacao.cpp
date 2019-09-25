#include "classificacao.h"
#include <time.h>
#include <math.h>

using namespace cv;
using namespace std;

void file_configuration(int &atributos,int &num_linhas,int &classes,char endereco[200])
{
	FILE*fp;
	num_linhas = -1;
	int cont = -1;
	float val;
	int val_2;
	char cont_linhas[5000];
	int ma = 0;
	int x,y;

	fp = fopen (endereco,"r");
	while(!feof(fp))
	{
		fgets (cont_linhas,5000,fp);
		num_linhas++;
	}
	fclose (fp);

	fp=fopen(endereco,"r");
	while(!feof(fp))
	{
		fscanf (fp,"%f,",&val);
		cont++;
	}
	fclose(fp);
	atributos=cont/num_linhas-1;

	fp=fopen(endereco,"r");
	for(x=0;x<num_linhas;x++)
	{
		for(y=0;y<atributos+1;y++)
		{
			if(y==atributos)
			{
				fscanf(fp,"%d",&val_2);
				if(x==0)
				{
					ma=val_2;
				}
				else if(val_2>ma)
				{
					ma=val_2;
				}
			}
			else
			{
				fscanf(fp,"%f,",&val);
			}
		}
	}
	fclose(fp);
	classes = ma+1;
	printf("O numero de classes sao    :  %d\n",classes);
	printf("O numero de atributos sao  :  %d\n",atributos);
}

void normalizacao (Mat &normalizado, Mat &lable,int atributos,int classes,int num_linhas,char endereco[200])
{
	int x,y;
	int val;
	float *vet = new float[atributos];
	float *vet_Max = new float[atributos];
	float *vet_Min = new float[atributos];
	float *vet_Dif = new float[atributos];
	
	FILE*fp=fopen(endereco,"r");
	for(y=0;y<num_linhas;y++)
	{
		for(x=0;x<atributos+1;x++)
		{
			if(x==atributos)
			{
				fscanf(fp,"%d",&val);
				lable.at<float>(y,0)=val;
			}
			else
			{
				fscanf(fp,"%f,",&vet[x]);
				normalizado.at<float>(y,x)=vet[x];
				if(y==0)
				{
					vet_Max[x]=vet[x];
					vet_Min[x]=vet[x];
				}
				else
				{
					if(vet[x]>vet_Max[x])
					{
						vet_Max[x]=vet[x];
					}
					if(vet[x]<vet_Min[x])
					{
						vet_Min[x]=vet[x];
					}
				}
			}
		}
	}
	fclose(fp);
	
	for(x=0;x<atributos;x++)
	{
		vet_Dif[x] = vet_Max[x] - vet_Min[x];
		if (vet_Dif[x]==0)
		{
			vet_Dif[x] = 1;
		}
	}
	
	
	for(y=0;y<num_linhas;y++)
	{
		for(x=0;x<atributos;x++)
		{
			normalizado.at<float>(y,x)= (normalizado.at<float>(y,x) - vet_Min[x])/vet_Dif[x];
		}
	}
	delete[]vet;
	delete[]vet_Dif;
	delete[]vet_Max;
	delete[]vet_Min;
}

void tamanho (Mat &lable,float &percent_treino,int classes,int num_linhas,int &tamanho_teste,int &tamanho_treino,int *&vet_classe,int *&vet_classe_treino,int *&vet_classe_teste)
{
	int x,y;
	vet_classe = new int [classes];
	vet_classe_treino = new int [classes];
	vet_classe_teste = new int [classes];
	int classe;
	percent_treino=percent_treino/100.0;

	for(x=0;x<classes;x++)
	{
		vet_classe[x]=0;
	}
	for(y=0;y<num_linhas;y++)
	{
		classe = (int)lable.at<float>(y,0);
		vet_classe[classe]++;
	}
	
	for(x=0;x<classes;x++)
	{
		vet_classe_treino[x]= percent_treino*vet_classe[x];
		tamanho_treino=vet_classe_treino[x]+tamanho_treino;
	}
	
	for(x=0;x<classes;x++)
	{
		vet_classe_teste[x]= vet_classe[x] - vet_classe_treino[x];
		tamanho_teste=vet_classe_teste[x] + tamanho_teste;
	}
}

void leave_one_out (Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable,int* vet_classe_treino,int classes,int num_linhas,int atributos)
{
	printf("\n\tSTART_Leave_One_Out\n\n");

	int start,end,tmili;
	start=(int)GetTickCount();

	int x,y;
	int x2=0,y2=0;
	int x3=0,y3=0;
	int cont=0;
	int classe;
	for(classe=0;classe<classes;classe++)
	{
		cont=0;
		for(y=0;y<num_linhas;y++)
		{
			x2=0;
			x3=0;
			for(x=0;x<atributos;x++)
			{
				if((lable.at<float>(y,0)==classe)&&(vet_classe_treino[classe]>cont))
				{
					treino.at<float>(y2,x2)=normalizado.at<float>(y,x);
					treino_lable.at<float>(y2,0)=classe;
					x2++;
				}
				else if( (lable.at<float>(y,0)==classe)&&(cont>=vet_classe_treino[classe]) )
				{
					teste.at<float>(y3,x3)=normalizado.at<float>(y,x);
					teste_lable.at<float>(y3,0)=classe;
					x3++;
				}
			}
			if((lable.at<float>(y,0)==classe)&&(vet_classe_treino[classe]>cont))
			{
				y2++;
				cont++;
			}
			else if( (lable.at<float>(y,0)==classe)&&(cont>=vet_classe_treino[classe]) )
			{
				y3++;
				cont++;
			}
		}
	}

	end = (int)GetTickCount();
	tmili = end-start;
	printf("O tempo gasto para leave_one_out foi de : %d milissegundos\n",tmili);
	printf("\t End_Leave_One_Out\n\n");
}

void houd_out (Mat normalizado, Mat &treino, Mat &teste, Mat &teste_lable, Mat &treino_lable, int classes, int num_linhas, int tamanho_teste, int tamanho_treino, int* vet_classe, int* vet_classe_treino, int atributos, Mat &lable)
{

	int y, y1, y2;
	int x;
	int i;
	int* vetor;
	int escolhida;
	int contTreino = 0;
	int classe;

	vetor = new int [num_linhas]; 
	for (i=0; i<num_linhas; i++)
	{
		vetor [i] = 0;
	}

	y1=0;
	srand (time (NULL));
	for (y=0; y<tamanho_treino; y++) 
	{
		do
		{
			escolhida = rand()%num_linhas; // escolho a linha geral
			classe = lable.at<float>(escolhida, 0); // pego a classe
		} while ( vet_classe_treino [classe] < 0 || vetor [escolhida] == 1);

		vetor [escolhida] = 1; //condi��o pra colocar pra teste e treino

		for (x=0; x<atributos+1; x++)
		{
			if (x == atributos)
			{
				treino_lable.at<float>(y1, 0) = lable.at<float>(escolhida, 0);
			}
			else
			{
				treino.at<float>(y1, x) = normalizado.at<float>(escolhida, x);
			}
		}
		y1++;
		vet_classe_treino [classe]--;
	}

	y2=0;
	for (i=0; i<num_linhas; i++)
	{
		if (vetor [i] == 0)
		{
			for (x=0; x<atributos+1; x++)
			{
				if (x == atributos)
				{
					teste_lable.at<float>(y2, 0) = lable.at<float>(i, 0);
				}
				else
				{
					teste.at<float>(y2, x) = normalizado.at<float>(i, x);
				}
			}
			y2++;
		}
	}

	delete [] vetor;

}

void k_means (Mat teste, Mat treino, Mat teste_lable, Mat treino_lable, int classes, int num_linhas,  int tamanho_teste, int tamanho_treino, int* vet_classe, int* temp, int atributos, Mat &lable)
{
	int start,end,tmili;
	start=(int)GetTickCount();

	int x, x2, y, y1, y2, i, k;
	float dif=0;
	int posicao=0;
	float percent_acerto=0;
	float cont_acerto=0;
	float me=0;
	float*vet_comparacao=new float[atributos];
	Mat res (tamanho_teste, 1, CV_32FC1);
	printf("\n\tSTART K_means\n\n");

	float* vetor = new float [atributos];

	Mat auxiliar (classes, atributos, CV_32FC1);
	Mat auxiliar_lable (classes, 1, CV_32FC1);

	FILE* A = fopen ("auxiliar.txt", "w");

	y1 = 0;
	for (i=0; i<classes; i++)
	{
		for (k=0; k<atributos; k++)
		{
			vetor [k] = 0;
		}

		for (y = 0; y < tamanho_treino; y++) /*Para percorrer as linhas da lable pra saber qual � igual a classe*/
		{
			if (i == treino_lable.at<float>(y, 0) ) /* Procuro todos os lables cujo valor � igual a essa classe */
			{
				for (k=0; k<atributos; k++) 
				{
					vetor [k] += treino.at<float>(y, k)/temp[i];
				}

				for (x=0; x<atributos+1; x++)
				{
					if (x==atributos)
					{
						auxiliar_lable.at<float>(y1, 0) = i;
						fprintf (A, "%f\n", auxiliar_lable.at<float>(y1, 0) );
					}
					else
					{
						auxiliar.at<float>(y1, x) = vetor [x];
						fprintf (A, "%f, ",auxiliar.at<float>(y1, x));
					}
				}
			}
		}
		y1++; //atualiza s� quando vai pra uma nova classe
	}

	fclose(A);

	delete [] vetor;

	vet_comparacao = new float [atributos];
	y1=0;
	//(y1=0; y<classes; y++)
	//for (y1=0; y1<tamanho_teste; y1++)
	for (y=0; y<classes; y++)
	{
		me = 0;
		for (x=0; x<atributos; x++)
		{
			vet_comparacao [x] = auxiliar.at<float>(y, x);
		}

		for (y2 = 0; y2 <tamanho_teste; y2++)
		{
			for (x2 = 0; x2<atributos; x2++)
			{
				dif = pow ((vet_comparacao[x2] - teste.at<float>(y2, x2)), 2 ) + dif;
			}
			res.at<float>(y2,0) = sqrt(dif);
			dif=0;
			if(y2 == 0)
			{
				posicao=y2;
				me=res.at<float>(y2,0);
			}
			else if(res.at<float>(y2,0) < me)
			{
				me=res.at<float>(y2,0);
				posicao=y2;
			}
		}

		if ( auxiliar_lable.at<float>(y,0) == teste_lable.at<float>(posicao,0) ) //Posicao do treino que � menor
		{
			cont_acerto++;
		}
	}

	end = (int)GetTickCount();
	tmili = end-start;
	printf("O tempo gasto para o Knn_1 foi de : %d milissegundos\n",tmili);
	printf ("O menor eh: %f\n", me);
	percent_acerto = (cont_acerto/classes);
	printf("Taxa de acerto foi de : %f\n", percent_acerto);
	printf("O percentual de acerto foi de : %f %\n", percent_acerto*100.0);

	auxiliar.release();
	auxiliar_lable.release();
	res.release();

	delete [] vet_comparacao;

	printf("\n\tEND K_means\n\n");
}

