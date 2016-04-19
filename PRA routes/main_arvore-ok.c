#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabecalho.h"

#define ERRO_FILA_VAZIA -1



void inicializaFila(FilaEncadeada *f, int tamanho);
int inserir(FilaEncadeada *f, void *info);
int remover(FilaEncadeada *f, void *info);
int filaVazia(FilaEncadeada f);
void limpaFila(FilaEncadeada *f);
void mostraFila(FilaEncadeada f, void (*mostraInfo)(void *) );





void inicializa_ABP(ABP *a, int t);
void insere_ABP(ABP *a, void *info, int (*compara_info)(void *, void *) );
void remove_ABP(ABP *a, void *info, int (*compara_info)(void *, void *) );
void limpa_ABP(ABP *a);
int busca_APB(ABP a, void *chave, int (*compara_info)(void *, void *) );
void percurso_pre_ordem(ABP a, void (*mostra_info)(void *) );
void percurso_em_ordem(ABP a, void (*mostra_info)(void *) );
void percurso_pos_ordem(ABP a, void (*mostra_info)(void *) );
void percurso_em_largura(ABP a, void (*mostra_info)(void *) );
void mostra_estrutura(ABP a, void (*mostra_info)(void *) );

int altura(NoABP *n);


void mostra_int(void *info);
int compara_int(void *a, void *b);

/*
int main(int argc, char *argv[])
{
   ABP *arvore;
   /*
   inicializa_ABP(arvore, sizeof(int));
   percurso_em_ordem(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");
   
   int x = 10;
   void *info = &x;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(arvore, info, compara_int);
   mostra_estrutura(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");

   x = 5;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(arvore, info, compara_int);
   mostra_estrutura(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");

   x = 8;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(arvore, info, compara_int);
   mostra_estrutura(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");

   x = 7;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(arvore, info, compara_int);
   mostra_estrutura(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");

   x = 20;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(arvore, info, compara_int);
   mostra_estrutura(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");

   x = 15;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(arvore, info, compara_int);
   mostra_estrutura(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");
   
   x = 25;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(arvore, info, compara_int);
   mostra_estrutura(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");
   
   x = 7;
   printf("Removendo %i...\n\n", x);
   remove_ABP(arvore, &x, compara_int);   
   mostra_estrutura(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");
   
   percurso_em_ordem(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");
   
   percurso_pre_ordem(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");
   
   percurso_pos_ordem(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");

   percurso_em_largura(*arvore, mostra_int);
   system("PAUSE");
   system("CLS");

   int y;
   printf("Digite um valor:\n");
   scanf("%i", &y);
   printf("Buscando %i...\n\n", y);
   if(busca_APB(*arvore, &y, compara_int))
      printf("%i encontrado!!\n\n", y);
   else
      printf("%i nao encontrado!!\n\n", y);
   system("PAUSE");
   system("CLS");

   printf("Limpando arvore...\n\n");
   limpa_ABP(arvore);
   percurso_em_ordem(*arvore, mostra_int);
   mostra_estrutura(*arvore, mostra_int);
	
   printf("Fim da demosntracao.\n\n");
   system("PAUSE");
   return 0;
}
*/
void mostra_int(void *info){
   int *p = (int *) info;
   printf("%i\n", *p);
}

int compara_int(void *a, void *b){
    int *pa = (int *) a;
    int *pb = (int *) b;
    
    if(*pa > *pb)
       return 1;

    if(*pa < *pb)
       return -1;

    return 0;
}

/*-------------------------------- FILA ENCADEADA FUNCTIONS -------------------------------*/
/*-----------------------------------------------------------------------------------------*/
void inicializaFila(FilaEncadeada *f, int tamanho){
   f->tamanhoInfo = tamanho;
   f->inicio = NULL;
   f->fim = NULL;
}

Elemento *aloca_e_copia(void *info, int tamanho){
   Elemento *p = (Elemento *) malloc(sizeof(Elemento));
   if(p == NULL)
      return 0; // Erro, falta de memória!
   p->info = malloc(tamanho);
   if(p->info == NULL){
      free(p);
      return 0; // Erro, falta de memória!
   }
   memcpy(p->info, info, tamanho);
   return p;
}

