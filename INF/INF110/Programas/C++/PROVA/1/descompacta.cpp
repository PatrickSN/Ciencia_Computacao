#include <iostream>
using namespace std;

int main(){

    int rep= -1;
    char letra;
    while(rep != 0){
        cin >> rep;
        cin >> letra;
        for(int i=0; i<rep;i++){
            cout << letra;
        }
    }
    cout << '.' << endl;
    return 0;
}