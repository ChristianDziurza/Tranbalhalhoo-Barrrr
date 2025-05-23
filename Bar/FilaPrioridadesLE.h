#include "enum.h"

struct no {
    string nome;   //Nome do Anao
    bool fila;    //define para qual fila o Anao vai
    enum Prioridades prior;   //Prioridade dos Anoes
    enum Gosto beber;   //Define o nivel do gosto que o Anao tem por bebida
    enum Gosto cantar;  //Define o nivel do gosto que o Anao tem por karaoke
    no *link;   //Aponta pro próximo nó da fila
};

no *inicializaFP(no *L)
{
    L = NULL;
    return L;
}

no *insereFP(no *L, string valor, enum Prioridades prior, bool fila, Gosto beber, Gosto cantar)
{
    no *N, *P, *ANT;

    N = new no;
    N->nome = valor;
    N->prior = prior;
    N->fila = fila;
    N->beber = beber;
    N->cantar = cantar;

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

no *removeFP(no *L, string *valor, Prioridades *prior, Gosto *beber, Gosto *cantar, bool *fila) {
	no *AUX;

	if (L != NULL) {
		*valor = L->nome;
		*prior = L->prior;
        	*beber = L->beber;
        	*cantar = L->cantar;
        	*fila = L->fila;
		AUX = L;
		L = L->link;
		delete AUX;
	}
	return L;
}

bool verificaSeVazia(no *L) {
	if (L == NULL)
		return 1;
	else
		return 0;
}

void exibe(no *L)
{
    no *P = L;
    while (P != NULL) {
		cout << "Nome:" << P->nome;
        switch(P->prior){
            case 0:
                cout << "\t     ||       Prioridade: FIEL (1)"<< endl;
                break;
            case 1:
                cout << "\t     ||       Prioridade: NORMAL (2)"<< endl;
                break;
            case 2:
                cout << "\t     ||       Prioridade: BEBADO (3)"<< endl;
                break;
        }
        P = P->link;
    }
    cout<<endl;
}

no* insereFilaChegada(no *L, string valor, enum Prioridades prior, bool fila, Gosto beber, Gosto cantar) {
	no *P, *N;

	N = new no; 
	N->nome = valor;
    N->prior = prior;
    N->fila = fila;
    N->beber = beber;
    N->cantar = cantar;
	N->link = NULL; 
	 
	if (L == NULL){ 
		L = N;
	}
	else { 
		P = L;	
        
		while(P != NULL) {
			if(P->link == NULL)
                break;
            
            P = P->link;
		}
        
		P->link = N;
	} 
	return L;
}
