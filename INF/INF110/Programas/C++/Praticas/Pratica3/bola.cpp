#include <iostream>
using namespace std;

int main(){
    int diametro;
    int altura, largura, profundidade;
    cin >> diametro;
    cin >> altura >> largura >> profundidade;

    if (diametro <= altura && diametro <= largura && diametro <= profundidade)
        cout << "S" << endl;
    else 
        cout << "N" << endl;

return 0;
}