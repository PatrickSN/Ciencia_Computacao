#include <iostream>
using namespace std;

int main(){
    int numero;
    int cont = 0, i;
    cin >> numero;
    for (i=1;i<=numero;i++){
        if (numero%i == 0){
            cont ++;
        }
    }

    if (cont == 2){
        cout << "Primo." << endl;
    }
    else{
        cout << "Nao primo." << endl;
    }
return 0;
}