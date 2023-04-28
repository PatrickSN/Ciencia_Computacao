#include <iostream>
#include <math.h>
using namespace std;

int espelhar(int n){
    int aux=0,a,b,c;
    a = (n%1000);
    b = (n%100);
    c = (n%10);
    aux = (c*1000)+((b-c)*10)+((a-b)/10)+((n-a)/1000);

    return aux;
}

int main(){
    int A=-1, B=-1,aux=0;
    cin >> A >> B;

    while(A!=0 && B!=0){
        aux = espelhar(A);
        if (aux == B){cout << "espelho" << endl;}
        else{cout << "nao espelho" << endl;}
        cin >> A >> B;
    }
}
