#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int cont=0, aux=0;
    char p1[100], p2[100];
    cin >> p1 >> p2;

    for(int i=0;i <= strlen(p2);i++){
        for(int j=0; j<= strlen(p1);j++){
            if(p2[i+j]==p1[j]){
                aux++;
            }
        }
        if(aux == strlen(p1)){
            cont++;
        }
        aux=0;
    }
    
    cout << cont << endl;
}