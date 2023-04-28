#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double temp,conversor;
    char escala;
    cin >> temp >> escala;

    if (escala == 'F'){
        conversor = (5/9.0)*(temp-32);
        cout <<fixed << setprecision(1) << conversor << " C" << endl;
    }
    else if(escala == 'C')
    {
        conversor = (1.8*temp)+32;
        cout <<fixed << setprecision(1) << conversor << " F" << endl;
    }
    
return 0;
}