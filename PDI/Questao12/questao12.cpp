//Laboratório de Protótipos - LPROT

#include "opencv\cv.h"
#include "opencv\highgui.h"

using namespace std;
using namespace cv;

FILE* fp;
Mat gray;

int main()
{
	 fp = fopen ("resultado.txt", "r");

	 if (!fp)
	 {
		 printf ("Nao foi possivel abrir o arquivo\n");
		 return 0;
	 }

	 /////////////Quantidade de linhas///////////////
	 char nome [100];
	 int quant_linhas = 0;
	 do
	 {
		 quant_linhas++;
	 } while (fgets (nome, 100, fp) != NULL);
	  fclose (fp);

	 ////////////Quantidade de numeros///////////////
     fp = fopen ("resultado.txt", "r");
	 int num;
	 int quant_num = 0;
	 while (!feof (fp))
	 {
		 fscanf (fp, "%d", &num);
		 quant_num++;
	 }
	 fclose (fp);

	 /////////////Quantidade de colunas//////////////
	 int quant_col = (quant_num-1)/quant_linhas;
	 printf ("COLUNAS: %d, LINHAS: %d, NUMEROS: %d\n", quant_col, quant_linhas, quant_num);
	 Mat_<Vec3b> gray (quant_linhas, quant_col, CV_8UC3); /*Pega as propriedades da imagem*/
     ////////////Criar imagem///////////////
	 int x, y;
	 fp = fopen ("resultado.txt", "r");
	 for (y= 0; y < quant_linhas; y++)
	 {
		 for (x = 0; x < quant_col; x++)
		 {
			 fscanf (fp, "%d", &num);
			 gray(y,x)[0] = num;
			 gray(y,x)[1] = num;
			 gray(y,x)[2] = num;
		 }
	 }
	 fclose (fp);


	 imshow ("Imagem em tons de cinza", gray);
     waitKey(0); 

	 system ("Pause");
	 return 0;
}
  
