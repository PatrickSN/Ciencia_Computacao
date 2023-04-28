#include <iostream>
using namespace std;

int main(){

    int X, Y;
    cin >> X >> Y;
    if (X>0){
        if (Y>0){
            cout << "QUADRANTE 1" << endl;
        }
        else if (Y<0){
            cout << "QUADRANTE 4" << endl;
        }
        else{
            cout << "EIXO X" << endl;
        }
    }
    else if(X<0){
        if (Y>0){
            cout << "QUADRANTE 2" << endl;
        }
        else if (Y<0){
            cout << "QUADRANTE 3" << endl;
        }
        else{
            cout << "EIXO X" << endl;
        }
    }
    else{
        if(Y==0){
            cout << "ORIGEM" << endl;
        }
        else{
            cout << "EIXO Y" << endl;
        }
    }
}
