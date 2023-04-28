#include <iostream>
#include <cstring>

using namespace std;


int main(){
    char palavra[50];
    cin >> palavra;
    for(int i=strlen(palavra)-2;palavra[i]!='\0';i++){
        if(i == strlen(palavra)-2){palavra[i] = 'P';}
        else{palavra[i] = 'i';}
    }
    cout << palavra << endl;
}