#include <iostream>
using namespace std;

int main(){
    int N, cont=0;
    int soma=0;
    cin >> N;

    for(int i=1;i<=N;i++){
        soma = 0;
        for(int j=i;j<N;j++){
            soma += j;
            if(soma == N){cont++;}
        }
    }
    if(cont != 0){cout << "SIM" << endl;}
    else{cout << "NAO" << endl;}
}