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

		vetor [escolhida] = 1; //condição pra colocar pra teste e treino

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

void bayes (Mat tabela, Mat matrizConfusao, int classes, Mat treino, Mat treino_lable, Mat teste, Mat teste_lable, int tamanho_teste)
{
	float percent_acerto=0;
	float percent_erro=0;

	CvNormalBayesClassifier *bayes = new CvNormalBayesClassifier(); 
	bayes->train(treino, treino_lable);

	cv::Mat test_sample;

	int correct_class = 0;
	int wrong_class = 0;

	for (int tsample = 0; tsample < tamanho_teste; tsample++) 
	{
		test_sample = teste.row (tsample);

		int res = (int) (bayes->predict(test_sample));
		int test = (int) (teste_lable.at<float>(tsample,0));

		matrizConfusao.at<float>(res, test)++;

		if (test!=res)
		{              
			wrong_class++;  
        } 
		else 
		{
            correct_class++;
        }
    }

	int x, y;
	FILE* fp = fopen ("matrizconfusao.txt", "w");
	for (y=0; y<classes; y++)
	{
		for (x=0; x<classes; x++)
		{
			if(x==0)
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
			else
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
		}
		fprintf (fp, "\n");
	}

	fclose (fp);
	
	percent_acerto = (float)correct_class/(float)tamanho_teste;
	percent_erro = (float)wrong_class/(float)tamanho_teste;

	printf("Taxa de acerto foi de : %f\n", percent_acerto);
	printf("O percentual de acerto foi de : %f %\n", percent_acerto*100.0);
	
	printf("Taxa de erro foi de : %f\n", percent_erro);
	printf("O percentual de erro foi de : %f %\n", percent_erro*100.0);

	analise (matrizConfusao, tabela, classes);
}

void Knn_1(Mat tabela, Mat matrizConfusao, Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable, int atributos,int tamanho_teste,int tamanho_treino,int classes,int num_linhas,int opcao,int *&vet_classe,int *&vet_classe_treino)
{
	int start,end,tmili;
	start=(int)GetTickCount();

	int x,y;
	int x2,y2;
	float dif=0;
	int posicao=0;
	float percent_acerto=0;
	float cont_acerto=0;
	float me=0;
	float*vet_comparacao=new float[atributos];
	Mat res(tamanho_treino,1,CV_32FC1);
	printf("\n\tSTART KNN_1\n\n");

	for(y=0;y<tamanho_teste;y++)
	{
		me = 0;
		for(x=0;x<atributos;x++)
		{
			vet_comparacao[x]=teste.at<float>(y,x);
		}
		for(y2=0;y2<tamanho_treino;y2++)
		{
			for(x2=0;x2<atributos;x2++)
			{
				dif = pow ((vet_comparacao[x2] - treino.at<float>(y2,x2)), 2) + dif;
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
		if ( treino_lable.at<float>(posicao,0) == teste_lable.at<float>(y,0) )
		{
			cont_acerto++;
		}
		matrizConfusao.at<float>( treino_lable.at<float>(posicao,0) , teste_lable.at<float>(y,0) )++;
	}

	FILE* fp = fopen ("matrizconfusao.txt", "w");
	for (y=0; y<classes; y++)
	{
		for (x=0; x<classes; x++)
		{
			if(x==0)
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
			else
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
		}
		fprintf (fp, "\n");
	}

	fclose (fp);


	end = (int)GetTickCount();
	tmili = end-start;
	printf("O tempo gasto para o Knn_1 foi de : %d milissegundos\n",tmili);
	printf ("O menor eh: %f\n", me);
	percent_acerto = (cont_acerto/tamanho_teste);
	printf("Taxa de acerto foi de : %f\n", percent_acerto);
	printf("O percentual de acerto foi de : %f %\n", percent_acerto*100.0);
	res.release();
	delete [] vet_comparacao;
	printf("\n\tEND KNN_1\n\n");

	analise (matrizConfusao, tabela, classes);
}

void k_means (Mat tabela, Mat matrizConfusao, Mat teste, Mat treino, Mat teste_lable, Mat treino_lable, int classes, int num_linhas,  int tamanho_teste, int tamanho_treino, int* vet_classe, int* temp, int atributos, Mat &lable)
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
	printf("\n\tSTART K-means\n\n");

	float* vetor = new float [atributos];

	Mat auxiliar (classes, atributos, CV_32FC1);
	Mat auxiliar_lable (classes, 1, CV_32FC1);

	y1 = 0;
	for (i=0; i<classes; i++)
	{
		for (k=0; k<atributos; k++)
		{
			vetor [k] = 0;
		}

		for (y = 0; y < tamanho_treino; y++) /*Para percorrer as linhas da lable pra saber qual é igual a classe*/
		{
			if (i == treino_lable.at<float>(y, 0) ) /* Procuro todos os lables cujo valor é igual a essa classe */
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
					}
					else
					{
						auxiliar.at<float>(y1, x) = vetor [x];
					}
				}
			}
		}
		y1++; //atualiza só quando vai pra uma nova classe
	}

	delete [] vetor;

	vet_comparacao = new float [atributos];
	y1=0;

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

		if ( auxiliar_lable.at<float>(y,0) == teste_lable.at<float>(posicao,0) ) //Posicao do treino que é menor
		{
			cont_acerto++;
		}
		matrizConfusao.at<float>(auxiliar_lable.at<float>(y,0) == teste_lable.at<float>(posicao,0) );
	}

	FILE* fp = fopen ("matrizconfusao.txt", "w");
	for (y=0; y<classes; y++)
	{
		for (x=0; x<classes; x++)
		{
			if(x==0)
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
			else
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
		}
		fprintf (fp, "\n");
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

	printf("\n\tEND K-means\n\n");

	analise (matrizConfusao, tabela, classes);
}

