#include <iostream>

using namespace std;

#include "Pilha/ModeloPilha.hpp"
#include "Hanoi/Jogada.hpp"
#include "Hanoi/Mostra.hpp"
#include "Hanoi/GeraDiscos.hpp"

int main() {
    setlocale(LC_ALL, "portuguese");

    Pilha H1, H2, H3;

    Set(&H1);
    Set(&H2);
    Set(&H3);

    H1.discos = H2.discos = H3.discos = getDiscos();

    int jogadas = getJogadas(&H1, H1.discos);

    while(jogadas > 0) {
        Mostra(&H1, &H2, &H3, jogadas, false);

        if(Jogada(&H1, &H2, &H3)) {
            jogadas--;
        } else {
            cout << "\nOpção inválida!" << endl;
            getchar();
        }

        if(Overflow(&H3)) {
            Mostra(&H1, &H2, &H3, jogadas, true);
            cout << "\nVocê venceu o jogo, Parabéns!!!!" << endl;
            break;
        } else {
            if(jogadas <= 0) {
                system("cls");
                cout << "\nVocê perdeu, tente novamente!" << endl;
                break;
            }
        }
    }

    return 0;
}
