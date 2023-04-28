#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char palavra[200];
    int cont=0;
    cin.getline(palavra,200);

    for(int i=0; palavra[i]!='\0';i++){
        if (isupper(palavra[i])){
            cout << palavra[i];
        }
    }
    cout << endl;
    return 0;
}