void KNN (Mat tabela, Mat matrizConfusao, Mat treino, Mat treino_lable, Mat teste, Mat teste_lable, int tamanho_teste, int classes)
{
	float percent_acerto=0;
	float percent_erro=0;

	FILE* fp = fopen ("matrizconfusao.txt", "w");

	int K;
	int numk;

	printf ("Informe o numeros de vizinhos: ");
	scanf ("%d", &numk);

	K = numk;

	CvKNearest knn(treino, treino_lable, cv::Mat(), false, K);

	int correct_class = 0;
	int wrong_class = 0;
	
	cv::Mat test_sample;

	int x, y;
	for (y=0; y<classes; y++)
	{
		for (x=0; x<classes; x++)
		{
			matrizConfusao.at<float>(y, x) = 0;
		}
	}


	 for (int tsample = 0; tsample < tamanho_teste; tsample++) 
	 {

		 test_sample = teste.row(tsample);

		 int res = knn.find_nearest(test_sample, K);
         int test = (int) (teste_lable.at<float>(tsample,0));

		 matrizConfusao.at<float>(res, test)++;

		 if (test!=res)
         {
             wrong_class++;
         }
		 else 
		 {
              correct_class++;
         }
            
      }

	for (y=0; y<classes; y++)
	{
		for (x=0; x<classes; x++)
		{
			if(x==0)
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
			else
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
		}
		fprintf (fp, "\n");
	}

	fclose (fp);

	percent_acerto = (float)correct_class/(float)tamanho_teste;
	percent_erro = (float)wrong_class/(float)tamanho_teste;

	printf ("\n");
	printf("Taxa de acerto foi de : %f\n", percent_acerto);
	printf("O percentual de acerto foi de : %f %\n", percent_acerto*100.0);

	printf ("\n");
	printf("Taxa de erro foi de : %f\n", percent_erro);
	printf("O percentual de erro foi de : %f %\n", percent_erro*100.0);

	analise (matrizConfusao, tabela, classes);
}

