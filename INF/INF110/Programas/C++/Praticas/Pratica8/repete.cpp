#include <iostream>
using namespace std;

void testa(int V[], int tam){
    int aux=0;
    for(int i=0; i<tam;i++){
        for(int j=i;j<tam;j++){
            if(V[i] == V[j] && i!=j){
                aux = V[i];
            }
        }
    }
    if(aux != 0){cout << "SIM: " << aux << endl;}
    else{cout << "NAO" << endl;}
    return;
}
int main(){
    int t=0;
    cin >> t;
    for(int i=0;i<t;i++){
        int n=0;
        cin >> n;
        int V[n]={0};
        for(int j=0;j<n;j++){cin >> V[j];}
        testa(V,n);
    }
    return 0;
}