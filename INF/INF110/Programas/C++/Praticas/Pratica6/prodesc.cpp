#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int Va[n]={0}, Vb[n]={0};
    int soma=0;

    for(int i=0;i<n;i++){
        cin >> Va[i];
    }
    for(int i=0;i<n;i++){
        cin >> Vb[i];
        soma += Va[i]*Vb[i];
    }
    cout << soma << endl;
return 0;
}