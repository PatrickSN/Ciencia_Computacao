#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    long long int Ca[n]={0}, Cb[m]={0};
    int cont=0;
    
    for(int i=0;i<n;i++){
        cin >> Ca[i];
    }
    for(int i=0;i<m;i++){
        cin >> Cb[i];
        for(int j=0;j<n;j++){
            if(Ca[j] == Cb[i]){
                cont++;
            }
        }
    }

    if(cont != 0){
        cout << "{";

        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(Ca[k] == Cb[j]){
                    cout << Ca[k] << " ";
                }
            }
        }
    }
    else{
        cout << "{ ";
    }
    cout << "}" <<  endl;
return 0;
}