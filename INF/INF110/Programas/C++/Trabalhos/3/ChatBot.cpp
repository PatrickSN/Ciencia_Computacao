#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
using namespace std;

void imprime_saudacoes(char nome[]){
    char saudacao[3][100]={ ", o seu conselheiro do zodíaco.",
                            ", Eu sei falar sobre signos do zodíaco.",
                            ", estou aqui para falar sobre signos."
    };
    char apresentacao[][100]={  "Olá, meu nome é ",
                                "Oi, me chamo ",
                                "Olá eu me chamo "
    };
    
    srand(time(NULL));
    cout << apresentacao[rand()%3] << nome << saudacao[rand()%3] << "Qual o seu nome?" << endl;
}

void imprime_despedida(){
    char despedida[4][20]={"Até logo!", "Tchau!", "Até mais!","A gente se vê!"};
    char finalizacao[2][40]={"Volte sempre!","Foi um prazer falar com você."};
    srand (time(NULL));
    cout << despedida[rand()%3] << finalizacao[rand()%2] << endl;
}

int verifica_palavra(int ctrl,char frase[],char chave[]){
    int i=0, aux=0;

    if(ctrl == 0){//usada para comparar frase com frase
//inicializa a variavel auxiliar de frase e cria o token frase
        char frase_aux[strlen(frase)];
        strcpy(frase_aux,frase);

        char *token_frase = strtok(frase_aux, " ,.-");
//******************************************************
//inicializa a variavel auxiliar da chave e cria o token chave
        char chave_aux[strlen(chave)];
        strcpy(chave_aux,chave);
        
//******************************************************
//percorre as frases e compara as palavras  
        while(token_frase != NULL){
            char *token_chave = strtok(chave_aux, " ,.-");
            while(token_chave != NULL){
                if(strcmp(token_frase,token_chave) == 0){
                    aux = 1;
                    break;
                }
                token_chave = strtok(NULL, " ,.-");
            }
            if(aux == 1){
                break;
            }
            token_frase = strtok(NULL, " ,.-");
        }
    }//fim do ctrl 0

    else if(ctrl ==1){//usada para comprar frase com palavra
//inicializa a variavel da frase auxiliar e cria o token frase
        char frase_aux[strlen(frase)];
        strcpy(frase_aux,frase);

        char *token_frase = strtok(frase_aux, " ,.-");
//******************************************************
//inicializa a variavel da chave auxiliar

        char chave_aux[strlen(chave)];
        strcpy(chave_aux,chave);

//******************************************************
//percorre a frase e compara com a chave

        while(token_frase != NULL){
            if(strcmp(token_frase,chave_aux) == 0){
                aux = 1;
                break;
            }
            token_frase = strtok(NULL, " ,.-");
        }
    }//fim do ctrl 1

    return aux;// retorna 1 quando as palavras são iguais e 0 quando nn encontra nenhuma palavra igual
}

