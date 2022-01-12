#include <stdio.h>
#include <stdlib.h>
#include "TP1.h"

int main(int argc, char*argv[])
{
    PGM *img;
    Pilha *pilha;   //Pilha que irá guardar o caminho percorrido para alcançar o pixel 0.
    img=LerPGM(argv[1]);    //A função recebe como parâmetro o nome do arquivo.
    pilha=(Pilha*)malloc(sizeof(Pilha));
    FPVazia(pilha);
    Busca(img,pilha);
    ImprimeCaminho(pilha);
    LiberaPilha(pilha);
    liberarPGM(img);
    return 0;
}
