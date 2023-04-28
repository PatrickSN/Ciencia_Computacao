#include <iostream>
using namespace std;

int main(){

    int numero;
    long long int fatorial = 1,i;
    cin >> numero;

    for(i=1;i<=numero;i++)
    {
        fatorial *= i;
    }
    cout << fatorial << endl;

return 0;
}