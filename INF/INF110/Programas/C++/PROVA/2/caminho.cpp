#include <iostream>
using namespace std;

int main(){
    int n=0,cont=0;
    cin >> n;
    int mat[n][n]={0};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i + 1][j] || mat[i][j + 1] || mat[i + 1][j + 1]){
                cont++;
            }
        }
    }

    if(cont != 0){cout << "SIM" << endl;}
    else{cout << "NAO" << endl;}
    return 0;
}