void MLP_Opencv (Mat tabela, Mat matrizConfusao, Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable, int config,int atributos,int tamanho_teste,int tamanho_treino,int classes,int num_linhas,int opcao,int *&vet_classe,int *&vet_classe_treino)
{
	printf("\n\tSTART MLP\n\n");

	int x,y;
	int val;
	char arquivo[200];
	int numHiddenLayer;
	int start,end,tmili;
	int cont_erro = 0;
	int numClassses = classes;
	float cont_acerto = 0,percent_acerto;

	Mat teste_lable_MLP(tamanho_teste,classes,CV_32F);
	Mat treino_lable_MLP(tamanho_treino,classes,CV_32F);

	Mat classificationResult(1, classes, CV_32FC1);
	Mat layers(3,1,CV_32S);
	Mat linha_teste;

	for(y=0;y<tamanho_teste;y++)
	{
		val = (int)teste_lable.at<float>(y,0);
		for(x=0;x<classes;x++)
		{
			if(val==x)
			{
				teste_lable_MLP.at<float>(y,x) = 1.0;
			}
			else
			{
				teste_lable_MLP.at<float>(y,x) = 0;
			}
		}
	}

	for(y=0;y<tamanho_treino;y++)
	{
		val = (int)treino_lable.at<float>(y,0);
		for(x=0;x<classes;x++)
		{
			if(val==x)
			{
				treino_lable_MLP.at<float>(y,x) = 1.0;
			}
			else
			{
				treino_lable_MLP.at<float>(y,x) = 0;
			}
		}
	}

	printf ("Informe a configuracao: ");
	scanf ("%d", &config);

	switch (config) 
	{
	case 1:
		numHiddenLayer = (classes+atributos)/2;
		layers.at<int>(0,0) =atributos;//input layer
        layers.at<int>(1,0)=numHiddenLayer;//hidden layer
        layers.at<int>(2,0) =classes;//output layer
		break;
    case 2:
		numHiddenLayer = (classes+atributos)*2/3;
        layers.at<int>(0,0) = atributos;//input layer
        layers.at<int>(1,0)=numHiddenLayer;//hidden layer
        layers.at<int>(2,0) =classes;//output layer
        break;
	default:
		numHiddenLayer = (classes+atributos)/2;
        layers.at<int>(0,0) = atributos;//input layer
        layers.at<int>(1,0)=numHiddenLayer;//hidden layer
        layers.at<int>(2,0) =classes;//output layer
		break;
	}

	CvANN_MLP nnetwork(layers, CvANN_MLP::SIGMOID_SYM,0.6,1);
	CvANN_MLP_TrainParams params (cvTermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS, 1000, 0.000001), CvANN_MLP_TrainParams::BACKPROP, 0.1, 0.1);
	
	start=(int)GetTickCount();
    int iterations = nnetwork.train(treino,treino_lable_MLP,Mat(),Mat(),params);
	end = (int)GetTickCount();
	tmili = end-start;
	//tempos.at<float>(iteracao*2,0)= (float)tmili;
	printf("O tempo gasto para treino MLP_Opencv foi de : %d milissegundos\n",tmili);
	
	start=(int)GetTickCount();

	for (int y = 0; y<tamanho_teste; y++) 
	{
		
		linha_teste = teste.row(y);
		
		nnetwork.predict(linha_teste, classificationResult);
  
        int maxIndex = 0;
        float value=0.0f;
        float maxValue = classificationResult.at<float>(0,0);
		for(int index=1;index<classes;index++)
		{ 
			value = classificationResult.at<float>(0,index);
            if(value>maxValue)
            {   
				maxValue = value;
				maxIndex=index;
			}
		}
		if (teste_lable_MLP.at<float>(y, maxIndex)!=1.0f)
		{
			cont_erro++;
			//for(int class_index=0;class_index<classes;class_index++)
			//{
			//	if(teste_lable_MLP.at<float>(y, class_index)==1.0f)
			//	{
			//		predict_teste.at<float>(maxIndex,class_index)++;//matriz para fazer matriz confusao
   //                 break;
			//	}
			//}
		}
		else 
		{
			cont_acerto++;
			//predict_teste.at<float>(maxIndex,maxIndex)++;//matriz para fazer matriz confusao
		}
	}

	end = (int)GetTickCount();
	tmili = end-start;
	percent_acerto=(cont_acerto/(float)tamanho_teste);

	//if(iteracao==0)
	//{
	//	nnetwork.save(arquivo);
	//	previous_acc = cont_acerto;
	//}
	//else if ((cont_acerto>previous_acc)&&(iteracao!=0))
	//{
	//	nnetwork.save(arquivo);
	//	previous_acc = cont_acerto;
	//}

	teste_lable_MLP.release();
	treino_lable_MLP.release();
	classificationResult.release();
	linha_teste.release();
	layers.release();

	printf("O tempo gasto para teste MLP_Opencv foi de : %d milissegundos\n",tmili);
	printf("A taxa de acerto foi de : %f\n",percent_acerto);
	printf("O percentual de acerto foi de : %f %\n",percent_acerto*100.0);
	printf("\t END MLP\n\n");

	analise (matrizConfusao, tabela, classes);
}

