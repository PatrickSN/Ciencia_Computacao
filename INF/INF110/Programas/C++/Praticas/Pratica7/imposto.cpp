#include <iostream>
#include <iomanip>
using namespace std;

double imposto(double);

int main(){

    double V=0;
    cin >> V;
    while (V!=0)
    {
        cout << "R$ " << fixed << setprecision(2) << imposto(V) << endl;
        cin >> V;
    }
    
}
double imposto(double v){
    //limites:
    float l1=22847.76, l2=33919.8, l3=45012.6, l4=55976.16;
    // aliquontas:
    float al1=0, al2=0.075, al3=0.15, al4=0.225, al5=0.275;
    //deduçao:
    float d1=0, d2=1713.58, d3=4257.57, d4=7633.51, d5=10432.32;
    //Valor a pagar:
    double pg=0;
    
    if(v<=l1){pg=(v*al1)-d1;}
    else if(v<=l2){pg=(v*al2)-d2;}
    else if(v<=l3){pg=(v*al3)-d3;}
    else if(v<=l4){pg=(v*al4)-d4;}
    else{pg=(v*al5)-d5;}
    return pg;
}