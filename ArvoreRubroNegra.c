#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
	TIPOCHAVE chave;
	struct aux *esq, *dir;
	int cor;
	
} NO;

typedef NO* PONT;

int cor(PONT raiz){
	if(raiz == NULL)
		return BLACK;
	else
		return raiz->cor;
}


void trocaCor(PONT raiz){
	raiz->cor = !raiz->cor;
	
	if(raiz->esq != NULL)
		raiz->esq->cor = !raiz->esq->cor;
	if(raiz->dir != NULL)
		raiz->dir->cor = !raiz->dir->cor;
		
}

PONT esquerda(PONT r){
	
	PONT B = r->dir;
	r->dir = B->esq;
	B->esq = r;
	B->cor = r->cor;
	r->cor = RED;
	
	return B;
}


PONT direita(PONT r){
	
	PONT B = r->esq;
	r->esq = B->dir;
	B->dir = r;
	B->cor = r->cor;
	r->cor = RED;
	
	return B;
}

PONT moveVermelhoEsquerda(PONT r){
	trocaCor(r);
	if(cor(r->dir->esq) == RED) {
		r->dir = direita(r->dir);
		r = esquerda(r);
		trocaCor(r);
	}
	return r;
}


PONT moveVermelhoDireita(PONT r){
	trocaCor(r);
	if(cor(r->esq->esq) == RED) {
		r = direita(r);
		trocaCor(r);
	}
	return r;
}

PONT balancear(PONT r){
	
	if(cor(r->dir) == RED)
		r = esquerda(r);
	
	if(r->esq != NULL && cor(r->dir) == RED && cor(r->esq->esq) == RED)
		r = direita(r);
		
	if(cor(r->esq) == RED && cor(r->dir) == RED)
		trocaCor(r);
	
	return r;
}

int insereArv(PONT raiz, TIPOCHAVE ch){
	int resp;
	
	raiz = 
}



int main(){






}