void SVM_funcao (Mat tabela, Mat matrizConfusao, int classes, Mat treino, Mat treino_lable, Mat teste, Mat teste_lable, int tamanho_teste)
{
	float percent_acerto=0;
	float percent_erro=0;
	int kernell;

	cv::Mat test_sample;

	int correct_class = 0;
	int wrong_class = 0;

	CvSVMParams param = CvSVMParams();
        
        param.svm_type = CvSVM::C_SVC;

		printf ("\n");
		printf ("Fazer o SVM com qual teste: ");
		printf ("\n1 - Linear");
		printf ("\n2 - RBF");
		printf ("\n3 - POLY");
		printf ("\n4 - Sigmoidal");
		printf ("\nOpcao escolhida: ");
        scanf ("%d", &kernell);

        switch (kernell)
		{
            case 1:
                param.kernel_type = CvSVM::LINEAR;
                break;
            case 2:
                param.kernel_type = CvSVM::RBF;
                break;
            case 3:
                param.kernel_type = CvSVM::POLY;
                break;
            case 4:
                param.kernel_type = CvSVM::SIGMOID;
                break;
            default:
                param.kernel_type = CvSVM::LINEAR;
                break;
        }
        
        param.degree = 1; // for poly
        param.gamma = 20; // for poly/rbf/sigmoid
        param.coef0 =10; // for poly/sigmoid
        
        param.C = 7; // for CV_SVM_C_SVC, CV_SVM_EPS_SVR and CV_SVM_NU_SVR
        param.nu = 0.0; // for CV_SVM_NU_SVC, CV_SVM_ONE_CLASS, and CV_SVM_NU_SVR
        param.p = 0.0; // for CV_SVM_EPS_SVR
        
        param.class_weights = NULL; // for CV_SVM_C_SVC
        param.term_crit.type = CV_TERMCRIT_ITER +CV_TERMCRIT_EPS;
        param.term_crit.max_iter = 1000;
        param.term_crit.epsilon = 1e-6;

		CvSVM SVM;

		int op;
		printf ("\n");
		printf ("Deseja fazer o SVM automatico ou nao?\n1 - Sim\n2 - Nao");
		printf ("\nInforme: ");
		scanf ("%d", &op);

		if(op==1)
        {
			int iteractions = SVM.train_auto(treino, treino_lable, cv::Mat(), cv::Mat(), param);
		}
		else
		{
			 int iteractions = SVM.train(treino, treino_lable, cv::Mat(), cv::Mat(), param);
		}

		for (int tsample = 0; tsample < tamanho_teste; tsample++)
        {
            test_sample = teste.row(tsample);

			int res = (int) (SVM.predict(test_sample));
            int test = (int) (teste_lable.at<float>(tsample,0));

			if (test!=res)
            {
                wrong_class++;
            } 
			else 
			{
                correct_class++;
            }
			matrizConfusao.at<float>(res, test)++;
		}

	int x, y;
	FILE* fp = fopen ("matrizconfusao.txt", "w");
	for (y=0; y<classes; y++)
	{
		for (x=0; x<classes; x++)
		{
			if(x==0)
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
			else
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
		}
		fprintf (fp, "\n");
	}

	fclose (fp);
	percent_acerto = (float)correct_class/(float)tamanho_teste;
	percent_erro = (float)wrong_class/(float)tamanho_teste;

	printf ("\n");
	printf("Taxa de acerto foi de : %f\n", percent_acerto);
	printf("O percentual de acerto foi de : %f %\n", percent_acerto*100.0);
	
	printf ("\n");
	printf("Taxa de erro foi de : %f\n", percent_erro);
	printf("O percentual de erro foi de : %f %\n", percent_erro*100.0);

	analise (matrizConfusao, tabela, classes);
}

