#include <iostream>
using namespace std;

int main(){

    int N;
    int soma=0,i;
    cin >> N;
    for (i=1;i<=N/2;i++){
        if (N % i == 0){
            soma += i;
        }
    }
    if (soma == N){
        cout << "SIM" << endl;
    }
    else{
        cout << "NAO" << endl;
    }
return 0;
}