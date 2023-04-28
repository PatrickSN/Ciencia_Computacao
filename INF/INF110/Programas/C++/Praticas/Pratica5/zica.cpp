#include <iostream>
using namespace std;

int main(){
    long long int pop_in, taxa_rep;
    int i;
    cin >> pop_in >> taxa_rep;
    for(i=0;pop_in<1000000000;i++){
        pop_in = (pop_in*taxa_rep) + pop_in;
    }
    cout << i << endl;
return 0;
}