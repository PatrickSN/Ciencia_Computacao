#include <iostream>
using namespace std;

int main(){
    
    char voto = 'A';
    int cont_geral=0, cont_C=0, cont_D=0, cont_E=0, cont_R=0, cont_T=0;

    while (voto != 'X'){
        cin >> voto;
        if (voto!='X'){cont_geral++;}
        if (voto == 'C'){
            cont_C++;
        }
        else if(voto == 'D'){
            cont_D++;
        }
        else if(voto == 'E'){
            cont_E++;
        }else if(voto == 'R'){
            cont_R++;
        }else if(voto == 'T'){
            cont_T++;
        }
    }
    if (cont_C > cont_geral/2.0 || cont_D > cont_geral/2.0 || cont_E > cont_geral/2.0 ||cont_R > cont_geral/2.0 ||cont_T > cont_geral/2.0){
        cout << "SIM" << endl;
    }
    else{
        cout << "NAO" << endl;
    }
return 0;
}