int inserir(FilaEncadeada *f, void *info){
   Elemento *novo = aloca_e_copia(info, f->tamanhoInfo);
   if(novo == NULL)
      return 0;

   if(f->inicio == NULL)
      f->inicio = novo;
   else
      f->fim->proximo = novo;
   
   novo->proximo = NULL;
   f->fim = novo;
   return 1;
}

int remover(FilaEncadeada *f, void *info){
   if(f->inicio == NULL)
      return ERRO_FILA_VAZIA;

   Elemento *p = f->inicio;
   f->inicio = p->proximo;   
   if(p->proximo == NULL)
      f->fim = NULL;
  
   memcpy(info, p->info, f->tamanhoInfo);
   free(p->info);
   free(p);
   return 1;
}

int filaVazia(FilaEncadeada f){
   return f.inicio == NULL;
}

void limpaFila(FilaEncadeada *f){
   Elemento *p = f->inicio;
   while(p != NULL){
      Elemento *aux = p->proximo;
      free(p->info);
      free(p);
      p = aux;
   }
   f->inicio = NULL;
   f->fim = NULL;
}

void mostraFila(FilaEncadeada f, void (*mostraInfo)(void *) ){
   if( filaVazia(f) ){
      printf("Fila vazia!\n");
   }
   else{
      printf("Dados da fila:\n");
      Elemento *p = f.inicio;
      while(p != NULL){
         (*mostraInfo)(p->info); // Invocação por callback
         p = p->proximo;
      }
   }
   printf("----------------------\n\n");
} 

/*-------------------------------- FILA ENCADEADA FUNCTIONS -------------------------------*/
/*-----------------------------------------------------------------------------------------*/


// ------------------------------------- private ABP --------------------------------------
/*-----------------------------------------------------------------------------------------*/
NoABP *inicializa_no_ABP(void *info, int t){
  NoABP *p = (NoABP *) malloc(sizeof(NoABP));
  if(p == NULL)
     return NULL;
  p->info = malloc(t);
  if(p->info == NULL){
     free(p);
     return NULL;
  }
  memcpy(p->info, info, t);
  p->esq = NULL;
  p->dir = NULL;
  p->pai = NULL;
  p->fb = 0;
  return p;
}

int insere_no_ABP(NoABP *n, void *info, int t, int (*compara_info)(void *, void *) ){
   if (n == NULL)
      return 0; // não achou.
      
   if ((*compara_info)(info, n->info) < 0){
     int achou = insere_no_ABP(n->esq, info, t, (*compara_info) );
     if(!achou){
        n->esq = inicializa_no_ABP(info, t);
        n->esq->pai = n;
     }
     return 1; // propaga que foi inserido.
   }
   
   if ((*compara_info)(info, n->info) > 0){
     int achou = insere_no_ABP(n->dir, info, t, (*compara_info) );
     if(!achou){
        n->dir = inicializa_no_ABP(info, t);
        n->dir->pai = n;
     }
     return 1; // propaga que foi inserido.
   }
   
   
   return 1; // achou
}

NoABP *procura_menor_a_direita(NoABP *n){
   while(n->esq != NULL)
      n = n->esq;
   return n;
}

void troca_info(NoABP *a, NoABP *b){
   void *temp = a->info;
   a->info = b->info;
   b->info = temp;
}

void arruma_ponteiros_pai(NoABP *n, NoABP *filho){
   NoABP *pai = n->pai;

   if(pai != NULL){
      if(pai->esq == n)
         pai->esq = filho;
      else
         pai->dir = filho;
   }

   if(filho != NULL)
      filho->pai = pai;
}

void remove_no_simples(NoABP *n){

   if(n->esq == NULL && n->dir == NULL) // nó folha
      arruma_ponteiros_pai(n, NULL);
   else 
      if(n->esq != NULL) // nó com um filho à esquerda
         arruma_ponteiros_pai(n, n->esq);
      else // nó com um filho à direita
         arruma_ponteiros_pai(n, n->dir);

   free(n->info);
   free(n);
}

NoABP *busca_ABP_rec(NoABP *n, void *chave, int (*compara_info)(void *, void *) ){
   if (n == NULL)
      return NULL;

   if ((*compara_info)(chave, n->info) < 0)
      return busca_ABP_rec(n->esq, chave, (*compara_info));

   if ((*compara_info)(chave, n->info) > 0)
      return busca_ABP_rec(n->dir, chave, (*compara_info));

   return n;
}