void imprime_signo(char signo[]){
    if(strcmp(signo,"Áries") == 0){
        cout << "Áries é o primeiro signo astrológico do zodíaco, situado entre Peixes e Touro e associado à constelação de áries. Seu símbolo é um carneiro. Forma com Leão e Sagitário a triplicidade dos signos do Fogo. É também um dos quatro cardinais, juntamente com Câncer, Libra e Capricórnio. Com pequenas variações nas datas dependendo do ano, os arianos são as pessoas nascidas entre 21 de março e 20 de abril." << endl;
    }
    
    else if(strcmp(signo,"Touro") == 0){
        cout << "Touro é o segundo signo astrológico do zodíaco, situado entre Áries e Gêmeos e associado à constelação de Taurus. Seu símbolo é um touro. Forma com Virgem e Capricórnio a triplicidade dos signos da Terra. É também um dos quatro signos fixos, juntamente com Leão, Escorpião e Aquário. Com pequenas variações nas datas dependendo do ano, os taurinos são as pessoas nascidas entre 21 de abril e 20 de maio." << endl;
    }

    else if(strcmp(signo,"Gêmeos") == 0){
        cout << "Gêmeos é o terceiro signo astrológico do zodíaco, situado entre Touro e Câncer e associado à constelação de Gemini. Seu símbolo são os irmãos gêmeos. Forma com Libra e Aquário a triplicidade dos signos do Ar. É também um dos quatro signos mutáveis, juntamente com Virgem, Sagitário e Peixes. Com pequenas variações nas datas dependendo do ano, os geminianos e geminianas são as pessoas nascidas entre 21 de Maio e 20 de Junho." << endl;
    }

    else if(strcmp(signo,"Câncer") == 0){
        cout << "Câncer é o quarto signo astrológico do zodíaco, situado entre Gêmeos e Leão e associado à constelação de Cancer. Seu símbolo é um caranguejo. Forma com Escorpião e Peixes a triplicidade dos signos da Água. É também um dos quatro cardinais, juntamente com Áries, Libra e Capricórnio. Com pequenas variações nas datas dependendo do ano, os cancerianos são as pessoas nascidas entre 21 de Junho e 22 de Julho." << endl;
    }

    else if(strcmp(signo,"Leão") == 0){
        cout << "Leão é o quinto signo astrológico do zodíaco, situado entre Câncer e Virgem e associado à constelação de Leo. Seu símbolo é um leão. Forma com Áries e Sagitário a triplicidade dos signos do Fogo. É também um dos quatro signos fixos, juntamente com Touro, Escorpião e Aquário. Com pequenas variações nas datas dependendo do ano, os leoninos e leoninas são as pessoas nascidas entre 22 de Julho e 23 de Agosto." << endl;
    }

    else if(strcmp(signo,"Virgem") == 0){
        cout << "Virgem é o sexto signo astrológico do zodíaco, situado entre Leão e Libra e associado à constelação de Virgo. Seu símbolo é uma virgem. Forma com Touro e Capricórnio a triplicidade dos signos da Terra. É também um dos quatro signos mutáveis, juntamente com Gêmeos, Sagitário e Peixes. Com pequenas variações nas datas dependendo do ano, os virginianos e virginianas são as pessoas nascidas entre 23 de agosto e 22 de setembro." << endl;
    }

    else if(strcmp(signo,"Libra") == 0){
        cout << "Libra é o sétimo signo astrológico do zodíaco, situado entre Virgem e Escorpião e associado à constelação de Libra. Seu símbolo é uma balança. Forma com Gêmeos e Aquário a triplicidade dos signos do Ar. É também um dos quatro signos cardinais, juntamente com Áries, Câncer e Capricórnio. Com pequenas variações nas datas dependendo do ano, os librianos e librianas são as pessoas nascidas entre 23 de setembro e 22 de outubro." << endl;
    }

    else if(strcmp(signo,"Escorpião") == 0){
        cout << "Escorpião é o oitavo signo astrológico do Zodíaco, originário da constelação de Scorpius. Sob o zodíaco tropical, o Sol transita em média entre 23 de outubro e 22 de novembro. Escorpião é um dos três signos de água, junto de Câncer e Peixes. É um signo fixo e negativo. Nos tempos antigos, Escorpião era associado ao planeta Marte. Depois que Plutão foi descoberto em 1930, tornou-se associado a Escorpião. Escorpião está associado a três animais diferentes: o escorpião, a cobra e a águia (ou fênix). A cobra e a águia estão relacionadas às constelações próximas de Ophiuchus e Aquila. Escorpião também está associado à divindade grega Ártemis, que dizem ter criado a constelação de Scorpius. De acordo com a Bíblia da Astrologia, as cores de Escorpião são vermelho escuro, marrom e preto." << endl;
    }

    else if(strcmp(signo,"Sagitário") == 0){
        cout << "Sagitário é o nono signo astrológico do zodíaco, situado entre Escorpião  e Capricórnio e associado à constelação de Sagittarius. Seu símbolo é o centauro. Forma com Áries e Leão a triplicidade dos signos do Fogo. É também um dos quatro signos mutáveis, juntamente com Gêmeos, Virgem e Peixes. Com pequenas variações nas datas dependendo do ano, os sagitarianos e sagitarianas são as pessoas nascidas entre 22 de novembro e 21 de dezembro." << endl;
    }

    else if(strcmp(signo,"Capricórnio") == 0){
        cout << "Capricórnio é o décimo signo astrológico do zodíaco, situado entre Sagitário e Aquário e associado à constelação de Capricornus. Seu símbolo é uma cabra. Forma com Touro e Virgem a triplicidade dos signos da Terra. É também um dos quatro signos cardinais, juntamente com Áries, Câncer e Libra. Com pequenas variações nas datas dependendo do ano, os capricornianos são as pessoas nascidas entre 22 de dezembro e 20 de janeiro." << endl;
    }

    else if(strcmp(signo,"Aquário") == 0){
        cout << "Aquário é o décimo primeiro signo astrológico do zodíaco, situado entre Capricórnio e Peixes e associado à constelação de Aquarius. Seu símbolo é o aguadeiro. Forma com Gêmeos e Libra a triplicidade dos signos do Ar. É também um dos quatro signos fixos, juntamente com Touro, Leão e Escorpião. Com pequenas variações nas datas dependendo do ano, os aquarianos e aquarianas são as pessoas nascidas entre 21 de janeiro e 19 de fevereiro." << endl;
    }

    else if(strcmp(signo,"Peixes") == 0){
        cout << "Peixes é o décimo segundo, e último signo astrológico do zodíaco, situado entre Aquário e Áries e associado à constelação de Pisces. Seu símbolo são dois peixes. Forma com Câncer e Escorpião a triplicidade dos signos da Água. É também um dos quatro signos mutáveis, juntamente com Gêmeos, Virgem e Sagitário. Com pequenas variações nas datas dependendo do ano, os piscianos são as pessoas nascidas entre 20 de Fevereiro e 20 de Março." << endl;
    }
    return;
}

