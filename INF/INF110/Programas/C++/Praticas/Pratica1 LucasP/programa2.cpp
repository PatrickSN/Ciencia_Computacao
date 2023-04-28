//Programa 2: calculo da nota final de um candidato a monitoria
#include <iostream>
int main(){

    int entrevista, curriculo, prova, media; // notas do candidato
    int total; // total de pontos
    //Leitura dos dados
    std::cout << "Escreva a nota da entrevista: ";
    std::cin >> entrevista;
    std::cout << "Escreva a nota do curriculo: ";
    std::cin >> curriculo;
    std::cout << "Escreva a nota da prova: ";
    std::cin >> prova;
    //Cálculo do resultado
    total = entrevista + curriculo + prova;
    media = (entrevista+curriculo+prova)/3;
    std::cout << "Nota final do candidato: " << total << std::endl;
    std::cout << "Media final do candidato: " << media << std::endl;
    return 0;
}
