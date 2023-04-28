#include <iostream>
#include <math.h>
using namespace std;

bool divresto(int divd, int divs, int &i, int &r){
    bool verifica=true;
    if (divs == 0){verifica=false;}
    else{
        i=divd/divs;
        r=divd%divs;
    }
    return verifica;
}
int main(){
    int N=0;
    cin >> N;
    int a[N]={0},b[N]={0},i=0,r=0;
    for(int j=0;j<N;j++){
        cin >> a[j] >> b[j];
        if(divresto(a[j],b[j],i,r)){
            cout << i << " " << r << endl;
        }
        else{
            cout << "indefinido" << endl;
        } 
    }
}