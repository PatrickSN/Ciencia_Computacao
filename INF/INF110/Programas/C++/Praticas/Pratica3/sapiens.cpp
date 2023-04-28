#include <iostream>
using namespace std;

int main(){
    double nota_final;
    int faltas_teoricas, faltas_praticas;
    cin >> nota_final >> faltas_teoricas >> faltas_praticas;

    if (faltas_teoricas <= 15 && faltas_praticas <= 7){
        if (nota_final >= 60)
            cout << "Aprovado" << endl;
        else if (nota_final >= 40)
            cout << "Final" << endl;
        else
            cout << "Reprovado" << endl;                

    }
    else
        cout << "Reprovado" << endl;
    
return 0;
}