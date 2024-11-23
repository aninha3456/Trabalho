#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int dado;
  struct no *esq;
  struct no *dir;
} No;

No *criar_no(int dado) {
  No *no = malloc(sizeof(No));
  if(no) { // no != NULL
    no->dado = dado;
    no->esq = NULL;
    no->dir = NULL;
  }
  return no;
}

int maior(int x, int y) {
  return x > y ? x : y;
}

int altura(No *arvore) {
  if(!arvore) return -1; // Critério de parada
  // nó válido
  // relação de recorrência
  return maior(altura(arvore->esq), altura(arvore->dir)) + 1;
  
}

int alturaOtim(No *arvore) {
  if(!arvore) return -1; // Critério de parada
  if(!arvore->esq && !arvore->dir) return 0; // Critério de Parada (Nó folha)
  // nó válido
  // relação de recorrência
  return maior(altura(arvore->esq), altura(arvore->dir)) + 1;
}

int fb(No *arvore) {
  return (alturaOtim(arvore->esq)+1) 
      -  (alturaOtim(arvore->dir)+1);
}

void exibir_pre_ordem(No *arvore) {
  if(arvore) { // no != NULL
    printf("(%d)", arvore->dado);
    exibir_pre_ordem(arvore->esq);
    exibir_pre_ordem(arvore->dir);
  }
}

void exibir_nos_folha(No *arvore) {
  if(arvore) { // no != NULL
    if(arvore->esq == NULL && arvore->dir == NULL) {
      printf("(%d)", arvore->dado);
      return;
    }
    exibir_nos_folha(arvore->esq);
    exibir_nos_folha(arvore->dir);
  }
}

void exibir_nos_internos(No *arvore) {
  if(arvore) { // no != NULL
    // !(arvore->esq == NULL && arvore->dir == NULL)
    // (!(arvore->esq == NULL) || !(arvore->dir == NULL))
    // (arvore->esq != NULL) || arvore->dir != NULL)
    if(!(arvore->esq == NULL && arvore->dir == NULL)) {
      printf("(%d)", arvore->dado);
    }
    exibir_nos_internos(arvore->esq);
    exibir_nos_internos(arvore->dir);
  }
}

int main(void) {
  //       (1)
  //   (2)     (3)
  //     (5)
        // (6)
  No *raiz = criar_no(1);
        raiz->esq = criar_no(2);
          raiz->esq->dir = criar_no(5);
          raiz->esq->dir->dir = criar_no(6);
        raiz->dir = criar_no(3);
  // printf("altura(1): %d\n", alturaOtim(raiz));
  // printf("altura(2): %d\n", alturaOtim(raiz->esq));
  // printf("altura(4): %d\n", alturaOtim(raiz->esq->dir));
  printf("fb(1): %d\n", fb(raiz));
  printf("fb(2): %d\n", fb(raiz->esq));
  printf("fb(3): %d\n", fb(raiz->dir));
  printf("fb(5): %d\n", fb(raiz->esq->dir));
  printf("fb(6): %d\n", fb(raiz->esq->dir->dir));
  
  // exibir_pre_ordem(raiz);
  // puts("\n");
  // exibir_nos_folha(raiz);
  // puts("\n");
  // exibir_nos_internos(raiz);
  return 0;
}