int main(){
    char name_Bot[7] = "ZodBot";//coloquei cm variavel para caso de mudança do nome
    imprime_saudacoes(name_Bot);// inicializa o dialogo com uma saudação aleatoria

    setlocale(LC_ALL, "portuguese");
    char palavras_chave[]="olá ola olÁ o meu nome é É eh eu sou me chamo pode chamar";//palavras chave de quando uma pessoa vai se aprensentar
    char meses[]={"janeiro fevereiro março marÇo marco abril maio junho julho agosto setembro outubro novembro dezembro"};//meses do ano 
    char signos[]={"áries Áries aries touro gêmeos gÊmeos gemeos câncer cancer cÂncer leão leÃo leao virgem libra escorpião escorpiÃo escorpiao sagitário sargitÁrio sargitario capricórnio capricÓrnio capricornio aquário aquÁrio aquario peixes"};//signos existentes
    char desp[]={"até mais atÉ ate tchau logo xau flw falou"};
    int data_lim=0;
    char meses30[]={"Abril Junho Setembro Novembro"};
    char meses31[]={"Janeiro Março Maio Julho Agosto Outubro Dezembro"};
    int i=0,j=0, cont=0;

    while(true){ 
        char campo_entrada[100];
        ;

        cin.getline(campo_entrada,100);
        char name_user[strlen(campo_entrada)]="\0";

        for(i=0;campo_entrada[i]!='\0';i++){//coloca tds os caracteres em caixa baixa
            campo_entrada[i] = tolower(campo_entrada[i]);
        }

        if(verifica_palavra(0,campo_entrada,desp) == 1){break;}//finaliza o dialogo

    //*************************************************************************************************************************************************

        if(verifica_palavra(0,campo_entrada,palavras_chave) == 1 && cont == 0){//verifica se eh uma frase com as palavras chave para descobrir o nome 
            i=0;
            
            while(true){
                for(j=i;campo_entrada[j]!=' ';j++){//salva palavra por palavra na variavel name_user para dps verifica-la
                    name_user[j-i] = campo_entrada[j];
                    if(campo_entrada[j] == '\0'){
                        break;
                    }
                }
                name_user[j-i] = '\0';
                
                if(verifica_palavra(1,palavras_chave,name_user) == 0){//diferencia o nome das palavras-chave
                    name_user[0] = toupper(name_user[0]);
                    break;
                }
                
                i+=strlen(name_user)+1;//inicia o j na proxima palavra
                
                if(campo_entrada[i] == '\0'){
                    break;
                }
            }
        }

        else if(cont == 0){
            for(i=0;campo_entrada[i]!='\0';i++){
                name_user[i] = campo_entrada[i];
            }
            name_user[0] = toupper(name_user[0]);
            name_user[i] ='\0';

        }
        
        if(cont == 0){
            cont++;
            cout << "Olá " << name_user << ". Me fale um signo ou mês do ano." << endl;
        }
            
        else{
            cout << "Me fale um signo ou mês do ano." << endl;
        }
    
    //************************************************************************************************************************************************* 

        char msg[30],signo[30];
        cin.getline(campo_entrada,100);

        for(i=0;campo_entrada[i]!='\0';i++){//coloca tds os caracteres em caixa baixa
            campo_entrada[i] = tolower(campo_entrada[i]);
        }

        if(verifica_palavra(0,campo_entrada,desp) == 1){break;}//finaliza o dialogo

        int teste_meses=0, teste_signos=0, aux=0;
        
        while(teste_meses==0 && teste_signos==0){// inicio while de teste dos meses ou signos
            i=0;
        
            for(i=0;campo_entrada[i] != '\0';){
                for(j=i;campo_entrada[j]!=' ';j++){//salva palavra por palavra na variavel msgpara dps verifica-la
                    msg[j-i] = campo_entrada[j];
                    if(campo_entrada[j] == '\0'){
                        break;
                    }
                }
                msg[j-i] = '\0';
        
                if(verifica_palavra(1, meses, msg) == 1){//define o mes/signo 
                    msg[0] = toupper(msg[0]);
                    teste_meses = 1;
                    break;
                }

                else if(verifica_palavra(1, signos, msg)==1){
                    msg[0] = toupper(msg[0]);
                    teste_meses = 1;
                    break;
                }

                i+=strlen(msg)+1;//inicia o j na proxima palavra
            }
            if(teste_meses==0 && teste_signos==0){
                campo_entrada[0]=toupper(campo_entrada[0]);
                cout << campo_entrada << " não é um mês ou signo, por favor escreva um dos dois!" << endl;
                cin.getline(campo_entrada,100);
                        
                for(i=0;campo_entrada[i]!='\0';i++){//coloca tds os caracteres em caixa baixa
                    campo_entrada[i] = tolower(campo_entrada[i]);
                }

                if(verifica_palavra(0,campo_entrada,desp) == 1){//finaliza o dialogo caso a pessoa erre o nome do mes e queira sair 
                    aux++;
                    break;
                }
            }
        }//FIM DO WHILE TESTE

        if(aux != 0){break;}//finaliza o dialogo caso a pessoa erre o nome do mes e queira sair 

        if(teste_meses == 1){//identifica o signo com base no mes e na data 
            cout << "Me fale um dia." << endl;
            int dia=0;
            cin >> dia;
                
            char mes[strlen(msg)];
            strcpy(mes,msg);

            if((strcmp(mes,"Março") == 0 || strcmp(mes,"Marco") == 0 || strcmp(mes,"MarÇo") == 0)){
                strcpy(mes,"Março");
            }

            if(verifica_palavra(1, meses30, mes) == 1){
                data_lim = 30;
            }

            else if(verifica_palavra(1, meses31, mes) == 1){
                data_lim = 31;
            }

            else{
                data_lim = 28;
            }

            while(dia>data_lim || dia<=0){//impede a entrada de uma data invalida
                cout << mes << " não tem " << dia << " dias. Me fale um dia do mês de " << mes << endl;
                cin >> dia;
            }
            
            if(strcmp(mes,"Março") == 0  && dia >= 21){
                strcpy(signo,"Áries");
            }

            else if(strcmp(mes,"Abril") == 0 && dia <= 20){
                strcpy(signo,"Áries");
            }
            
            else if(strcmp(mes,"Abril") == 0 && dia >= 21){
                strcpy(signo,"Touro");
            }

            else if(strcmp(mes,"Maio") == 0 && dia <= 20){
                strcpy(signo,"Touro");
            }
            
            else if((strcmp(mes,"Maio") == 0 && dia >= 21)){
                strcpy(signo,"Gêmeos");
            }

            else if(strcmp(mes,"Junho") == 0 && dia <= 20){
                strcpy(signo,"Gêmeos");
            }

            else if((strcmp(mes,"Junho") == 0 && dia >= 21)){
                strcpy(signo,"Câncer");
            }
            
            else if(strcmp(mes,"Julho") == 0 && dia <= 22){
                strcpy(signo,"Câncer");
            }

            else if((strcmp(mes,"Julho") == 0 && dia >= 23)){
                strcpy(signo,"Leão");
            }

            else if(strcmp(mes,"Agosto") == 0 && dia <= 22){
                strcpy(signo,"Leão");
            }

            else if((strcmp(mes,"Agosto") == 0 && dia >= 23)){
                strcpy(signo,"Virgem");
            }

            else if(strcmp(mes,"Setembro") == 0 && dia <= 22){
                strcpy(signo,"Virgem");
            }

            else if((strcmp(mes,"Setembro") == 0 && dia >= 23)){
                strcpy(signo,"Libra");
            }

            else if(strcmp(mes,"Outubro") == 0 && dia <= 22){
                strcpy(signo,"Libra");
            }

            else if((strcmp(mes,"Outubro") == 0 && dia >= 23)){
                strcpy(signo,"Escorpião");
            }

            else if(strcmp(mes,"Novembro") == 0 && dia <= 21){
                strcpy(signo,"Escorpião");
            }

            else if((strcmp(mes,"Novembro") == 0 && dia >= 22)){
                strcpy(signo,"Sargitário");
            }
            
            else if(strcmp(mes,"Dezembro") == 0 && dia <= 21){
                strcpy(signo,"Sargitário");
            }

            else if((strcmp(mes,"Dezembro") == 0 && dia >= 22)){
                strcpy(signo,"Capricórnio");
            }
            
            else if(strcmp(mes,"Janeiro") == 0 && dia <= 21){
                strcpy(signo,"Capricórnio");
            }

            else if((strcmp(mes,"Janeiro") == 0 && dia >= 21)){
                strcpy(signo,"Aquário");
            }
            
            else if(strcmp(mes,"Fevereiro") == 0 && dia <= 18){
                strcpy(signo,"Aquário");
            }

            else if((strcmp(mes,"Fevereiro") == 0 && dia >= 19)){
                strcpy(signo,"Peixes");
            }
            else if(strcmp(mes,"Março") == 0 && dia <= 20){
                strcpy(signo,"Peixes");
            }
        }//fim da atribuiçao de signo de acordo com mes e a data
            
        else if(teste_signos == 1){//atribui a variavel signo os signos com a escrita correta
            if(strcmp(msg,"áries") == 0 || strcmp(msg,"Áries") == 0 || strcmp(msg,"Aries") == 0){
                strcpy(signo,"Áries");
            }

            else if(strcmp(msg,"Gêmeos") == 0 || strcmp(msg,"GÊmeos") == 0 || strcmp(msg,"Gemeos") == 0){
                strcpy(signo,"Gêmeos");
            }

            else if(strcmp(msg,"Câncer") == 0 || strcmp(msg,"CÂncer") == 0 || strcmp(msg,"Cancer") == 0){
                strcpy(signo,"Câncer");
            }

            else if(strcmp(msg,"Leão") == 0 || strcmp(msg,"Leão") == 0 || strcmp(msg,"Leao") == 0){
                strcpy(signo,"Leão");
            }

            else if(strcmp(msg,"Escorpião") == 0 || strcmp(msg,"EscorpiÃo") == 0 || strcmp(msg,"Escorpiao") == 0){
                strcpy(signo,"Escorpião");
            }

            else if(strcmp(msg,"Sargitário") == 0 || strcmp(msg,"SargitÁrio") == 0 || strcmp(msg,"Sargitario") == 0){
                strcpy(signo,"Sargitário");
            }

            else if(strcmp(msg,"Capricórnio") == 0 || strcmp(msg,"CapricÓrnio") == 0 || strcmp(msg,"Capricornio") == 0){
                strcpy(signo,"Capricórnio");
            }

            else if(strcmp(msg,"Aquário") == 0 || strcmp(msg,"AquÁrio") == 0 || strcmp(msg,"Aquario") == 0){
                strcpy(signo,"Aquário");
            }

            else{
                strcpy(signo,msg);
            }
        }//fim da atribuiçao dos signos

    //*************************************************************************************************************************************************

            imprime_signo(signo);//imprime as imformações sobre o signo solicitado

    }//fim da while q mantem o dialogo
    
    imprime_despedida();//imprime uma despedida aleatoria

return 0;
}