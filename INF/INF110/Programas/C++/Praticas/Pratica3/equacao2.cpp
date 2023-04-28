#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){

    double A, B, C;
    double delta, x1, x2;
    cin >> A >> B >> C;
    
    delta = (B*B)-(4*A*C);
    if (delta == 0){
        x1 = (-B + sqrt(delta))/2*A;
        cout << fixed << setprecision(2) << x1 << endl;
    }
    else if(delta < 0)
        cout << "Nao ha raiz real" << endl;
    else
        x1 = (-B + sqrt(delta))/2*A;
        x2 = (-B - sqrt(delta))/2*A;
        cout << fixed << setprecision(2) << x2 << " " << x1 << endl;
return 0;
}