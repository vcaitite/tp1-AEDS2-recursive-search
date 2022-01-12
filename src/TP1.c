#include <stdio.h>
#include <stdlib.h>
#include "TP1.h"

PGM* LerPGM(char*entrada)
/*Recebe o nome do arquivo como entrada, realiza a leitura da imagem e
retorna uma instância alocada de forma dinâmica da estrutura
de dados PGM.*/
{
    FILE *arq;
    PGM* img;
    img=(PGM*)malloc(sizeof(PGM));
    int i,j;    //Contadores
    char a,b;   //Variaveis criadas apenas para armazenar "P2" lida do arquivo.
    //Inicializando o ponteiro arq que aponta para o arquivo:
    arq=fopen(entrada,"r");
    if (arq==NULL)
        exit(1);
    fscanf(arq,"%c %c",&a,&b); // Lendo "P2".
    //Lendo o número de linhas, colunas, e o tamanho maáximo dos elementos da matriz:
    fscanf(arq,"%d %d %hhu",&img->c,&img->l,&img->maximo);
    //Alocando memória para a matriz que armazena os pixels da imagem:
    img->imagem = alocacao(img->l,img->c);
    //Lendo os valores do arquivo e salvando em img->imagem:
    for(i=0;i<img->l;i++)
    {
        for(j=0;j<img->c;j++)
        {
            img->imagem[i][j]=0;
            fscanf(arq,"%hhu",&img->imagem[i][j]);
        }
    }
    fclose(arq);
    return (img);
}/* LerPGM */


//FUNÇÃO REALIZA ALOCAÇÃO DINÂMICA DE MATRIZES
unsigned char** alocacao(int lines, int columns)    //Recebe a quantidade de Linhas e Colunas como Parâmetro
{
    int i; //Variável Auxiliar para percorrer as linhas  da matriz
    unsigned char **m;
    m=(unsigned char**)malloc(lines*sizeof(unsigned char*)); //Aloca um Vetor de Ponteiros
    if(m==NULL)
    {
        printf("\n ERRO,MEMORIA NAO ALOCADA!\n\a");
        exit(1);
    }
    for (i = 0; i < lines; i++)//Percorre as linhas do Vetor de Ponteiros
    {
        //Aloca um Vetor de unsigned char para cada posição do Vetor de Ponteiros.
        m[i] = (unsigned char*) malloc(columns*sizeof(unsigned char));
        if(m[i]==NULL)
        {
            printf("\n ERRO,MEMORIA NAO ALOCADA!\n\a");
            exit(1);
        }
    }
    return m; //Retorna o Ponteiro para a Matriz Alocada
}/* alocacao */


/*Função que libera a memória alocada para a Estrutura e para todas as variáveis que ela possui.*/
void liberarPGM(PGM* img)
{
    int aux;    //contador para percorrer as linhas da matriz de pixels.
    for (aux=0;aux<img->l;aux++)
    {
        free(img->imagem[aux]);
    }
    free (img->imagem);
    free (img);
}/* liberarPGM */


 /*Função que recebe o endereço de uma pilha a ser criada e assim faz uma pilha vazia*/
void FPVazia(Pilha *pilha){
    pilha->topo=(Celula*)malloc(sizeof(Celula));
    pilha->topo->proximo = NULL;
}


/*Função que testa se uma pilha está vazia*/
int TestePVazia(Pilha *pilha){
    return (pilha->topo->proximo==NULL);
}


/*Função que empilha uma célula na pilha*/
void Empilha(Pilha *pilha, Celula* celula){
    Celula* Nova;
    Nova=(Celula*)malloc(sizeof(Celula));
    pilha->topo->l = celula->l;
    pilha->topo->c = celula->c;
    Nova->proximo = pilha->topo;
    pilha->topo = Nova; //Nova se torna a célula cabeça
    free(celula);
}


/*Função que Desempilha uma célula e retorna seu endereço de memória*/
Celula* Desempilha(Pilha *pilha){
    if(TestePVazia(pilha)){
        printf("Voce esta tentando desempilhar uma pilha que ja esta vazia");
        exit (1);
    }
    Celula *auxiliar;
    auxiliar = pilha->topo;
    pilha->topo = auxiliar->proximo;
    return pilha->topo; //Retorna a célula que estava anteriormente na primeira posição após a cabeça.
}


