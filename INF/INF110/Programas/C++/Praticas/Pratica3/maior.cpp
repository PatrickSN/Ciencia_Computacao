#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    if (A>B && A>C)
        cout << A << endl;
    else if (B>A && C<B)
        cout << B << endl;
    else 
        cout << C << endl;
return 0;
}