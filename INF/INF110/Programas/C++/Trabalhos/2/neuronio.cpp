#include <iostream>
#include <math.h>
using namespace  std;

//***************************************************************************************************************

long double sigmoide(double z){// calculo do sigmoide 
    long double euler = 2.7182818284590452353602874;
    long double omega = 0;

    omega =1/(1+pow(euler, -z));
    return omega;
};

//***************************************************************************************************************

double produto_interno(double Matriz_x[][2], double Vet_w[], int n){//calcula o produto interno entre os vetores
    double Z=0;
    for(int i=0; i<2; i++){
        Z += Matriz_x[n][i]*Vet_w[i]; 
    }
    return Z;
};

//***************************************************************************************************************

void treinamento(double w[]){// funçao de treinamento e execuçao do neuronio
    double x[10][2]={{2.7,10.5},
                     {1.5,11.8},
                     {5.5,20.0},
                     {3.5,15.2},
                     {3.1,14.5},
                     {7.6,14.5},
                     {1.5, 3.5},
                     {6.9, 8.5},
                     {8.6, 2.0},
                     {7.66,3.5}};
    double y[10]={0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 , 1 };
    double z=0 , o=0, erro=0, alfa=0.1;

    for(int i=0;i<1000;i++){
        for(int j=0;j<10;j++){
            z = produto_interno(x, w, j);
            o = sigmoide(z);
            erro = y[j]-o;
            for(int l=0; l<2; l++){
                w[l] = w[l] + alfa * erro * o * (1-o) * x[j][l];
            }
        }
    }
    return;
}

//***************************************************************************************************************

void imprima(double O){
    if(O > 0.5){cout << 1 << endl;}
    else{cout << 0 << endl;}
    return;
}

//***************************************************************************************************************

int main(){
    double peso[2]={0.5,0.5};
    treinamento(peso);//treina o neuronio
    double valores[1][2]={0.0,0.0}, z=0.0, o=0.0;

    for(int i=0;i<2;i++){cin >> valores[0][i];}// entrada do valor do salario e do emprestimo

    z = produto_interno(valores, peso,0);//calculo do valor do produto interno das entradas
    o = sigmoide(z);
    imprima(o);// imprime se o emprestimo foi aceito ou se nn

    return 0;
}