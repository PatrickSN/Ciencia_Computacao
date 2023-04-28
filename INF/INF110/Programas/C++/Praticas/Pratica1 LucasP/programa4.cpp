#include <iostream>
using namespace std;

int main(){

    int salario, valorextra, horas, salariototal;
    cout << "Entre com o seu salario base: ";
    cin >> salario;
    cout << "Entre com o valor da hora extra: ";
    cin >> valorextra;
    cout << "Entre com o numero de horas extras trabalhadas: ";
    cin >> horas;
    salariototal = salario + (valorextra*horas);
    cout << "O seu salario total devera ser: " << salariototal << endl;
    
}