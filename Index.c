#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cabecalho.h"

#define MBuffer 8192

ABP* sortedArrayToABP(char arr[], int start, int end)
{
    if (start > end)
      return NULL;
 
    int mid = (start + end)/2;
    char temp[11];
    
    strncpy(temp, &(arr[10*(mid-1)]), 9);
    temp[9]='\0';

    ABP *root = newNode(temp);
    root->left =  sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}

int compara_iNFO (void *a, void *b){
	infoAr *ia = (infoAr*)a;
	infoAr *ib = (infoAr*)b;
	int lnA = (int ) ia->linha;
	int lnB = (int ) ib->linha; // ln = LiNha

	if (lnA > lnB)
		return 1;
	if (lnA < lnB)
		return -1;
	return 0;
}



void mostra_iNFO ( infoAr *info ){
	int *pLinha = (int *) info->linha;
	int *pDst = (int *) info->dst;
}

void mostra_char(void *info){
   char *p = (char *) info;
   printf("%s\n", *p);
}

int main () {
	FILE * pFile,
		 * pFileNew;
	char c;

	ABP * arvore;

	
	arvore = sortedArrayToABP (, sizeof(int));
	//inicializa_ABP(arvore, sizeof(infoAr));
printf("oi amor\n");
	int i=0,
		contAux = 0,
		contPart_Max[9],
		tamMax_Linha = 0,
		source,
		dest,
		result,
		k = 0,
		lin = 0;

	while(i<9){
		contPart_Max[i] = 0;
		i++;
	}
	pFile = fopen ("routes.dat_New.txt","r");
	if (pFile==NULL) {
		fputs ("File error",stderr);
		exit (1);
	}
	system("clear");
	i=0;
	  //seleciona tam max campo
	while ((c = fgetc(pFile))!=EOF){
		if(c != '\r'){
			if(c !=  '\n'){
				if(c == ','){
					contPart_Max[i] = contAux;
					contAux = 0;
					i++;
				}else{
					contAux++;
				}
			}else{
				contPart_Max[i] = contAux;
				contAux = 0;
					
				break;
			}
		}

	}
	fclose(pFile);
	/*i=0;
	while(i<9){
		printf("Campo %i -  %i\n",i+1, contPart_Max[i]);
		i++;
	}
	*/

	  // terminate pt1
	//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	  // start pt2

	  //tam max linha
	while(i<9){
		tamMax_Linha+= contPart_Max[i];
		i++;
	}
	i=0;

	pFileNew = fopen ("indice.txt","w");
	if (pFileNew==NULL) {
		fputs ("File error",stderr);
		exit (1);
	}

	contAux = 0;

	char src[contPart_Max[3]];
	char dst[contPart_Max[4]];

	int srcPos = 0,
		dstPos = 0,
		cntLin = 0;

	char *buffer = (char*) malloc (sizeof(char) * MBuffer + 1);
	if (buffer == NULL){
		fputs("Memory Error", stderr);
		exit(2);
	}

	while ((result = fread (buffer, sizeof(char), MBuffer, pFile))!=EOF){
		buffer[result] = '\0';
		if (!result) {
			//printf("\nAcabou a geração do novo arquivo\n");
			break;
		}
		for(i = 0; i < result; i++){
			    if(buffer[i] != '\r') {
		            if (buffer[i] == '\n'){
		            	lin++;
		            	cntLin = 0;
		            	//aqui a gente tem a linha, o campo source e 
		            	
                        }
                     else {
                     	cntLin++;
                     	if(buffer[i] != ','){
                     		if (cntLin > 14 && cntLin < 19)
                     		{
                     			src[srcPos++] = buffer[i];
                     		}

                     		if (cntLin > 23 && cntLin < 28)
                     		{
                     			dst[dstPos++] = buffer[i];
                     		}

                     		if (cntLin == 31){
                     			if (buffer[i] == '0'){
                     				infoAr in;
                     				in.linha = lin;
                     				in.dst = atoi(dst);
                     				insere_ABP(arvore, &in, compara_iNFO);
                     				mostra_estrutura(*arvore, mostra_char);
                     				printf("%s - %s\n", src, dst);
                     			}
                     		}

 
                     		//pula para a pos do source
                     	 	//recebe o campo source
                     		//pula para a pos do dest
                     	  	//recebe o campo dest
                     	
                     		//testa se só tme uma escala
			            
			            	
			            }
			        }
			    }
		}
	}
	return 0;
}	