/*Realiza a busca recursiva do pixel 0 na imagem PGM e salva o caminho em umA pilha.*/
void Busca(PGM *img, Pilha *pilha){
    int menor;
    Celula* aux;
    Celula* Nova;
    if(pilha->topo->proximo==NULL){ //Empilhando coordenadas da origem.
        Celula* inicial;
        inicial=(Celula*)malloc(sizeof(Celula));
        inicial->l=0;
        inicial->c=0;
        Empilha(pilha,inicial);
    }
    aux = pilha->topo->proximo;
    Nova=(Celula*)malloc(sizeof(Celula));
    if(img->imagem[aux->l][aux->c] == 0){
        return;
    }
    else{
        //Testando se é possivel andar para a direita e se o pixel da direita ainda não foi percorrido:
        if(aux->c < img->c-1 && !(BuscaPilha(pilha,aux->l,aux->c+1))){
            menor = img->imagem[aux->l][aux->c+1];
            Nova->l=aux->l;
            Nova->c=aux->c+1;
        }
        else
            menor = 256;    //Valor Inválido(Valor que garante que a função percorra um caminho ou para baixo, ou para esquerda ou para direita).
        //Testando se é possivel andar para a baixo e se o pixel de baixo ainda não foi percorrido:
        if((aux->l < img->l-1) && !(BuscaPilha(pilha,aux->l+1,aux->c))){
            if (menor > img->imagem[aux->l+1][aux->c]){
                menor=img->imagem[aux->l+1][aux->c];
                Nova->l=aux->l+1;
                Nova->c=aux->c;
            }
        }
        //Testando se é possivel andar para a esquerda e se o pixel da esquerda ainda não foi percorrido:
        if(aux->c > 0 && !(BuscaPilha(pilha,aux->l,aux->c-1))){
            if(menor > img->imagem[aux->l][aux->c-1]){
                menor=img->imagem[aux->l][aux->c-1];
                Nova->l=aux->l;
                Nova->c=aux->c-1;
            }
        }
        //Testando se é possivel andar para cima e se o pixel a cima ainda não foi percorrido:
        if(aux->l > 0 && !(BuscaPilha(pilha,aux->l-1,aux->c))){
            if(menor > img->imagem[aux->l-1][aux->c]){
                menor=img->imagem[aux->l-1][aux->c];
                Nova->l=aux->l-1;
                Nova->c=aux->c;
            }
        }
        Empilha(pilha, Nova); //Empilhando uma celula que contem as coordenadas do pixel a ser percorrido(que possui valor de menor módulo)
        Busca(img, pilha);  //Cgamando a função recursiva.
    }
}


/*Função que recebe uma pilha e imprime seus elementos de maneiro que o elemento do topo seja o ultimo a ser impresso  */
void ImprimeCaminho(Pilha *pilha){
    Pilha *pilha_aux;   //Pilha usada para inverter a ordem a ser impressa.
    Celula* tmp;
    pilha_aux=(Pilha*)malloc(sizeof(Pilha));
    FPVazia(pilha_aux);
    while(pilha->topo->proximo!=NULL){
        Empilha(pilha_aux,Desempilha(pilha));
    }
    tmp=Desempilha(pilha_aux);
    printf("(%d,%d)",tmp->l,tmp->c);
    free(tmp);
    while(pilha_aux->topo->proximo!=NULL){
        tmp=Desempilha(pilha_aux);
        printf(", (%d,%d)",tmp->l,tmp->c);
        free(tmp); //Liberando Memória de cada Célula.
    }
    LiberaPilha(pilha_aux); //Libera memória da variavel do tipo pilha e ainda da sua célula cabeça.
}

int BuscaPilha(Pilha* pilha,int linha,int coluna){
    Celula* aux=pilha->topo->proximo;
    while(aux!=NULL){
        if(aux->l==linha && aux->c==coluna)
            return 1;
        aux=aux->proximo;
    }
    free(aux);
    return 0;
}

/*Função que libera memoria da variável do tipo pilha alocada, juntamente com a célula cabeça dessa pilha.
A função deve ser chamada apenas quando a pilha já esta vazia(contém apenas a celula cabeça)*/
void LiberaPilha(Pilha* pilha)
{
    free(pilha->topo);
    free(pilha);
}
