#include <iostream>
#include <cstdlib>
#include <ctime> //time
#include <algorithm>
#include <stdlib.h> //clear
#include <iomanip>
#include <vector>

using namespace std;
int qtdcartelas, qtddezenas, limite, somador;
vector<double>precos;

int inicializador();
void gerador_de_dezenas_aleatorias();
void Mega_Sena();
void valor_gasto();
void Quina();
void Lotomania();
void Lotofacil();
double calculador_de_valor_gasto();

int main (){

    setlocale(LC_ALL, "portuguese");
    cout << fixed << setprecision(2);

    inicializador();

    return 0;
}

int inicializador(){
int jogo;
    cout << "*****GERADOR DE APOSTAS ALEATÓRIAS*****\n\n";
    cout << "Escolha um dos jogos a seguir, digitando o número corespondente a opção desejada:\n";
    cout << "[1]Mega-Sena\n[2]Quina\n[3]Lotomania\n[4]Lotofácil\n[0]sair\n\n";
    cin >> jogo;
    while(jogo < 0 || jogo > 4) {
        cout << "Opção inválida! Digite novamente:";
        cin >> jogo;
    }

    system("cls");

    if (jogo == 0){
        exit(0);
    }

    else{

        do {
            cout << "\nQuantas cartelas você deseja jogar? ";
            cin >> qtdcartelas;
        } while(qtdcartelas <= 0);
    }

        switch(jogo) {

    case 1:
        Mega_Sena();
    break;

    case 2:
        Quina();
    break;

    case 3:
        Lotomania();
    break;

    case 4:
        Lotofacil();
    break;
    }
}

void gerador_de_dezenas_aleatorias(){

    vector<int>dezenas;
    int sorteado;

    srand(time(NULL));

    while(dezenas.size() <= qtddezenas){

        bool esta_repetido = false;

        sorteado = (rand() % limite)+ somador;

        for(int i = 0; i < dezenas.size(); i++){
            if(sorteado == dezenas[i]){
                esta_repetido = true;
            }
        }

        if(!esta_repetido){
            dezenas.push_back(sorteado);
        }
    }

sort(dezenas.begin(), dezenas.end());

    for(int deze:dezenas){
        cout << deze << " ";
    }

}

void Mega_Sena(){

    limite = 60;
    somador = 1;

    precos.push_back(0);
    precos.push_back(3.50);
    precos.push_back(24.50);
    precos.push_back(98);
    precos.push_back(294);
    precos.push_back(735);
    precos.push_back(1617);
    precos.push_back(3234);
    precos.push_back(6006);
    precos.push_back(10510.50);
    precos.push_back(17517.50);

    cout << setw(5) << "\n\nTabela de preços da Mega Sena" << setw(5) << endl << endl;
    cout << "n° dezenas" << setw(1) << "|"  << setw(1) << "preço(R$)" << endl;
    for(int i = 6, j = 1; i <= 15; i++, j++){
        cout << i << setw(11) << precos[j] << endl;
    }
    for (int i = 0; i < qtdcartelas; i++) {
        cout << "\n\n---" << i + 1 << "° Cartela---\n";
        cout << "\n\nQuantas dezenas você deseja sortear nessa cartela? ";
        cin >> qtddezenas;
        while (qtddezenas < 6 || qtddezenas > 15) {
            cout << "Você digitou um número de dezenas inválido. Digite novamente: ";
            cin >> qtddezenas;
        }
        gerador_de_dezenas_aleatorias();
        cout << "\n\nVocê gastou R$" << calculador_de_valor_gasto() << " nessa cartela\n\n\n";

        }
}

void Quina() {
    limite = 81;
    somador = 1;

    precos.push_back(1.50);
    precos.push_back(9);
    precos.push_back(31.50);
    precos.push_back(84);
    precos.push_back(189);
    precos.push_back(378);
    precos.push_back(693);
    precos.push_back(1188);
    precos.push_back(1930.50);
    precos.push_back(3003);
    precos.push_back(4504.50);

    cout << setw(5) << "\n\nTabela de preços da Quina" << setw(5) << endl << endl;
    cout << "n° dezenas" << setw(1) << "|"  << setw(1) << "preço(R$)" << endl;
    for(int i = 5, j = 0; i <= 15; i++, j++){
        cout << i << setw(11) << precos[j] << endl;
    }

    for (int i = 0; i < qtdcartelas; i++){
        cout << "\n\n---" << i + 1 << "° Cartela---\n";
        cout << "\n\nQuantas dezenas você deseja sortear nessa cartela? ";
        cin >> qtddezenas;
        while (qtddezenas < 5 || qtddezenas > 15) {
            cout << "Você digitou um número de dezenas inválido. Digite novamente: ";
            cin >> qtddezenas;
    }

    gerador_de_dezenas_aleatorias();
    cout << "\n\nVocê gastou R$" << calculador_de_valor_gasto() << " nessa cartela\n\n\n";
    }
}

void Lotomania(){
    precos.push_back(1.50);
    limite = 100;
    somador = 0;
    qtddezenas = 50;
    cout << "\nA Lotomania possui um único preço e um único número de dezenas: 50 dezenas por R$1.50\n\n";
    for (int i = 0; i < qtdcartelas; i++) {
        cout << "---" << i + 1 << "° Cartela---\n";
        gerador_de_dezenas_aleatorias();
        cout << endl << endl;
    }
}

void Lotofacil() {
    limite = 25;
    somador = 1;


    precos.push_back(0);
    precos.push_back(0);
    precos.push_back(0);
    precos.push_back(0);
    precos.push_back(0);
    precos.push_back(0);
    precos.push_back(0);
    precos.push_back(0);
    precos.push_back(0);
    precos.push_back(0);
    precos.push_back(2);
    precos.push_back(32);
    precos.push_back(272);
    precos.push_back(1632);

    cout << setw(5) << "\n\nTabela de preços da Lotofácil" << setw(5) << endl << endl;
    cout << "n° dezenas" << setw(1) << "|"  << setw(1) << "preço(R$)" << endl;
    cout << fixed << setprecision(2);
    for(int i = 15, j = 10; i <= 18; i++, j++){
        cout << i << setw(11) << precos[j] << endl;
    }

    for (int i = 0; i < qtdcartelas; i++){
        cout << "\n\n---" << i + 1 << "° Cartela---\n";
        cout << "\n\nQuantas dezenas você deseja sortear? ";
        cin >> qtddezenas;
        while (qtddezenas < 15 || qtddezenas > 18) {
            cout << "Você digitou um número de dezenas inválido. Digite novamente: ";
            cin >> qtddezenas;
        }
        gerador_de_dezenas_aleatorias();
        cout << "\n\nVocê gastou R$" << calculador_de_valor_gasto() << " nessa cartela\n\n\n";
    }
}


double calculador_de_valor_gasto() {
    for(int i = 0, j = 5; i <= 14; i++, j++){
        if(qtddezenas == j){
            return precos[i];
        }
    }
}






