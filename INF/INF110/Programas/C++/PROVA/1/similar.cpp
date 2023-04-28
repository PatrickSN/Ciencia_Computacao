#include <iostream>
using namespace std;

int main(){
    int N=0;
    cin >> N;
    int pag_1[N]={0}, pag_2[N]={0}, pag_3[N]={0};
    int prod1_2=0, prod1_3=0, prod2_3=0;

    for(int i=0;i<N;i++){
        cin >> pag_1[i];
    }
    for(int i=0;i<N;i++){
        cin >> pag_2[i];
    }
    for(int i=0;i<N;i++){
        cin >> pag_3[i];
    }

    for(int i=0;i<N;i++){
        prod1_2 += pag_1[i]*pag_2[i]; 
    }
    for(int i=0;i<N;i++){
        prod1_3 += pag_1[i]*pag_3[i]; 
    }
    for(int i=0;i<N;i++){
        prod2_3 += pag_2[i]*pag_3[i]; 
    }

    if(prod1_2 > prod1_3 && prod1_2 > prod2_3){cout << "1 2" << endl;}
    else if(prod1_3 > prod1_2 && prod1_3 > prod2_3){cout << "1 3" << endl;}
    else{cout << "2 3" << endl;}

    return 0;
}