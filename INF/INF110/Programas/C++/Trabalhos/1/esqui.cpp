#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    double distancia;
    double nota1, nota2, nota3, nota4, nota5;
    double nota_distancia, nota_estilo, score;
    cin >> distancia;
    cin >> nota1 >> nota2 >> nota3 >> nota4 >> nota5;

    //calcula a nota da distancia
    nota_distancia = 1.8*(distancia-120) + 60;
    /*if (nota_distancia < 0){
        nota_distancia = 0;
    }*/
    // descobre a menor e a maior nota desconsiderando-as 
    if (nota1>=nota2 && nota1>=nota3 && nota1>=nota4 && nota1>=nota5){
        if (nota2<=nota3 && nota2<=nota4 && nota2<=nota5){
            nota_estilo = nota3+nota4+nota5;
        } 
        if (nota3<=nota2 && nota3<=nota4 && nota3<=nota5){
            nota_estilo = nota2+nota4+nota5;
        }
        if (nota4<=nota2 && nota4<=nota3 && nota4<=nota5){
            nota_estilo = nota2+nota3+nota5;
        }
        if (nota5<=nota2 && nota5<=nota3 && nota5<=nota4){
            nota_estilo = nota2+nota3+nota4;
        }
    }

    if (nota2>=nota1 && nota2>=nota3 && nota2>=nota4 && nota2>=nota5){
        if (nota1<=nota3 && nota1<=nota4 && nota1<=nota5){
            nota_estilo = nota3+nota4+nota5;
        } 
        if (nota3<=nota1 && nota3<=nota4 && nota3<=nota5){
            nota_estilo = nota1+nota4+nota5;
        }
        if (nota4<=nota1 && nota4<=nota3 && nota4<=nota5){
            nota_estilo = nota1+nota3+nota5;
        }
        if (nota5<=nota1 && nota5<=nota3 && nota5<=nota4){
            nota_estilo = nota1+nota3+nota4;
        }
    }  

    if (nota3>=nota1 && nota3>=nota2 && nota3>=nota4 && nota3>=nota5){
        if (nota1<=nota2 && nota1<=nota4 && nota1<=nota5){
            nota_estilo = nota2+nota4+nota5;
        } 
        if (nota2<=nota1 && nota2<=nota4 && nota2<=nota5){
            nota_estilo = nota1+nota4+nota5;
        }
        if (nota4<=nota1 && nota4<=nota2 && nota4<=nota5){
            nota_estilo = nota1+nota2+nota5;
        }
        if (nota5<=nota1 && nota5<=nota2 && nota5<=nota4){
            nota_estilo = nota1+nota2+nota4;
        }
    }

    if (nota4>=nota1 && nota4>=nota2 && nota4>=nota3 && nota4>=nota5){
            if (nota1<=nota2 && nota1<=nota3 && nota1<=nota5){
                nota_estilo = nota2+nota3+nota5;
            } 
            if (nota2<=nota1 && nota2<=nota3 && nota2<=nota5){
                nota_estilo = nota1+nota3+nota5;
            }
            if (nota3<=nota1 && nota3<=nota2 && nota3<=nota5){
                nota_estilo = nota1+nota2+nota5;
            }
            if (nota5<=nota1 && nota5<=nota2 && nota5<=nota3){
                nota_estilo = nota1+nota2+nota3;
            }
        }

    if (nota5>=nota1 && nota5>=nota2 && nota5>=nota3 && nota5>=nota4){
            if (nota1<=nota2 && nota1<=nota3 && nota1<=nota4){
                nota_estilo = nota2+nota3+nota4;
            } 
            if (nota2<=nota1 && nota2<=nota3 && nota2<=nota4){
                nota_estilo = nota1+nota3+nota4;
            }
            if (nota3<=nota1 && nota3<=nota2 && nota3<=nota4){
                nota_estilo = nota1+nota2+nota4;
            }
            if (nota4<=nota1 && nota4<=nota2 && nota4<=nota3){
                nota_estilo = nota1+nota2+nota3;
            }
        }
    score = nota_distancia+nota_estilo;
    /*if (score < 0){
        score = 0;
    }*/

    cout << fixed << setprecision(1) << score << endl;

return 0;
}
