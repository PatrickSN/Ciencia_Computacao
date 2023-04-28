#include <iostream>
using namespace std;

int main(){
    int batata = 430, suco = 270, guarana = 143; 
    int codigo_do_produto;
    int soma = 0, dinheiro;
    char tipo;

    cin >> codigo_do_produto;
// entrada do dinheiro
    while(true){
        cin >> tipo >> dinheiro;
        if (dinheiro == 0){
            break;
        }
        if (tipo == 'C'){
            soma += dinheiro*100;
        }
        else{
            soma += dinheiro;
        }
        
    }
// verifica se o codigo do produto eh valido
    if (codigo_do_produto < 1 || codigo_do_produto > 3){
        cout << "Produto inexistente." << endl;
    }
// imprime o troco com base no codigo do produto
    else{
        if (codigo_do_produto == 1 && soma >= batata){
            cout << "Troco de " << soma - batata << " centavos." << endl;
        }
        else if (codigo_do_produto == 2 && soma >= suco){
            cout << "Troco de " << soma - suco << " centavos." << endl;
        }
        else if (codigo_do_produto == 3 && soma >= guarana){
            cout << "Troco de " << soma - guarana << " centavos." << endl;
        }
        else{
            cout << "Saldo insuficiente." << endl;
        }
        
    }
return 0;
}