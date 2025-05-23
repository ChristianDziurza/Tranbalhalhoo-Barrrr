#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "FilaPrioridadesLE.h"
#define N 10

no *criaAnoes(no *l);

int main(){
    no *anoes, *karaoke, *balcao;
    string nomes[2];
    bool a = !(verificaSeVazia(anoes) && verificaSeVazia(karaoke) && verificaSeVazia(balcao));
    
    bool usado1=false, usado2=false, k, l;
    srand (time(NULL));
    anoes = inicializaFP(anoes);
    balcao = inicializaFP(balcao);
    karaoke = inicializaFP(karaoke);
    anoes = criaAnoes(anoes);
    

    int iK=0, iB=0,x ,y;
    
    while(a){
        a = !(verificaSeVazia(anoes) && verificaSeVazia(karaoke) && verificaSeVazia(balcao)) || (usado2 || usado1);
        string nome;
        Prioridades prior;
        Gosto beb, can, beb1, can1;
        bool fila;
        cout << "|| BALCAO DE BEBIDA ||" << endl;
        cout << nomes[1] << endl;
        cout << "Gosto pra bebida: ";
        switch(beb1){
            case 1:
                cout << "ODEIA (10 minutos)" << endl;
                break;
            case 2:
                cout << "NAO GOSTA (20 minutos)" << endl;
                break;
            case 3:
                cout << "GOSTA (30 minutos)" << endl;
                break;
            case 4:
                cout << "ADORA (40 minutos)" << endl;
                break;
            case 5:
                cout << "AMA (50 minutos)" << endl;
                break;
        }
        if(((beb1-iB)+1) >= 0){
            cout << "Tempo que ele vai ficar bebendo: " << (beb1-iB)+1  << "0 minutos"<< endl;
        }else
            cout << "Sai daqui o bar fecho" << endl;
        
        exibe(balcao);
        cout << "|| KARAOKE ||" << endl;
        cout << nomes[0] << endl;
        cout << "Gosto pra cantar: ";
        switch(can1){
            case 1:
                cout << "ODEIA (10 minutos)" << endl;
                break;
            case 2:
                cout << "NAO GOSTA (20 minutos)" << endl;
                break;
            case 3:
                cout << "GOSTA (30 minutos)" << endl;
                break;
            case 4:
                cout << "ADORA (40 minutos)" << endl;
                break;
            case 5:
                cout << "AMA (50 minutos)" << endl;
                break;
        }
        if(((can1-iK)+1) >= 0){
            cout << "Tempo que ele vai ficar cantando: " << (can1-iK)+1  << "0 minutos"<< endl;
        }else
            cout << "Sai daqui o karaoke fecho" << endl;
        
        exibe(karaoke);
        cout << endl;
        if(anoes != NULL)
            anoes = removeFP(anoes, &nome, &prior, &beb, &can, &fila);
        if(fila && anoes != NULL){
            karaoke = insereFP(karaoke, nome, prior, fila, beb, can);
        }
        else if(!(fila) && anoes != NULL){ 
            balcao = insereFP(balcao, nome, prior, fila, beb, can);
            
        }
        if(karaoke != NULL && !(usado1)){
            iK = 0;
            karaoke = removeFP(karaoke, &nomes[0], &prior, &beb, &can1, &k);
            usado1 = true;
        }
        if(balcao != NULL && !(usado2)){
            iB = 0;
            balcao = removeFP(balcao, &nomes[1], &prior, &beb1, &can, &l);
            usado2 = true;
        }
        if(beb1 == iB){
            usado2 = false;
        }
        if(can1 == iK){
            usado1 = false;
        }
        
            iK++;
        
            iB++;
        
    }
    
    system("pause");
}

no *criaAnoes(no *l){
    string nomes[] = {"Jorge", "Carlos", "Leandro", "Gimli", "Dory", "Brogy", "Tiago", "Luis", "Ayumi", "Gustavo", "Yohann",
    "Matheus", "Luiz", "Joao", "Ambos","Luca","Luka","Mari","Ana","Mariana","Maria","Julya","Hebraim",
    "Rafael","Lucas","Marcelo","Guilherme","Malcon","Caio","Chris","Gabriel","Jo","Luciana",
    "Luciano","Marciano","Marvin","Marcos","Luisa","Camila","Alexandre","Geresvalda","Alan","Felipe","Dominique",
    "Oliver","Ruan","Thiago"
    };
    string nome;
    bool tipoFila;
    Prioridades prioridade;
    Gosto beber, cantar;
    no *X = l;

    for(int i = 0; i < 50; i++){
        nome = nomes[rand()%47];
        tipoFila = rand()%2;
        prioridade = Prioridades(rand()%3);
        beber = Gosto((rand()%5)+1);
        cantar = Gosto((rand()%5)+1);
        X = insereFilaChegada(X, nome, prioridade, tipoFila, beber, cantar);

    }
    l = X;
    return l;
}