#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int V[n]={0};
    for(int i=0;i<n;i++){
        cin >> V[i];
    }
    for(int i=n-1;i>=0;i--){
        if(i != 0){
            cout << V[i] << " ";
        }
        else{
            cout << V[i] << endl;
        }
    }
return 0;
}