void limpa_pos_ordem(NoABP *n){
   if(n != NULL){
      limpa_pos_ordem(n->esq);
      limpa_pos_ordem(n->dir);
      free(n->info);
      free(n);
   }
}

void pre_ordem(NoABP *n, void (*mostra_info)(void *) ){
   if(n != NULL){
      (*mostra_info)(n->info);
      pre_ordem(n->esq, (*mostra_info) );
      pre_ordem(n->dir, (*mostra_info) );
   }
}

void em_ordem(NoABP *n, void (*mostra_info)(void *) ){
   if(n != NULL){
      em_ordem(n->esq, (*mostra_info) );
      (*mostra_info)(n->info);
      em_ordem(n->dir, (*mostra_info) );
   }
}

void pos_ordem(NoABP *n, void (*mostra_info)(void *) ){
   if(n != NULL){
      pos_ordem(n->esq, (*mostra_info) );
      pos_ordem(n->dir, (*mostra_info) );
      (*mostra_info)(n->info);
   }
}

void pre_ordem_modificado(NoABP *n, int nivel, void (*mostra_info)(void *) ){
   int i;
   for(i=0; i<nivel-1; i++)
      printf("    ");
   printf("+---");

   if(n != NULL){
      (*mostra_info)(n->info);
      pre_ordem_modificado(n->esq, nivel+1, (*mostra_info) );
      pre_ordem_modificado(n->dir, nivel+1, (*mostra_info) );
   }
   else
      printf("(null)\n");
}

int altura(NoABP *n){
   if(n == NULL)
      return 0;
   else{
      if(n->esq == NULL && n->dir == NULL)
         return 1;
      else{
         int esq = altura(n->esq);
         int dir = altura(n->dir);
         if(esq > dir)
            return 1 + esq;
         else
            return 1 + dir;
      }
   }
}

NoABP *verifica_balanceamento(NoABP *n){
   if(n != NULL){
      
      NoABP *p = verifica_balanceamento(n->esq);
      if(p != NULL)
         return p;
      
      p = verifica_balanceamento(n->dir);
      if(p != NULL)
         return p;
      
      n->fb = altura(n->esq) - altura(n->dir);
      if(n->fb == 2 || n->fb == -2)
         return n;
   }
   return NULL;
}

void rotacao_a_direita(NoABP *pai, NoABP *filho, ABP *a){

   pai->esq = filho->dir; // pai desce e 'adota' filho do filho
   if(pai->esq != NULL)
      pai->esq->pai = pai;
   
   filho->dir = pai;      // filho sobe e se torna o pai
   filho->pai = pai->pai;
   pai->pai = filho;
   
   NoABP *avo = filho->pai;  // caso exista um 'avo', arrumar os ponteiros
   if(avo != NULL){
      if(avo->esq == pai)
         avo->esq = filho;
      else
         avo->dir = filho;
   }
   else                    // caso contrario, o filho (que subiu), se torna o raiz
      a->raiz = filho;
}

void rotacao_a_esquerda(NoABP *pai, NoABP *filho, ABP *a){
   pai->dir = filho->esq;
   if(pai->dir != NULL)
      pai->dir->pai = pai;
   
   filho->esq = pai;
   filho->pai = pai->pai;
   pai->pai = filho;
   
   NoABP *avo = filho->pai;
   if(avo != NULL){
      if(avo->esq == pai)
         avo->esq = filho;
      else
         avo->dir = filho;
   }
   else
      a->raiz = filho;
}

void executa_balancemanto(NoABP *n, ABP *a){
   if(n->fb > 0){ // rotação à direita
      if(n->esq->fb < 0){ // dupla
         printf("Rotacao dupla a direita...\n");
         rotacao_a_esquerda(n->esq, n->esq->dir, a);
         rotacao_a_direita(n, n->esq, a);
      }
      else{ // simples
         printf("Rotacao simples a direita...\n");
         rotacao_a_direita(n, n->esq, a);
      }
   }
   else{ // rotação à esquerda
      if(n->dir->fb > 0){ // dupla
         printf("Rotacao dupla a esquerda...\n");
         rotacao_a_direita(n->dir, n->dir->esq, a);
         rotacao_a_esquerda(n, n->dir, a);
      }
      else{ // simples
         printf("Rotacao simples a esquerda...\n");
         rotacao_a_esquerda(n, n->dir, a);
      }
   }
}
// ------------------------------------- private ABP --------------------------------------
/*-----------------------------------------------------------------------------------------*/

