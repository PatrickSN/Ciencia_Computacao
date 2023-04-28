#include <iostream>
using namespace std;

long long int fatorial (int x) {

    long long int fat = 1;
    for(int i=2; i<=x; i++)
        fat *= i;
    return fat;
}

int main(){

    int N=0, K=0;
    long long int Cnk=0;

    cin >> N >> K;

    Cnk = (fatorial(N))/((fatorial(K))*(fatorial(N-K)));

    cout << Cnk << endl;
    return 0;
}
