#include <iostream>
using namespace std;

int main(){

    long long int cid_p[10]={0};
    long long int cid_b[10]={0};
    int cont=0;

    for (int i=0; i<10;i++){
        cin >> cid_p[i];
    }
    for (int i=0; i<10;i++){
        cin >> cid_b[i];
    }
    for(int i=0;i<10;i++){
        cont = 0;
        for(int j=0;j<10;j++){
            if(cid_b[j] == cid_p[i]){cont++;}
        }
        if(cont == 0){cout << cid_p[i] << " ";}
    }
    for(int i=0;i<10;i++){
        cont = 0;
        for(int j=0;j<10;j++){
            if(cid_b[i] == cid_p[j]){cont++;}
        }
        if(cont == 0){cout << cid_b[i] << " ";}
    }
    cout << endl;
    return 0;
}