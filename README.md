# Treinamento Inicial do Lapisco

Treinamento para a seleção de novos integrantes do Laboratório de Processamento de Imagens, Sinais e Computação Aplicada (Lapisco). O treinamento inclui os módulos de processamento digital de imagens (PDI), extração de atributos e classificação.

<p align="center">
  <img width="200" height="200" src="https://avatars0.githubusercontent.com/u/44930696?s=280&v=4">
</p>


# Soluções

| Área de estudo  | Descrição  |  C++ |
|---|---|---|
|PDI | Abrir uma imagem colorida, visualizar e salvar | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao01) |
|PDI | Abrir uma imagem colorida, transformar em níveis de cinza, visualizar e salvar imagem gerada. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao02) |
|PDI | Abrir uma imagem colorida em RGB, visualizar e salvar cada um dos canais separadamente. Obs: Busquem compreender o que significa cada um dos canais. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao03) |
|PDI | 	Abrir uma imagem colorida, transformar em HSV, visualizar e salvar cada um dos canais separadamente. Obs: Busquem compreender o que significa cada um dos canais. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao04) |
|PDI | Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Apliquem os filtros passa baixa mediana (cv_median) e media (cv_blur), visualizem os resultados e salvem. Obs: Busquem compreender os resultados de cada filtro. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao05) |
|PDI | Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Apliquem os filtros passa alta de canny (cv_canny), visualizem os resultados e salvem. Obs: Busquem compreender os resultados do filtro. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao06) |
|PDI | Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Apliquem uma limiarização (thresholding), visualizem os resultados e salvem. Obs: Busquem compreender os resultados da técnica. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao07) |
|PDI | Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Apliquem um redimensionamento da imagem, reduzindo e depois aumentando seu tamanho, visualizem os resultados e salvem. Obs: uma imagem 320x240 deve virar uma 160x120 em primeiro caso e 640x480 em segundo caso.| [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao08) |
|PDI | Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Criem uma matriz de forma estática com as mesmas dimensões da imagem de entrada (vejam nas propriedades da imagem no Windows), peguem cada um dos pixels da imagem e coloquem na matriz que criaram. Imprimam esta matriz em um arquivo de texto (.txt) do mesmo modo que ela está alocada. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao09) |
|PDI | Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Criem uma matriz de forma estática com as mesmas dimensões da imagem de entrada (vejam nas propriedades da imagem no Windows), peguem cada um dos pixels da imagem e coloquem na matriz que criaram. Apliquem uma limiarização fazendo uma varredura na matriz. Imprimam esta matriz em um arquivo de texto (.txt) do mesmo modo que ela está alocada. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao10) |
|PDI | Abrir uma imagem colorida com o fundo branco e um quadrado preto centralizado, transformar em tom de cinza, visualizar imagem de entrada. Criem uma matriz de forma estática com as mesmas dimensões da imagem de entrada (vejam nas propriedades da imagem no Windows), peguem cada um dos pixels da imagem e coloquem na matriz que criaram. Calculem as coordenadas (xc,yc) que representam o centróide deste quadrado. Tentem pintar ou marcar ele na imagem para visualização. Xc será a média todas as coordenadas x que fazem parte do quadrado, e yc é as médias de y do quadrado. As coordenadas do quadrado são identificadas pelo tom preto (valor 0). Façam esta imagem de entrada no Paint. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao11) |
|PDI | Abram um arquivo de texto (pode ser o mesmo gerado na questão 10), criem uma imagem em tom de cinza e visualizem esta imagem. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao12) |
|PDI | Abrir uma imagem colorida, transformar em tom de cinza, visualizar imagem de entrada. Criem uma matriz de forma estática com as mesmas dimensões da imagem de entrada (vejam nas propriedades da imagem no Windows). Apliquem uma convolução fazendo uma varredura na matriz utilizando as máscaras do operador gradiente Sobel (procurem no google). Visualizem os resultados e salvem. Obs: Busquem compreender os resultados do operador Sobel (parece com o de canny, apenas parece). | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao13) ||PDI | Abrir uma câmera, capturar uma imagem (frame), transforme em tom de cinza, visualizar imagem de entrada. Continue infinitamente capturando, transformando em tom de cinza e vizualizando. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao14) |
|PDI | Abrir uma câmera, capturar uma imagem (frame), transforme em tom de cinza, visualizar imagem de entrada, aplique o filtro de canny e visualize os resultados. Continue infinitamente capturando, transformando em tom de cinza, aplicando canny e visualizando. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao15) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplicar uma Equalização de histograma utilizando a OpenCv, visualizando a imagem de entrada e seu respectivo histograma inicialmente, e, em seguida, o resultado da equalização e seu histograma. Esta técnica aumenta o contraste da imagem. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao16) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplicar uma Equalização de histograma utilizando apenas o conhecimento de manipulação da imagem, sem a OpenCv, visualizando a imagem de entrada e seu respectivo histograma inicialmente, e, em seguida, o resultado da equalização e seu histograma. Esta técnica aumenta o contraste da imagem. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao17) |
|PDI | 	Abrir uma imagem colorida, transformar para tom de cinza e aplicar o operador gradiente Laplaciano, aplique a técnica de Equalização no resultado obtido na detecção das bordas, onde a maior intensidade de borda seja 255, e a menor intensidade da borda seja 0. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao18) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplicar o operador gradiente Sobel, visualizando a imagem de entrada e seu respectivo histograma inicialmente, e, em seguida, o resultado do operador gradiente e seu histograma. Esta técnica realça melhor as bordas da imagem. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao19) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique a técnica Crescimento de Regiões (Region Growing). Para isto, inicialmente faça uma imagem com dimensões 320x240 no paint, onde o fundo da imagem seja branco e exista um círculo preto no centro. Utilize algum ponto dentro do circulo preto como semente, onde você deve determinar este ponto analisando imagem previamente. A regra de adesão do método deve ser: “Sempre que um vizinho da região possuir tom de cinza menor que 127, devesse agregar este vizinho à região”. Aplique o Crescimento de Regiões de forma iterativa, em que o algoritmo irá estabilizar apenas quando a região parar de crescer. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao20) |
|PDI | 	Faça o mesmo que na questão 21, alterando apenas o modo de inicializar a semente, onde esta deve ser inicializada com um click na imagem apresentada pela OpenCV. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao21) |
|PDI | Faça o mesmo que na questão 22, calculando no final o centroide do objeto segmentado pelo método Crescimento de Regiões 3D, apresentando a região segmentada em azul e o centroide em verde. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao22) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique a técnica Crescimento de Regiões (Region Growing). Para isto, pegue uma imagem qualquer real, com tanto que a mesma possua um objeto se destaque do fundo. Inicialize a semente com um clique neste objeto, conforme na questão 21 e encontre uma regra de adesão que seja capaz de segmentar este objeto. Aplique o Crescimento de Regiões de forma iterativa, em que o algoritmo irá estabilizar apenas quando a região parar de crescer. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao01) ||PDI |  | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao23) |
|PDI | Abrir uma imagem colorida e aplique a técnica Crescimento de Regiões (Region Growing). Para isto, pegue uma imagem qualquer real, com tanto que a mesma possua um objeto se destaque do fundo. Inicialize a semente com um clique neste objeto, conforme na questão 21 e encontre uma regra de adesão que seja capaz de segmentar este objeto. Aplique o Crescimento de Regiões de forma iterativa, em que o algoritmo irá estabilizar apenas quando a região parar de crescer. Este tópico diferenciasse dna questão 23 por ser necessário encontrar uma regra que utilize os canais R, G e B simultanemante. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao24) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique a técnica Crescimento de Regiões (Region Growing). Para isto, faça no paint uma imagem 640x480 com alguns objetos em preto e o fundo seja branco. Neste tópico irão existir mais de um objeto para segmentar, então existe mais de uma região. Inicialize a semente com um clique em cada objeto, em que o primeiro clique rotule o objeto como região 1, pintando a região encontrada de vermelho. Ao terminar de delimitar a região 2, clique em outro objeto, rotulando esta região como 2 e pinte esta região de azul. Faça o mesmo para um terceiro objeto, pintando o mesmo de verde e rotulando sua região como 3. Obs: Ressalto que as regiões que não fazem parte de nenhum objeto devem possuir valor 0. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao25) |
|PDI | Faça o mesmo que na questão 25, entretanto apenas forneça a imagem de entrada, detecte quantos objetos existem de forma automática, rotulando cada região de forma automática, e no final apresente cada objeto encontrado por uma cor distinta. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao26) |
|PDI | Faça o mesmo que na questão 26, entretanto gere subimagens com os objetos detectados e apresente estas subimagens, uma em cada janela. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao27) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique e aplique a limiarização automática da própria Opencv, para que o limiar não dependa da aplicação e nem da luminosidade do local. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao28) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique a transformada de hough para detectar bordas. Faça um desenho no paint que contenha diversos objetos, inclusive um círculo e apenas o círculo deve ser detectado. Obs: Perguntem para o Samuel, ele está trabalhando com isto. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao29) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique a transformada de canny para detectar bordas. Apliquem o método cvFindContours para determinar quantos contornos existem na imagem. Apresentem o resultado obtido e a imagem de entrada. O retorno deve ser a mesma quantidade de objetos existentes.| [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao30) |
|PDI | Após fazer na questão 30, destaque cada objeto encontrado desenhando um retângulo indicando onde os mesmos se encontram. Utilizar a função “cvContourBoundingRect” para determinar cada contorno. Ressalto que é necessário percorrer os contornos encontrados na função “cvFindContours” de forma correta. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao31) |
|PDI | Após fazer na questão 31, calcule a área de cada contorno obtido através da função “cvContourArea”, apresentando seu valor. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao01) ||PDI |  | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao32) |
|PDI | Após fazer na questão 31, gere uma subimagem utilizando o retângulo encontrado para cada objeto ou contorno encontrado. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao33) |
|PDI | Verificar se está ocorrendo acumulo de memória a cada iteração, aprendendo a apagar cada objeto criado quando não usar mais os mesmos. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao34) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique a limiarização de Otsu. Apliquem o método cvDilate de forma iterativa, apresentando o resultado de cada iteração, verificando o que o método causa. O resultado deve ser aumentar as regiões brancas, então se o objeto for branco este método aumentará o objeto. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao35) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique a limiarização de Otsu. Apliquem o método cvErode de forma iterativa, apresentando o resultado de cada iteração, verificando o que o método causa. O resultado deve ser diminuir as regiões brancas, então se o objeto for branco este método diminuirá o objeto. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao36) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique a limiarização de Otsu. Apliquem o método cvDilate de forma iterativa, apresentando o resultado de cada iteração, verificando o que o método causa. Utilize um elemento estruturante com uma linha e três colunas, com a referencia no centro, então o objeto deve crescer apenas na vertical, pois o elemento estruturante é vertical. O objeto deve ser branco e o fundo preto. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao37) |
|PDI | Faça o mesmo que na questão 37, alterando o elemento estruturante e sua referência e verifique o que acontece. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao38) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique a limiarização de Otsu. Apliquem o método cvErode de forma iterativa, apresentando o resultado de cada iteração, verificando o que o método causa. Utilize um elemento estruturante com uma linha e três colunas, com a referencia no centro, então o objeto deve diminuir apenas na vertical, pois o elemento estruturante é vertical. O objeto deve ser branco e o fundo preto. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao39) |
|PDI | Faça o mesmo que questão 39, alterando o elemento estruturante e sua referência e verifique o que acontece. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao40) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique a transformada de canny para detectar bordas. Apliquem a biblioteca CVBlobs para determinar quantos contornos existem na imagem. Apresentem o resultado obtido e a imagem de entrada. O retorno deve ser a mesma quantidade de objetos existentes. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao41) |
|PDI | Abrir uma imagem colorida, transformar para tom de cinza e aplique a transformada de canny para detectar bordas. Apliquem a biblioteca CVBlobs para determinar quantos contornos existem na imagem. Apresentem o resultado obtido e a imagem de entrada. O retorno deve ser a mesma quantidade de objetos existentes. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao42) |
|PDI | Após fazer na questão 42, apresentem cada objeto na imagem, pintando o mesmo ou apresentando quadrados ao seus redor, ou ambos. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao43) |
|PDI | Após fazer o issue 42, gerem subimagens com cada objeto encontrado. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao44) |
|PDI | Após fazer o issue 42, apliquem filtros de altura, largura e área para selecionar apenas os contronos que desejam. Apliquem outros filtros para ver o que acontece. Peçam para imprimir os valor encontrados que dá pra ter uma noção melhor dos valores que devem ser usados nos filtros. | [Solution](https://github.com/lapisco/TreinamentoInicialLapisco/tree/master/PDI/Questao45) |
| Extração | Abrir uma sequência de imagens coloridas,transformar para tom de cinza cada image e obtenha os momentos estatísticos de todas estas imagens. Imprima os resultados de cada imagem em um arquivo e na tela do prompt de comandos. Cada linha do arquivo gerado deve representar os atributos obtidos em uma imagem. | [Solution]() |
| Extração | Abrir uma sequência de imagens coloridas, transformar para tom de cinza cada image e obtenha os momentos centrais de todas estas imagens. Imprima os resultados de cada imagem em um arquivo e na tela do prompt de comandos. Cada linha do arquivo gerado deve representar os atributos obtidos em uma imagem | [Solution]() |
| Extração | Abrir uma sequência de imagens coloridas, transformar para tom de cinza cada image e obtenha os momentos de HU (também conhecidos como momentos invariantes) de todas estas imagens. Imprima os resultados de cada imagem em um arquivo e na tela do prompt de comandos. Cada linha do arquivo gerado deve representar os atributos obtidos em uma imagem. | [Solution]() |
| Extração | Abrir uma sequência de imagens coloridas, transformar para tom de cinza cada image e obtenha os Local Binary Pattern (LBP) de todas estas imagens. Imprima os resultados de cada imagem em um arquivo e na tela do prompt de comandos. Cada linha do arquivo gerado deve representar os atributos obtidos em uma imagem. | [Solution]() |
| Extração | Abrir uma sequência de imagens coloridas, transformar para tom de cinza cada image e obtenha as Texturas de Haralick que são calculadas à partir da matriz de co-ocorrência (GLCM em inglês) de todas estas imagens. Imprima os resultados de cada imagem em um arquivo e na tela do prompt de comandos. Cada linha do arquivo gerado deve representar os atributos obtidos em uma imagem. | [Solution]() |
| Classificação | Utilizar o método Scale Invariant Feature Transform (SIFT) para detectar onde está um objeto conhecido à priori em uma imagem através dos keypoints detectados por este método. Desenhar os keypoints emcomum e marcar o objeto procurado na imagem. (Usar OpenCV 2.4.9) | [Solution]() |
| Classificação | Utilizar o método Speeded Up Robust Features (SURF) para detectar onde está um objeto conhecido à priori em uma imagem através dos keypoints detectados por este método. Desenhar os keypoints em comum e marcar o objeto procurado na imagem. (Usar OpenCV 2.4.9) | [Solution]() |
| Classificação | Implementar o método de classificação do vizinho mais próximo (KNN em inglês) usando os métodos Hold out e Leave One Out. Tudo deve ser feito utilizando a estrutura Mat da OpenCv. Deve ser implementado o KNN com o K igual a 1, 3 e 7. Obs: Não usar as classes de Machine Learning da OpenCV.  | [Solution]() |
| Classificação | Implementar o método de classificação k-médias (K-means em inglês) usando os métodos Hold out e Leave One Out. Tudo deve ser feito utilizando a estrutura Mat da OpenCV. Deve ser implementado o KNN com o K igual a 1, 3 e 7. Obs: Não usar as classes de Machine Learning da OpenCv. | [Solution]() |
| Classificação | Usar o método de classificação pelo vizinho mais próximo (KNN em inglês) usando a biblioteca de Machine Learning da OpenCv. Deve-se fazer com os métodos Hold Out e Leave One Out. Tudo deve ser feito utilizando a estrutura Mat da OpenCV. | [Solution]() |
| Classificação | Usar o método de classificação Multi Layer Perceptron (MLP) usando a biblioteca de Machine Learning da OpenCV. Deve-se fazer com os métodos Hold Out e Leave One Out. Tudo deve ser feito utilizando a estrutura Mat da OpenCV. Faça os testes com no mínimo três topologias distintas da Rede Neural usada. | [Solution]() |
| Classificação | Usar o método de classificação do Support Vector Machine (SVM) usando a biblioteca de Machine Learning da OpenCV. Deve-se fazer com os métodos Hold Out e Leave One Out. Tudo deve ser feito utilizando a estrutura Mat da OpenCV. Faça os testes do SVM com os Kernels Linear, polinomial, Sigmoidal e RBF. | [Solution]() |
| Classificação | Usar o método de classificação de Bayes usando a biblioteca de Machine Learning da OpenCV. Deve-se fazer com os métodos Hold Out e Leave One Out. Tudo deve ser feito utilizando a estrutura Mat da OpenCV. | [Solution]() |
| Classificação | Faça a matriz de confusão para os issues de 53 a 58. | [Solution]() |
| Classificação | Calcule a acurácia, a especificidade e a sensibilidade a partir de cada matriz de confusão obtida na questão 59. | [Solution]() |
| Classificação | Calcule média e desvio padrão dos resultados obtidos no issue 60. | [Solution]() |
| Classificação | Todos os métodos de Machine Learning em um só arquivo (issues 53-58). | [Solution]() |
