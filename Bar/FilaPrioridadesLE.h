#include <enum.h>

struct no {
    char *nome;
    bool fila;
    enum Prioridades prior;
    enum Gosto beber;
    enum Gosto cantar;
    no *link;
};

no *inicializaFP(no *L)
{
    L = NULL;
    return L;
}

no *insereFP(no *L, char *valor, enum Prioridades prior, bool fila)
{
    no *N, *P, *ANT;

    N = new no;
    N->nome = valor;
    N->prior = prior;
    N->fila = fila;

    if (L == NULL) {
        L = N;
        N->link = NULL;
    }
    else {
        P = L;

        while ((P != NULL) && (prior >= P->prior)) {
            ANT = P;
            P = P->link;
        }
        if (P == L) {
            N->link = L;
            L = N;
        }
        else {
            ANT->link = N;
            N->link = P;
        }
    }
    return L;
}

no *removeFP(no *L, char *valor, int * prior) {
	no *AUX;

	if (L != NULL) {
		valor = L->nome;
		*prior = L->prior; 
		AUX = L;
		L = L->link;
		delete AUX;
	}
	return L;
}

int verificaSeVazia(no *L) {
	if (L == NULL)
		return 1;
	else
		return 0;
}

void exibe(no *L)
{
    no *P = L;
    cout << " ";
    while (P != NULL) {
		cout << "C:" << P->nome << " P:" << P->prior << "|" ;
        P = P->link;
    }
}

no* insereFilaChegada(no *L, char *valor, enum Prioridades prior) {
	no *P, *N;

	N = (no *) malloc (sizeof(no)); 
	N->nome = valor; 
	N->prior = prior; 
	N->link = NULL; 
	 
	if (L == NULL){ 
		L = N;
	}
	else { 
		P = L;	
	
		while(P->link != NULL) {
			P = P->link;
		}
		P->link = N;
	} 
	return L;
}