void Knn_N(Mat tabela, Mat &matrizConfusao,Mat &normalizado,Mat &lable,Mat &teste,Mat &teste_lable,Mat &treino,Mat &treino_lable,int atributos,int tamanho_teste,int tamanho_treino,int classes,int num_linhas,int opcao,int N,int *&vet_classe,int *&vet_classe_treino)
{

	printf("\n\tSTART KNN_%d\n\n",N);
	
	int x,y;
	int x2,y2,y3;
	int maior_rep;
	int predict;
	int cont = 0;
	int classe;
	int start,end,tmili;
	float dif = 0;
	float me  = 0;
	float percent_acerto = 0;
	float cont_acerto = 0;
	
	float*vet_comparacao = new float[atributos];
	int*vet_cont = new int[classes];

	Mat res(tamanho_treino,1,CV_32FC1);
	Mat res_lable_controle(tamanho_treino,1,CV_32FC1);
	
	Mat menores(N,1,CV_32FC1);
	Mat menores_posicoes(N,1,CV_32FC1);

	start=(int)GetTickCount();
	for(y=0;y<tamanho_teste;y++)
	{
		for(x=0;x<atributos;x++)
		{
			vet_comparacao[x]=teste.at<float>(y,x);
		}
		for(y2=0;y2<tamanho_treino;y2++)
		{
			for(x2=0;x2<atributos;x2++)
			{
				dif= pow(vet_comparacao[x2]-treino.at<float>(y2,x2),2) + dif;
			}
			res.at<float>(y2,0)=sqrt(dif);
			dif=0;
		}
		for(y2=0;y2<tamanho_treino;y2++)
		{
			res_lable_controle.at<float>(y2,0)=0;
		}
		for(y3=0;y3<N;y3++)
		{
			cont=0;
			for(y2=0;y2<tamanho_treino;y2++)
			{
				if(res_lable_controle.at<float>(y2,0)==0)//posso fazer a logica para esse numero significa que nao e nenhum dos menores ja encontrados
				{
					if(cont==0)
					{
						menores.at<float>(y3,0)=res.at<float>(y2,0);
						menores_posicoes.at<float>(y3,0)=(float)y2;
						cont++;
					}
					else if(res.at<float>(y2,0)<menores.at<float>(y3,0))
					{
						menores.at<float>(y3,0)=res.at<float>(y2,0);
						menores_posicoes.at<float>(y3,0)=(float)y2;
					}
				}
			}
			res_lable_controle.at<float>((int)menores_posicoes.at<float>(y3,0),0)=1;
		}
		for(x=0;x<classes;x++)
		{
			vet_cont[x]=0;
		}
		for(classe=0;classe<classes;classe++)
		{
			for(y2=0;y2<N;y2++)
			{
				if(treino_lable.at<float>((int)menores_posicoes.at<float>(y2,0),0)==classe)
				{
					vet_cont[classe]++;
				}
			}
		}
		maior_rep = 0;
		for(classe=0;classe<classes;classe++)
		{
			if(classe==0)
			{
				maior_rep = vet_cont[0];
				predict=classe;
			}
			else if(vet_cont[classe]>maior_rep)
			{
				maior_rep = vet_cont[classe];
				predict=classe;
			}
		}
		if(predict==teste_lable.at<float>(y,0))
		{
			cont_acerto++;
		}
		matrizConfusao.at<float>( predict , (int)teste_lable.at<float>(y,0) )++;
	}

	FILE* fp = fopen ("matrizconfusao.txt", "w");
	for (y=0; y<classes; y++)
	{
		for (x=0; x<classes; x++)
		{
			if(x==0)
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
			else
			{
				fprintf (fp, "%.f	", matrizConfusao.at<float>(y, x));
			}
		}
		fprintf (fp, "\n");
	}

	fclose (fp);

	end = (int)GetTickCount();
	tmili = end-start;
	percent_acerto=(cont_acerto/tamanho_teste);

	res.release();
	res_lable_controle.release();
	menores.release();
	menores_posicoes.release();
	delete[]vet_comparacao;
	delete[]vet_cont;

	printf("O tempo gasto para o Knn_%d foi de : %d milissegundos\n",N,tmili);
	printf("A taxa de acerto foi de : %f\n",percent_acerto);
	printf("O percentual de acerto foi de : %f %\n",percent_acerto*100.0);
	printf("\t END KNN_%d\n\n",N);

	analise (matrizConfusao, tabela, classes);
}
			 

