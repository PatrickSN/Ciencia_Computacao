#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){

    double X1, Y1, X2, Y2;
    double distanciax, distanciay, hipotenusa;
    cin >> X1 >> Y1 >> X2 >> Y2;

    distanciax = X1 - X2;
    distanciay = Y1 - Y2;
    hipotenusa = sqrt((distanciax*distanciax)+(distanciay*distanciay));

    cout << fixed << setprecision(2) << hipotenusa << endl;

    return 0;
}