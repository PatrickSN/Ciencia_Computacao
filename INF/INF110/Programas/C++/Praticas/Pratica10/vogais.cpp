#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main(){
    char palavra[30];
    double aux=0, cont=0, porcentagem=0; 
    
    cin >> palavra;

    for(int i=0; palavra[i]!='\0';i++){
        palavra[i] = tolower(palavra[i]);
        if (palavra[i]=='a' || palavra[i]=='e' || palavra[i]=='i' || palavra[i]=='o' || palavra[i]=='u'){
            cont++;
        }
    }

    aux = strlen(palavra);
    porcentagem = (cont/aux)*100;
    cout << fixed << setprecision(0) << porcentagem << "%" << endl;

    return 0;
}