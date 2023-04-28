#include <iostream>
using namespace std;

char posicao(char Matriz[][3], int linha, int coluna, char valor){// adiciona a jogada
    Matriz[linha][coluna]=valor;
}

void verifica(char Matriz[][3]){// verifica o ganhador 
    int cont=0;
    if(Matriz[0][0] == Matriz[1][1] && Matriz[0][0] == Matriz[2][2]){//verifica a diagonal principal
        cout << "Venceu " << Matriz[0][0] << "!" << endl;
        cont++;
    }
    else if(Matriz[0][2] == Matriz[1][1] && Matriz[0][2] == Matriz[2][0]){// verifica a diagonal secundaria
        cout << "Venceu " << Matriz[0][2] << "!" << endl;
        cont++;
    }
    else{
        for(int i=0; i<3; i++){
            if(Matriz[i][0] == Matriz[i][1] && Matriz[i][0]== Matriz[i][2]){//linha por linha
            cout << "Venceu " << Matriz[i][0] << "!" << endl;
            cont++;
            break;
            }
            else if(Matriz[0][i] == Matriz[1][i] && Matriz[0][i] == Matriz[2][i]){// coluna por coluna
            cout << "Venceu " << Matriz[0][i] << "!" << endl;
            cont++;
            break;
            }
        }
    }
    if(cont == 0){//caso nn haja nenhum ganhador
        cout << "Velha!" << endl;
    }
    return;
}

int main(){
    char M[3][3]={{'a','b','c'},{'d','e','f'},{'g','h','i'}}, caractere='a';
    int jogadas=0, pl=0, pc=0;
    cin >> jogadas;

    for(int i=0;i<jogadas;i++){
        cin >> caractere >> pl >> pc;
        posicao(M, pl, pc, caractere);
    }

    verifica(M);
    return 0;
}