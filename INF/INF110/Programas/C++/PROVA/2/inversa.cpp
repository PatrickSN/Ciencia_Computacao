#include <iostream>
using namespace std;

int main(){
    int n=0, cont=0;
    cin >> n;
    int matA[n][n]={0}, matB[n][n]={0}, matC[n][n]={0};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matA[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matB[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matC[i][j]=0;
            for(int l=0;l<n;l++){
                matC[i][j] += matA[i][l]*matB[l][i];
            }
        }
    }
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matC[i][i] == 1 || matC[i][j] == 0){
                cont++;
            }
        }
    }

    if(cont == n*n){cout << "SIM" << endl;}
    else{cout << "NAO" << endl;}

    return 0;
}