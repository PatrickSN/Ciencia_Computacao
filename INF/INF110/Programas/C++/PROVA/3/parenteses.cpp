#include <iostream>
#include <cstring>
using namespace std;

bool verifica(char frase[]){
    int p_aber=0, p_fech=0;

    for(int i=0; frase[i] != '\0';i++){
        if(frase[i] == '('){
            p_aber++;
        }
        else if(frase[i] == ')'){
            p_fech++;
        }
    }

    if(p_aber == p_fech){
        return true;
    }
    
    else{
        return false;
    }
}

int main(){
    char frase[101];
    cin.getline(frase,100);

    if(verifica(frase)){
        cout << "SIM" << endl;
    }
    
    else{
        cout << "NAO" << endl;
    }
    
    return 0;
}