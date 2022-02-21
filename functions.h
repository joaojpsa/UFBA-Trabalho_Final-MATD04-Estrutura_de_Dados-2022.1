#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
  float valor;
  struct NO *proximo;
} No;

typedef struct PILHA{
  No *topo;
  int tamanho;
} Pilha;

void inicializarPilha(Pilha *pilha) {
  pilha->topo    = NULL;
  pilha->tamanho = 0;
}


void empilhar(float valor, Pilha *pilha) {
  No *novoNo      = malloc(sizeof(No));
  novoNo->valor   = valor;
  if (pilha->tamanho == 0)
    novoNo->proximo = NULL;
  else
    novoNo->proximo = pilha->topo;
  pilha->topo = novoNo;
  pilha->tamanho++;

}

void exibir(Pilha *pilha) {
  No *temporario;
  float soma = 0;

  temporario = pilha->topo;

  int i = pilha->tamanho;
  while (i > 0) {
    soma += temporario ->valor;
    printf("Dia: %i | Valor: [ R$%5.2f ]\n", i, temporario->valor);
    temporario = temporario->proximo;
    i--;


  }
  printf("----------------------------\n");
	printf(" Total MES: R$%5.2f\n", soma);

}

void desempilhar(Pilha *pilha) {
  if (pilha->tamanho == 0) {
    printf("Sem Relatorios\n");
  } else {
    printf(" VALOR: [R$%5.2f] EXCLUIDO\n", pilha->topo->valor);
    pilha->tamanho--;
    pilha->topo = pilha->topo->proximo;
  }
}

void limparPilha(Pilha **pilha) {
  printf("Excluindo Relatorio...\n");
  No *temporario;
  temporario = *pilha;
  while (temporario != NULL) {
    printf("Excluindo... [R$%5.2f]\n", temporario->valor);

      *pilha = temporario->proximo;
      free(temporario);
      temporario = *pilha;
  }
}