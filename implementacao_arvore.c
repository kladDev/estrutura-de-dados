#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} Arv;

Arv *inserir_no(Arv *raiz, int numero) {
    if (raiz == NULL) {
        Arv *aux = (Arv*)malloc(sizeof(Arv));
        aux->valor = numero;
        aux->esq = NULL;
        aux->dir = NULL;
      return aux;
    } else {
      if (numero > raiz->valor) {
        raiz->dir = inserir_no(raiz->dir, numero);
      } else {
        raiz->esq = inserir_no(raiz->esq, numero);
      }
      return raiz;
    }
}

void mostrar_arvore(Arv *raiz) {
  if (raiz != NULL) {
    mostrar_arvore(raiz->esq);
    printf("%d\n", raiz->valor);
    mostrar_arvore(raiz->dir);
  }
}

int quantidade_no(Arv *raiz) {
  if(raiz != NULL) {
    return 1 + quantidade_no(raiz->esq) + quantidade_no(raiz->dir);
  } else {
    return 0;
  }
}

int main() {
    Arv *raiz = NULL;
    int qtd_no;
    raiz = inserir_no(raiz, 50);
    raiz = inserir_no(raiz, 100);
    raiz = inserir_no(raiz, 25);
    qtd_no = quantidade_no(raiz);
    mostrar_arvore(raiz);
    printf("%d", qtd_no);
    return 0;
}
