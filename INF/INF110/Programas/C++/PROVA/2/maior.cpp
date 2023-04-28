#include <iostream>
using namespace std;

int maior(int v[], int posicao, int n){
    int maior = v[posicao];
    for(int i=0; i<n;i++){
        if(v[i] > maior){
            maior = v[i];
        }
    }
    return maior;
}

int main(){
    int n=0, p=0;
    cin >> n;
    int A[n]={0};
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    p = maior(A, 0,n);
    cout << p << endl;
    return 0;
}