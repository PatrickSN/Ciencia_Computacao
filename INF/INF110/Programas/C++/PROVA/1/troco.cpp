#include <iostream>
using namespace std;

int main(){
    int N=0;
    int da=0, db=0, dc=0;

    cin >> N;
    cin >> da >> db >> dc;

    if (N % da == 0 || N % db ==0 || N % dc == 0){
        if(N % da == 0){cout << N/da << " doces de " << da << " reais" << endl;}
        else if(N % db == 0){cout << N/db << " doces de " << db << " reais" << endl;}
        else if(N % dc == 0){cout << N/dc << " doces de " << dc << " reais" << endl;}
    }
    else{cout << "Capivaristo ficara sem doce" << endl;}
    return 0;
}