// ------------------------------------- public ABP ---------------------------------------
/*-----------------------------------------------------------------------------------------*/
void inicializa_ABP(ABP *a, int t){
   a->tamanhoInfo = t;
   a->raiz = NULL;
}

void insere_ABP(ABP *a, void *info, int (*compara_info)(void *, void *) ){
    if(a->raiz == NULL)
       a->raiz = inicializa_no_ABP(info, a->tamanhoInfo);
    else{
       insere_no_ABP(a->raiz, info, a->tamanhoInfo, (*compara_info) );

       // ******** Verifica balanceamento ********
       NoABP *p = verifica_balanceamento(a->raiz);
       if(p != NULL){
          executa_balancemanto(p, a);
       }
       // ****************************************
    }
}

void remove_ABP(ABP *a, void *info, int (*compara_info)(void *, void *) ){
     NoABP *n = busca_ABP_rec(a->raiz, info, (*compara_info) );
     
     if(n->esq != NULL && n->dir != NULL){ // nó com 2 filhos
        NoABP *menor = procura_menor_a_direita(n->dir);
        troca_info(n, menor);
        n = menor; // a aponta para o menor, que será removido a seguir.
     }
     
     remove_no_simples(n);

     // ******** Verifica balanceamento ********
     NoABP *p = verifica_balanceamento(a->raiz);
     while(p != NULL ){
        executa_balancemanto(p, a);
        p = verifica_balanceamento(a->raiz);
     }
     // ****************************************
}

int busca_APB(ABP a, void *chave, int (*compara_info)(void *, void *) ){
   return busca_ABP_rec(a.raiz, chave, (*compara_info) ) != NULL;
}

void limpa_ABP(ABP *a){
     if(a->raiz != NULL){
        limpa_pos_ordem(a->raiz);
        a->raiz = NULL;
     }
}

void percurso_pre_ordem(ABP a, void (*mostra_info)(void *) ){
     if(a.raiz == NULL)
        printf("Arvore vazia!\n");
     else{
        printf("Percurso em Pre-Ordem:\n\n");
        pre_ordem(a.raiz, (*mostra_info) );
     }
     printf("----------------------\n\n");
}

void percurso_em_ordem(ABP a, void (*mostra_info)(void *) ){
     if(a.raiz == NULL)
        printf("Arvore vazia!\n");
     else{
        printf("Percurso Em-Ordem:\n\n");
        em_ordem(a.raiz, (*mostra_info) );
     }
     printf("----------------------\n\n");
}

void percurso_pos_ordem(ABP a, void (*mostra_info)(void *) ){
     if(a.raiz == NULL)
        printf("Arvore vazia!\n");
     else{
        printf("Percurso em Pos-Ordem:\n\n");
        pos_ordem(a.raiz, (*mostra_info) );
     }
     printf("\n----------------------\n\n");
}

void percurso_em_largura(ABP a, void (*mostra_info)(void *) ){
     if(a.raiz == NULL)
        printf("Arvore vazia!\n");
     else{
        printf("Percurso em largura:\n\n");
        FilaEncadeada f;
        inicializaFila(&f, sizeof(NoABP)); // Fila de nós da árvore
        inserir(&f, a.raiz); // O campo "raiz" é um ponteiro, portanto, não precisa do "&"...
        while(!filaVazia(f)){
           NoABP n;
           remover(&f, &n);
           (*mostra_info)(n.info); // Mostra nó (1o. da fila)
           if(n.esq != NULL)       // Insere filhos na fila
              inserir(&f, n.esq);
           if(n.dir != NULL)
              inserir(&f, n.dir);
        }
        limpaFila(&f);
     }
     printf("----------------------\n\n");
}

void mostra_estrutura(ABP a, void (*mostra_info)(void *) ){
     printf("Estrutura da Arvore:\n\n");
     if(a.raiz == NULL)
        printf("(null)\n");
     else{
        (*mostra_info)(a.raiz->info);
        pre_ordem_modificado(a.raiz->esq, 1, (*mostra_info) );
        pre_ordem_modificado(a.raiz->dir, 1, (*mostra_info) );
     }
     printf("----------------------\n\n");
}

// ------------------------------------- public ABP ---------------------------------------
/*-----------------------------------------------------------------------------------------*/
