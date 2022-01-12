#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED

//ESTRUTURA DE DADOS PGM:
typedef struct {
    int c;                  //Número de colunas da imagem
    int l;                  //Número de linhas da imagem
    unsigned char maximo;   //Valor máximo para cada pixel
    unsigned char **imagem; //variável para armazenar os pixels da imagem (matriz)
}PGM;

//ESTRUTURA DA PILHA:
typedef struct C{
    int l; // Linha de um ponto do caminho até a primeira célula de valor 0
    int c; // Coluna de um ponto do caminho até a primeira célula de valor 0
    struct C *proximo; // Ponteiro para a próxima célula da pilha
} Celula;

typedef struct {
    Celula *topo; // Ponteiro para a célula no topo da pilha
} Pilha;


//CABEÇALHO DAS FUNÇÕES:
PGM*LerPGM(char*entrada);
/*-------------------------------------------------------------------------------------------
Protótipo:PGM*LerPGM(char*entrada)
Função: Lê os dados de um arquivo(.pgm) e os salva em uma variável do tipo PGM.
Entrada: A função recebe somente o nome do arquivo da qual ela irá ler os dados.
Saída: Retorna o endereço da variável onde foram armazenados os dados lidos do arquivo.
--------------------------------------------------------------------------------------------*/


void Empilha(Pilha *pilha, Celula* Nova);
/*-------------------------------------------------------------------------------------------
Protótipo: void Empilha(Pilha *pilha, Celula *Nova)
Função: Empilha a posição do pixel passada como parâmetro pela estrutura do tipo Celula Nova.
Entrada: É passado para a função o endereço de uma pilha e o endereço de  e uma estrutura do
tipo Celula que contem as coordenadas de linha e coluna da posição do pixel a ser empilhada.
Saída: A função empilha uma célula contendo a posição do pixel que foi passada e não retorna
nada, pois ela é do tipo void.
--------------------------------------------------------------------------------------------*/


Celula* Desempilha(Pilha *pilha);
/*--------------------------------------------------------------------------------------------
Protótipo: Celula* Desempilha(Pilha *pilha)
Função: Desempilha a a célula topo de uma pilha, cuja qual teve seu endereço passado com
parâmetro.
Entrada: A função recebe o endereço de memória da pilha a qual se deseja desempilhar uma
célula.
Saída: A função desempilha célula do topo e retorna essa primeira célula (célula após a
célula cabeça), que contem coordenadas de um pixel.
--------------------------------------------------------------------------------------------*/


void FPVazia(Pilha *pilha);
/*--------------------------------------------------------------------------------------------
Protótipo: void FPVazia(Pilha *pilha)
Função: Cria uma pilha vazia.
Entrada: Endereço de memória alocado para uma variável pilha do tipo Pilha.
Saída: Pilha composta pela célula cabeça.
--------------------------------------------------------------------------------------------*/


int TestePVazia(Pilha *pilha);
/*--------------------------------------------------------------------------------------------
Protótipo: int TestePVazia(Pilha *pilha)
Função: Checa se a pilha está vazia.
Entrada: Endereço de uma pilha.
Saída: Retorna 1 caso a pilha esteja vazia e 0 caso não esteja.
--------------------------------------------------------------------------------------------*/


unsigned char** alocacao(int lines, int columns);
/*--------------------------------------------------------------------------------------------
Protótipo: unsigned char** alocacao(int lines, int columns)
Função: Realiza alocação dinâmica de matrizes.
Entrada: Recebe o número de linhas e colunas da matriz a ser desalocada.
Saída: Retorna um endereço para onde a memória foi alocada.
--------------------------------------------------------------------------------------------*/


void liberarPGM(PGM* img);
/*--------------------------------------------------------------------------------------------
Protótipo: void liberarPGM(PGM* img)
Função: Libera a memória alocada para a Estrutura e para todas as variáveis que ela possui.
Entrada: Recebe a estrutura a qual se deseja desalocar a memória.
Saída: A função não retorna nada por se tratar de um void.
--------------------------------------------------------------------------------------------*/


void Busca(PGM *img, Pilha *pilha);
/*--------------------------------------------------------------------------------------------
Protótipo: void Busca(PGM *img, Pilha *pilha)
Função: Realiza a busca recursiva do pixel 0 na imagem PGM e armazena na pilha, cujo o endereço
foi passado como parâmetro, o percurso percorrido até encontra-lo.
Entrada: Endereço de uma estrutura PGM contendo a imagem e endereço de uma estrutura Pilha, na
qual será empilhado as células contendo as coordenadas de cada pixel percorrido.
Saída: Caminho da origem, pixel de posição (0,0) até o pixel de módulo 0, empilhado na pilha
cujo o endereço foi passado como parâmetro.
---------------------------------------------------------------------------------------------*/


int BuscaPilha(Pilha* pilha,int linha,int coluna);
/*---------------------------------------------------------------------------------------------
Protótipo: int BuscaPilha(Pilha *pilha, int linha, int coluna)
Função: Verifica se existe, na pilha, uma célula com um determinado par de coordenadas passado
como parâmetros.
Entrada: Endereço de uma estrutura Pilha e variáveis do tipo int que contêm as coordenadas que
definem a posição de um pixel.
Saída: Retorna 1 se a pilha contém uma célula com o par de coordenadas passado como parâmetros
e retorna 0 caso contrário.
----------------------------------------------------------------------------------------------*/


void ImprimeCaminho(Pilha *pilha);
/*---------------------------------------------------------------------------------------------
Protótipo: void ImprimeCaminho(Pilha *pilha)
Função: Imprime na tela o caminho percorrido da origem, ou seja, pixel (0,0), até o pixel de
módulo 0.
Entrada: Endereço de memória alocado para uma variável pilha do tipo Pilha.
Saída: Impressão na tela das coordenadas dos pontos percorridos desde a origem até o pixel 0.
----------------------------------------------------------------------------------------------*/


void LiberaPilha(Pilha* pilha);
/*----------------------------------------------------------------------------------------------
Protótipo: void LiberaPilha(Pilha* pilha)
Função: Liberar a memória da variável do tipo pilha alocada, juntamente com a célula cabeça dessa
pilha. Obs.: A função deve ser chamada apenas quando a pilha já esta vazia(contém apenas a
celula cabeça).
Entrada: Endereço de memória alocado para uma variável pilha do tipo Pilha.
Saída: Memória da variavel pilha desalocada assim como a memória da célula cabeça dessa pilha.
-----------------------------------------------------------------------------------------------*/

#endif // TP1_H_INCLUDED

