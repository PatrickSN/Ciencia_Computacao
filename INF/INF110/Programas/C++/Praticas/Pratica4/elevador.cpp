#include <iostream>
using namespace std;

int main(){

    int n_leituras, c_capacidade,cont=0;
    int saida, entrada;
    int p_dentro=0,lim=0;
    cin >> n_leituras >> c_capacidade;
    while(cont<n_leituras){
        cin >> saida >> entrada;
        p_dentro=p_dentro+entrada-saida;
        if (p_dentro>c_capacidade){
            lim++;
        }
        cont++;
    }
    if(lim!=0){
        cout << "S" << endl;
    }
    else{
        cout << "N" << endl;
    }
    return 0;
}