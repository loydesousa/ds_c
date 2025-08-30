#include <stdio.h>
#include <stdlib.h>

//estrutura do nó
typedef struct NO
{
    int dado;
    struct NO *prox;
}NO;

//fila
typedef struct FILA
{
    NO *ini;
    NO *fim;
}FILA;

void inicializaFila(FILA *f){
    f->ini = NULL;
    f->fim = NULL;
}

void enfileira(int dado, FILA *f){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if (ptr == NULL){
        printf("Erro para alocar memória!");
        return;
    }else{
        ptr->dado = dado;
        ptr->prox = NULL;
        if (f->ini == NULL)
        {
            f->ini = ptr;
        }else{
            //caso esteja enfilerando um dado no fim da fila
            f->fim->prox = ptr;
        }
        f->fim = ptr;
    }
}

int desenfileira(FILA *f){
    NO *ptr = f->ini;
    int dado;
    if (ptr != NULL)
    {
        f->ini = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if (f->ini == NULL)
        {
            f->fim = NULL;
        }
        return dado;
    }else{
        printf("Empty Quenue!");
        return;
        }
    
}

void imprimeFila(FILA *f){
    NO *ptr = f->ini;
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
        printf("%d ", ptr->dado);
        ptr = ptr->prox;
        }
        
    }else
    {
        printf("Empty Quenue!");
        return;
    }
    
    
}

int main(){
    //fila chamada
    FILA *f1 = (FILA*) malloc(sizeof(FILA));
     if (f1 == NULL)
     {
        printf("Erro de alocação!");
        exit(-1);
     }
     else{
        inicializaFila(f1);

        enfileira(10, f1);
        enfileira(20, f1);
        enfileira(30, f1);
        enfileira(40, f1);
        enfileira(50, f1);

        imprimeFila(f1);

        printf("Desenfilerando: %d \n", desenfileira(f1));
        imprimeFila(f1);
        printf("\n");
        printf("Desenfilerando: %d \n", desenfileira(f1));
        imprimeFila(f1);
        printf("\n");
        printf("Desenfilerando: %d \n", desenfileira(f1));
        imprimeFila(f1);
        printf("\n");
        printf("Desenfilerando: %d \n", desenfileira(f1));
        imprimeFila(f1);
        printf("\n");
        printf("Desenfilerando: %d \n", desenfileira(f1));
        imprimeFila(f1);
        printf("\n");
     }
     
}