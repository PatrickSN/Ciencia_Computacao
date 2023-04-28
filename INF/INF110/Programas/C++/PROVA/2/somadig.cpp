#include <iostream>
using namespace std;

int main(){
    int N=0,soma=0;
    cin >> N;
    int aux=N;
    while(aux!=0){
        soma += aux%10;
        aux = aux/10;
    }
    cout << soma << endl;
    return 0;
}