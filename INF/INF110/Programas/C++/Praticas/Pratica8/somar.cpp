#include <iostream>
using namespace std;

void somar(long int V[], int tam, long int soma){
    int cont=0;
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam;j++){
            if(V[i]+V[j] == soma && i!=j){cont++;}
        }
    }
    if(cont > 0){cout << "SIM" << endl;}
    else{cout << "NAO" << endl;}
    return;
}

int main(){
    int N=0;
    cin >> N;
    long int L[N]={0};

    for(int i=0; i<N;i++){cin >> L[i];}

    long int X=0;
    cin >> X;

    somar(L, N, X);
    return 0;
}