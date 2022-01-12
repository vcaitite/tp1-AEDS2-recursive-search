#include <stdio.h>
#include <stdlib.h>
#include "TP1.h"

int main(int argc, char*argv[])
{
    PGM *img;
    Pilha *pilha;   //Pilha que ir� guardar o caminho percorrido para alcan�ar o pixel 0.
    img=LerPGM(argv[1]);    //A fun��o recebe como par�metro o nome do arquivo.
    pilha=(Pilha*)malloc(sizeof(Pilha));
    FPVazia(pilha);
    Busca(img,pilha);
    ImprimeCaminho(pilha);
    LiberaPilha(pilha);
    liberarPGM(img);
    return 0;
}
