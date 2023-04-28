#include <iostream>
using namespace std;

int main(){
    int D=0, F=0;
    cin >> D >> F;

    int tab[D][F];
    for(int i=0; i<D;i++){
        for(int j=0; j<F; j++){cin >> tab[i][j];}
    }
    for(int i=0; i<F;i++){
        for(int j=0;j<D;j++){
            if(j == D-1)
                cout << tab[j][i];
            else
                cout << tab[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}