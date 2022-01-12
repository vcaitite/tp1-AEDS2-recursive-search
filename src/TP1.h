#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED

//ESTRUTURA DE DADOS PGM:
typedef struct {
    int c;                  //N�mero de colunas da imagem
    int l;                  //N�mero de linhas da imagem
    unsigned char maximo;   //Valor m�ximo para cada pixel
    unsigned char **imagem; //vari�vel para armazenar os pixels da imagem (matriz)
}PGM;

//ESTRUTURA DA PILHA:
typedef struct C{
    int l; // Linha de um ponto do caminho at� a primeira c�lula de valor 0
    int c; // Coluna de um ponto do caminho at� a primeira c�lula de valor 0
    struct C *proximo; // Ponteiro para a pr�xima c�lula da pilha
} Celula;

typedef struct {
    Celula *topo; // Ponteiro para a c�lula no topo da pilha
} Pilha;


//CABE�ALHO DAS FUN��ES:
PGM*LerPGM(char*entrada);
/*-------------------------------------------------------------------------------------------
Prot�tipo:PGM*LerPGM(char*entrada)
Fun��o: L� os dados de um arquivo(.pgm) e os salva em uma vari�vel do tipo PGM.
Entrada: A fun��o recebe somente o nome do arquivo da qual ela ir� ler os dados.
Sa�da: Retorna o endere�o da vari�vel onde foram armazenados os dados lidos do arquivo.
--------------------------------------------------------------------------------------------*/


void Empilha(Pilha *pilha, Celula* Nova);
/*-------------------------------------------------------------------------------------------
Prot�tipo: void Empilha(Pilha *pilha, Celula *Nova)
Fun��o: Empilha a posi��o do pixel passada como par�metro pela estrutura do tipo Celula Nova.
Entrada: � passado para a fun��o o endere�o de uma pilha e o endere�o de  e uma estrutura do
tipo Celula que contem as coordenadas de linha e coluna da posi��o do pixel a ser empilhada.
Sa�da: A fun��o empilha uma c�lula contendo a posi��o do pixel que foi passada e n�o retorna
nada, pois ela � do tipo void.
--------------------------------------------------------------------------------------------*/


Celula* Desempilha(Pilha *pilha);
/*--------------------------------------------------------------------------------------------
Prot�tipo: Celula* Desempilha(Pilha *pilha)
Fun��o: Desempilha a a c�lula topo de uma pilha, cuja qual teve seu endere�o passado com
par�metro.
Entrada: A fun��o recebe o endere�o de mem�ria da pilha a qual se deseja desempilhar uma
c�lula.
Sa�da: A fun��o desempilha c�lula do topo e retorna essa primeira c�lula (c�lula ap�s a
c�lula cabe�a), que contem coordenadas de um pixel.
--------------------------------------------------------------------------------------------*/


void FPVazia(Pilha *pilha);
/*--------------------------------------------------------------------------------------------
Prot�tipo: void FPVazia(Pilha *pilha)
Fun��o: Cria uma pilha vazia.
Entrada: Endere�o de mem�ria alocado para uma vari�vel pilha do tipo Pilha.
Sa�da: Pilha composta pela c�lula cabe�a.
--------------------------------------------------------------------------------------------*/


int TestePVazia(Pilha *pilha);
/*--------------------------------------------------------------------------------------------
Prot�tipo: int TestePVazia(Pilha *pilha)
Fun��o: Checa se a pilha est� vazia.
Entrada: Endere�o de uma pilha.
Sa�da: Retorna 1 caso a pilha esteja vazia e 0 caso n�o esteja.
--------------------------------------------------------------------------------------------*/


unsigned char** alocacao(int lines, int columns);
/*--------------------------------------------------------------------------------------------
Prot�tipo: unsigned char** alocacao(int lines, int columns)
Fun��o: Realiza aloca��o din�mica de matrizes.
Entrada: Recebe o n�mero de linhas e colunas da matriz a ser desalocada.
Sa�da: Retorna um endere�o para onde a mem�ria foi alocada.
--------------------------------------------------------------------------------------------*/


void liberarPGM(PGM* img);
/*--------------------------------------------------------------------------------------------
Prot�tipo: void liberarPGM(PGM* img)
Fun��o: Libera a mem�ria alocada para a Estrutura e para todas as vari�veis que ela possui.
Entrada: Recebe a estrutura a qual se deseja desalocar a mem�ria.
Sa�da: A fun��o n�o retorna nada por se tratar de um void.
--------------------------------------------------------------------------------------------*/


void Busca(PGM *img, Pilha *pilha);
/*--------------------------------------------------------------------------------------------
Prot�tipo: void Busca(PGM *img, Pilha *pilha)
Fun��o: Realiza a busca recursiva do pixel 0 na imagem PGM e armazena na pilha, cujo o endere�o
foi passado como par�metro, o percurso percorrido at� encontra-lo.
Entrada: Endere�o de uma estrutura PGM contendo a imagem e endere�o de uma estrutura Pilha, na
qual ser� empilhado as c�lulas contendo as coordenadas de cada pixel percorrido.
Sa�da: Caminho da origem, pixel de posi��o (0,0) at� o pixel de m�dulo 0, empilhado na pilha
cujo o endere�o foi passado como par�metro.
---------------------------------------------------------------------------------------------*/


int BuscaPilha(Pilha* pilha,int linha,int coluna);
/*---------------------------------------------------------------------------------------------
Prot�tipo: int BuscaPilha(Pilha *pilha, int linha, int coluna)
Fun��o: Verifica se existe, na pilha, uma c�lula com um determinado par de coordenadas passado
como par�metros.
Entrada: Endere�o de uma estrutura Pilha e vari�veis do tipo int que cont�m as coordenadas que
definem a posi��o de um pixel.
Sa�da: Retorna 1 se a pilha cont�m uma c�lula com o par de coordenadas passado como par�metros
e retorna 0 caso contr�rio.
----------------------------------------------------------------------------------------------*/


void ImprimeCaminho(Pilha *pilha);
/*---------------------------------------------------------------------------------------------
Prot�tipo: void ImprimeCaminho(Pilha *pilha)
Fun��o: Imprime na tela o caminho percorrido da origem, ou seja, pixel (0,0), at� o pixel de
m�dulo 0.
Entrada: Endere�o de mem�ria alocado para uma vari�vel pilha do tipo Pilha.
Sa�da: Impress�o na tela das coordenadas dos pontos percorridos desde a origem at� o pixel 0.
----------------------------------------------------------------------------------------------*/


void LiberaPilha(Pilha* pilha);
/*----------------------------------------------------------------------------------------------
Prot�tipo: void LiberaPilha(Pilha* pilha)
Fun��o: Liberar a mem�ria da vari�vel do tipo pilha alocada, juntamente com a c�lula cabe�a dessa
pilha. Obs.: A fun��o deve ser chamada apenas quando a pilha j� esta vazia(cont�m apenas a
celula cabe�a).
Entrada: Endere�o de mem�ria alocado para uma vari�vel pilha do tipo Pilha.
Sa�da: Mem�ria da variavel pilha desalocada assim como a mem�ria da c�lula cabe�a dessa pilha.
-----------------------------------------------------------------------------------------------*/

#endif // TP1_H_INCLUDED

