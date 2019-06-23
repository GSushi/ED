#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define N_ALFABETO 26

typedef int bool;
typedef bool TIPORET;

typedef struct no {
	struct no *filhos[N_ALFABETO];
	TIPORET fim;
} NO;

typedef NO* PONT;


PONT criaNo() {
	PONT p = NULL;
	
	p = (PONT)malloc(sizeof(NO));
	
	if (p) {
		p->fim = false;
		for (int i=0; i < N_ALFABETO; i++)
			p->filhos[i] = NULL
	}
	
	return (p);
}

PONT inicializa() {
	return(criaNo());
}

int mapearIndice(char c) {
	return((int)c - (int)'a');
}

void insere(PONT raiz, char *chave) {
	int nivel;
	int compr = strlen(chave);
	int i;
	
	PONT p = raiz;
	for(nivel = 0; nivel < compr; nivel++){
		i = mapearIndice(chave[nivel]);
		if (!p->filhos[i])
			p->filhos[i] = criaNo();
		p = p->filhos[i];
	}
	
	p->fim = true;
}

void busca(PONT raiz, char *chave) {
	int nivel;
	int compr = strlen(chave);
	int i;
	PONT p = raiz;

	for(nivel = 0; nivel < compr; nivel++){
		i = mapearIndice(chave[nivel]);
		if (!p->filhos[i]) return(false);
		p = p->filhos[i];
	}
	
	return(p->fim);
}


int main(){
	
	PONT r = inicializa();
}
