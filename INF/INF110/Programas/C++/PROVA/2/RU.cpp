#include <iostream>
using namespace std;

int main(){
    int P=0, I=0;
    cin >> P >> I;

    int pratos[P][I]={0};
    int precos[I]={0};
    int preco_final[P]={0};
    for(int i=0;i<P;i++){
        for(int j=0;j<I;j++){
            cin >> pratos[i][j];
        }
    }

    for(int i=0;i<I;i++){
        cin >> precos[i];
    }

    for(int i=0;i<P;i++){
        preco_final[i] = 0;
        for(int j=0;j<I;j++){
            preco_final[i] += precos[j]*pratos[i][j];
        }
    }

    for(int i=0;i<P;i++){
        if(i != P-1){
        cout << preco_final[i] << " ";
        }
        else{cout << preco_final[i];}
    }

    cout << endl;
    return 0;
}