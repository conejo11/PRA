typedef struct ele{
   void *info;
   struct ele *proximo;
}Elemento;

typedef struct {
     int tamanhoInfo;
     Elemento *inicio, *fim;
}FilaEncadeada;

typedef struct no{
   void *info;
   int fb;
   struct no *esq, *dir, *pai;
}NoABP;

typedef struct{
   int tamanhoInfo;
   NoABP *raiz;
}ABP;

typedef struct infoAr
{
	int linha, dst; // Dst = DeSTino
} infoAr;