#include <iostream>
using namespace std;

int main(){
    int batata = 430, suco = 270, guarana = 143; 
    int codigo_do_produto;
    int soma = 0, dinheiro;
    int i, C[6] = {100, 50, 20, 10, 5, 2}, M[6] = {100, 50, 25, 10, 5, 1};
    char tipo;

    cin >> codigo_do_produto;
// entrada do dinheiro
    while(true)
    {
        cin >> tipo >> dinheiro;
        if(dinheiro == 0){break;}
        if (tipo == 'C')
        {
            soma += dinheiro*100;
        }
        else
        {
            soma += dinheiro;
        }
        
    }
// verifica se o codigo do produto eh valido
    if (codigo_do_produto < 1 || codigo_do_produto > 3)
    {
        cout << "Produto inexistente." << endl;
    }
// imprime o troco com base no codigo do produto
    else
    {
        if (codigo_do_produto == 1 && soma >= batata)
        {
            // calcula o troco 
            soma = soma - batata;
            while(soma != 0)
            {
                for(i=0; i<6; i++)// calcula as cedulas
                {
                    while ((soma-(C[i])*100)>=0)
                    {
                        soma = soma - C[i]*100;
                        cout << "C " << C[i] << endl;
                    } 
                }
                for(i=0; i<6; i++)// calcula as moedas
                {
                    while ((soma-(M[i]))>=0)
                    {
                        soma = soma - M[i];
                        cout << "M " << M[i] << endl;
                    }
                }
            }
        }
        else if (codigo_do_produto == 2 && soma >= suco)
        {
            // calcula o troco 
            soma = soma - suco;
            while(soma != 0)
            {
                for(i=0; i<6; i++)// calcula as cedulas
                {
                    while ((soma-(C[i])*100)>=0)
                    {
                        soma = soma - C[i]*100;
                        cout << "C " << C[i] << endl;
                    } 
                }
                for(i=0; i<6; i++)// calcula as moedas
                {
                    while ((soma-(M[i]))>=0)
                    {
                        soma = soma - M[i];
                        cout << "M " << M[i] << endl;
                    }
                }
            }
        }
        else if (codigo_do_produto == 3 && soma >= guarana)
        {
            // calcula o troco
            soma = soma - guarana;
            while(soma != 0)
            {
                for(i=0; i<6; i++)// calcula as cedulas
                {
                    while ((soma-(C[i])*100)>=0)
                    {
                        soma = soma - C[i]*100;
                        cout << "C " << C[i] << endl;
                    } 
                }
                for(i=0; i<6; i++)// calcula as moedas
                {
                    while ((soma-(M[i]))>=0)
                    {
                        soma = soma - M[i];
                        cout << "M " << M[i] << endl;
                    }
                }
            }
        }
        else//quando o valor inserido nn eh suficiente
        {
         cout << "Saldo insuficiente." << endl;
        }
    }
return 0;
}