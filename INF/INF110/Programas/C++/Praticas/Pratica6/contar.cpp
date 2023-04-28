#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int V[n]={0};
    int X, cont=0;

    for(int i=0;i<n;i++){
        cin >> V[i];
    }
    cin >> X;
    for (int i=0; i<n;i++){
        if(V[i]>=X){
            cont++;
        }
    }
    cout << cont << endl;
return 0;
}