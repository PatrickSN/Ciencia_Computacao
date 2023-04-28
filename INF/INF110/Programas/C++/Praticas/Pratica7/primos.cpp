#include <iostream>
using namespace std;

bool eh_primo(int N){
	
    int cont=0;

	for (int i=1;i<=N/2;i++){
		if(N%i == 0){cont++;}
    }
    if(cont == 1){return true;}
    else{return false;}
}

int main(){
	int a, b;
	cin >> a >> b;
    cout << "Primos entre " << a << " e " << b << ":";

	for (int i=a;i<=b;i++){
		if (eh_primo(i)){cout << " " << i;}
	}
	cout << endl;

	return 0;
}