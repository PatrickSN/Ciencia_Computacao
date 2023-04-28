#include <iostream>
using namespace std;

int main(){
    int num;
    long long int ultimo=1, penultimo=1, cont = 3, termo=0;
    cin >> num;

    if (num==0 || num==1){
        cout << num << endl;
    }
    else{
        while(cont<=num){
            termo = ultimo+penultimo;
            penultimo = ultimo;
            ultimo = termo;
            cont++;
        }
        cout << ultimo << endl;
    }
}
    