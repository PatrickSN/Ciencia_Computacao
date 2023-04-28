#include <iostream>
using namespace std;

void intercala(int V[], int V2[], int tam){
    for(int i=0; i<tam;i++){cout << V[i] << " " << V2[i] << " ";}
    cout << endl;
}

int main(){
    int n=0;
    cin >> n;
    int L1[n]={0}, L2[n]={0};

    for (int i =0;i<n;i++){cin >> L1[i];}
    for (int i =0;i<n;i++){cin >> L2[i];}

    intercala(L1, L2, n);
    return 0;
}