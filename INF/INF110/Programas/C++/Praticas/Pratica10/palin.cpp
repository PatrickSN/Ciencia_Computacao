#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char palavra[30];
    int cont=0;
    cin >> palavra;
    char aux[strlen(palavra)];

    for(int i=0; palavra[i]!='\0';i++){
        aux[strlen(palavra)-1-i]=palavra[i];
    }

    for(int i=0; palavra[i]!='\0';i++){
        if(palavra[i] == aux[i]){
            cont++;
        }
    }

    if(cont == strlen(palavra)){
        cout << "PALINDROMO" << endl;
    }
    else{
        cout << "NAO" << endl;
    }

    return 0;
}