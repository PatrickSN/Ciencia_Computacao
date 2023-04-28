#include <iostream>
using namespace std;

int main(){
    int preco_produto;
    int soma = 0,moeda;
    cin >> preco_produto;

    // recebe os valores das moedas
    while(true){
        cin >> moeda;
        if (moeda == 0){
            break;
        }
        else{
            soma += moeda;
        }
    }
    //verifica se o saldo eh suficiente e imprime na tela
    if (soma >= preco_produto){
        cout << "Troco de " << soma - preco_produto << " centavos." << endl;
    }

    else{
        cout << "Saldo insuficiente." << endl;
    }
    
return 0;
}