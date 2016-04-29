/*

    <Labirinto>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LAB_H
#define LAB_H

#define ERRO_LISTA_VAZIA -1
#define POSICAO_INEXISTENTE -2
#define ERROARQ -3
#define ERROALLOC -4
#define INALCANCAVEL -10

int COL=0;
int LIN=0;
char *nomeArquivo;


//define estrutura eletemnto de lista
typedef struct elemento{
	int info;
	struct elemento *proximo;
        struct elemento *anterior;
}Elemento;

//define estrutura de cabeçalho da lista
typedef struct{
	int tamanho;
	Elemento *cabeca;
}ListaEncadeada;

//protótipo da funções
void imprimeRatoLabirinto(char **lab, ListaEncadeada *caminho);
ListaEncadeada *criaLista();
int estah_vazia_listaenc(ListaEncadeada *lista);
int pertenceALista(ListaEncadeada *lista, int elemento);
void destroi_lista(ListaEncadeada *lista);
ListaEncadeada *caminhoInicial(ListaEncadeada **mapa, int **vet, char **lab);
int adicionaNoInicio(ListaEncadeada *lista, int dados);
int adicionaNoFim(ListaEncadeada *lista, int dados);
int removeElementoInicio(ListaEncadeada *lista);
void imprime_lista(ListaEncadeada *lista);
int removeDoFimAte(ListaEncadeada *lista, int forkk);
int carga(char **lab, int **vertices);
ListaEncadeada *caminhoMinimo(char **labirinto, int **vertices);
int qtdVertices(int **vertices);
int procuraNoMapa(ListaEncadeada **mapa, int elemento, int qV);
//ListaEncadeada** mapeamento(int **vertices);
int posInicio(int **vet, char **lab);
int posSaida(int **vet, char **lab);
int pCima(int x, int y, int **v);
int pBaixo(int x, int y,  int **v);
int pEsquerda(int x, int y,  int **v);
int pDireita(int x, int y,  int **v);
#endif

