#include <iostream>
using namespace std;

int main(){
    int m=0,n=0,v=0, cont=0;
    cin >> m >> n;
    int tab[m][n]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> tab[i][j];
        }
    }

    cin >> v;

    for(int i=0;i<m;i++){
        cont = 0;
        for(int j=0;j<n;j++){
            if(tab[i][j] == v){cont++;}
        }
        cout << cont << endl;
    }
    return 0;
}