void analise (Mat matrizConfusao, Mat tabela, int classes)
{
	int k, w, j, x, y;
	int valor=0, soma=0, soma1=0, soma2=0;

	for (x=0; x<4; x++)
	{
		if (x==0)
		{
			soma=0;
			k=0;
			w=0;
			for (y=0; y<classes; y++)
			{
				tabela.at<float>(y, x) = matrizConfusao.at<float>(k, w);
				k++;
				w++;
			}
		}
		if (x==1)
		{
			soma=0;
			k=0;
			w=0;
			for (y=0; y<classes; y++)
			{
				soma += matrizConfusao.at<float>(k, w);
				k++;
				w++;
			}
			k=0;
			w=0;
			for (y=0; y<classes; y++)
			{
				tabela.at<float>(y, x) = soma - matrizConfusao.at<float>(k, w);
				k++;
				w++;
			}
		}
		if (x==2)
		{
			k=0;
			j=0;
			for (y=0; y<classes; y++)
			{
				soma=0;
				for (w=0; w<classes; w++)
				{
					soma += matrizConfusao.at<float>(k, w);
				}
				tabela.at<float>(y, x) = soma - matrizConfusao.at<float>(k, j);
				k++;
				j++;
			}
		}
		if (x==3)
		{
			w=0;
			j=0;
			for (y=0; y<classes; y++)
			{
				soma=0;
				for (k=0; k<classes; k++)
				{
					soma += matrizConfusao.at<float>(k, w);
				}			
				tabela.at<float>(y, x) =  soma - matrizConfusao.at<float>(j, w);
				w++;
				j++;
			}
		}
	}
	
	FILE* Fh = fopen ("tabela.txt", "w");
	for (y=0; y<classes; y++)
	{
		for (x=0; x<4; x++)
		{
			fprintf (Fh, "%.f	", tabela.at<float>(y, x));
		}
		fprintf (Fh, "\n");
	}
	fclose (Fh);

	float ACC, SPC, TPR;

	FILE* arquivo = fopen ("arquivo.txt", "w");
	for (y=0; y<classes; y++)
	{
		fprintf (arquivo, "Classe %d:\n", y);
		ACC = (tabela.at<float>(y, 0) + tabela.at<float>(y, 1))/(tabela.at<float>(y, 0) + tabela.at<float>(y, 1) + tabela.at<float>(y, 2) + tabela.at<float>(y, 3));
		SPC = tabela.at<float>(y, 1)/(tabela.at<float>(y, 2) + tabela.at<float>(y, 1));
		TPR =  tabela.at<float>(y, 0) / ( tabela.at<float>(y, 0) + tabela.at<float>(y, 3) ) ;
		fprintf (arquivo, "Acurácia = %f\n", ACC);
		fprintf (arquivo, "Especificidade = %f\n", SPC);
		fprintf (arquivo, "Sensibilidade = %f\n", TPR);
		fprintf (arquivo, "\n");
	}
	fclose (arquivo);

//	analise (matrizConfusao, tabela, classes);
}



			 
			 