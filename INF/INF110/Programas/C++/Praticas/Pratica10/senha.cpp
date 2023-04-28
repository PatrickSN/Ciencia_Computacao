#include <iostream>
#include <cstring>
using namespace std;

void imprime(int condicao){
    if(condicao == 3){
        cout << "fraca" << endl;
    }

    else if(condicao == 2 ){
        cout << "media" << endl;
    }

    else{
        cout << "segura" << endl;
    }
    return;
}
int main(){
    char palavra[30];
    int num=0, let=0,LET=0,esp=0,cond=0;
    cin >> palavra;

    for(int i=0; palavra[i]!='\0';i++){
        if (islower(palavra[i])){
            let++;
            let++;
        }
    
        else if (isupper(palavra[i])){
            LET++;
            LET++;
        }
    
        else if (ispunct(palavra[i])){
            esp++;
            esp++;
        }
    
        else if (isdigit(palavra[i])){
            num++;
            num++;
        }
    }
    if(let>0 && LET>0 && esp>0 && num>0){
        cond=1;
    }
    else if(let==0 && LET>0 && esp>0 && num>0  ||
            let>0 && LET==0 && esp>0 && num>0  ||
            let>0 && LET>0 && esp==0 && num>0  ||
            let>0 && LET>0 && esp>0 && num==0  ||
            let==0 && LET==0 && esp>0 && num>0 ||
            let==0 && LET>0 && esp==0 && num>0 ||
            let==0 && LET>0 && esp>0 && num==0 ||
            let>0 && LET==0 && esp==0 && num>0 ||
            let>0 && LET==0 && esp>0 && num==0 ||
            let>0 && LET>0 && esp==0 && num==0){
        cond=2;
    }
    
    else{
        cond=3;
    }

    imprime(cond);

    return 0;
}

