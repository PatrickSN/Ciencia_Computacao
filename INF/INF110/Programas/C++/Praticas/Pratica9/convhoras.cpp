#include <iostream>
using namespace std;

void convhoras(int seg, int &h,int &m, int &s){
    int aux=0;
    s=seg%60;
    aux=seg/60;
    m=aux%60;
    h=aux/60;
    return;
}

int main(){
    int N=0;
    cin >> N;
    int h=0, m=0, s=0;
    convhoras(N, h,m,s);
    if(h<10){
        if(m<10){
            if(s<10){
                cout << 0 << h << ":" << 0 << m << ":" << 0 << s << endl;
            }
            else{
                cout << 0 << h << ":" << 0 << m << ":" << s << endl;
            }
        }
        else{
            if(s<10){
                cout << 0 << h << ":" << m << ":" << 0 << s << endl;
            }
            else{
                cout << 0 << h << ":" << m << ":" << s << endl;
            }
        }
    }
    else{
        if(m<10){
            if(s<10){
                cout << h << ":" << 0 << m << ":" << 0 << s << endl;
            }
            else{
                cout << h << ":" << 0 << m << ":" << s << endl;
            }
        }
        else{
            if(s<10){
                cout << h << ":" << m << ":" << 0 << s << endl;
            }
            else{
                cout << h << ":" << m << ":" << s << endl;
            }
        }
    }
}