#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int eq2grau(double a, double b, double c, double &x1, double&x2){
    double delta = (b*b)-(4*a*c);
    int cont=0;
    if (delta == 0){
        x1 = (-b + sqrt(delta))/(2*a);
        cont = 1;
    }
    else if(delta > 0){
        x1 = (-b - sqrt(delta))/(2*a);
        x2 = (-b + sqrt(delta))/(2*a);
        cont = 2;
    }
    return cont;
}

int main(){
    double A=0, B=0, C=0, r1=0, r2=0, raizes=0;
    cin >> A >> B >> C;
    raizes = eq2grau(A, B, C, r1, r2);
    if(raizes == 1){
        cout << fixed << setprecision(2) << r1 << endl;
    }
    else if(raizes == 2){
        cout << fixed << setprecision(2) << r1 << " " << r2 << endl;
    }
    else{
        cout << "Nao ha raiz real" << endl;
    }
}