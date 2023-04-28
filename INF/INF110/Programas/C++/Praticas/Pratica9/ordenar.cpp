#include <iostream>
using namespace std;

void ordenar(int &A, int &B, int &C){
    int maior=A;
    if(B > maior){
        if(B>C){
            maior = B;
            
        }
    }
        
}

int main()
{
int a, b, c;
cin >> a >> b >> c;
ordenar(a, b, c);
cout << a << " " << b << " " << c << endl;
return 0;
}