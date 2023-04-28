#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int V[n]={0};
    int cont=1;
    
    for(int i=0;i<n;i++){
        cin >> V[i];
    }    
    for(int j=1;j<n;j++){
        if(V[j] == V[j-1]){
            cont++;
        }
    }
    
    cout << n-cont << endl;
return 0;
}