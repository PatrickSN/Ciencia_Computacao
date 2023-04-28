#include <iostream>
#include <cstring>
using namespace std;

void compara(int &cont_tok, int &cont_tip, char frase[], char palavra[]){
    char palavra_aux[strlen(palavra)], frase_aux[strlen(frase)];
    int aux=0;
    strcpy(frase_aux,frase);
    strcpy(palavra_aux, palavra);

    char *token_aux = strtok(frase_aux, " ,.-");
    
    while(token_aux != NULL){
        if(!(strcmp(token_aux,palavra_aux) == 0)){
            cont_tip++;
        }
        cont_tok++;
        token_aux = strtok(NULL, " ,.-");
    }

    return;
}

int main(){
    
    int ntok=0, ntip=0, i=0, j=0;
    char sentenca[101];
    cin.getline(sentenca,100);
    char palavra[100];
    for(int i=0; sentenca[i] != '\0';i++){
        sentenca[i] = tolower(sentenca[i]);
    }

    for(i=0;sentenca[i] != '\0';){
        for(j=i;sentenca[j]!=' ';j++){//salva palavra por palavra na variavel msgpara dps verifica-la
            palavra[j-i] = sentenca[j];
            if(sentenca[j] == '\0'){
                break;
            }
        }
        palavra[j-i] = '\0';

        compara(ntok,ntip,sentenca,palavra);

        i+=strlen(palavra)+1;//inicia o j na proxima palavra
    
    }
    cout << ntok << " " << ntip << endl;

    return 0;
}