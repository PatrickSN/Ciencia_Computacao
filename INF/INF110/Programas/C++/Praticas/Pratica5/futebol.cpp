#include <iostream>
using namespace std;

int main(){
    int num_jog, idade_r, lim;
    int idade[30];
    int i, cont=0;

    cin >> num_jog >> idade_r >> lim;

    for(i=0;i<num_jog;i++){
        cin >> idade[i];
        if(idade[i] >= idade_r){
            cont++;
        }
    }
    if(cont > lim){
        cout << "Nao aceito." << endl;
    }
    else{
        cout << "Aceito." << endl;
    }
return 0;
}