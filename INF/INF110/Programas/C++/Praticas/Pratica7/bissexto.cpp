#include <iostream>
using namespace std;

bool bissexto(int n){
    
    if(n%4 == 0 && n%100 != 0){return true;}
    else if(n%400 == 0){return true;}
    else{return false;}

}

int main(){

    int ano=0;
    cin >> ano;
    while (ano >= 0)
    {
        if(bissexto(ano)){cout << "bissexto" << endl;}
        else{cout << "nao bissexto" << endl;}
        cin >> ano;
    }
    
    return 0;
}

