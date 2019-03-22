#include <iostream>

using namespace std;

#include "Stack.hpp"
#include "Hanoi/play.hpp"
#include "Hanoi/show.hpp"
#include "Hanoi/generateDisks.hpp"

int main() {
    setlocale(LC_ALL, "portuguese");

    Stack leftStack, centerStack, rightStack;

    set(&leftStack);
    set(&centerStack);
    set(&rightStack);

    leftStack.disks = centerStack.disks = rightStack.disks = getDiscos();

    int remainingPlays = getJogadas(&leftStack, leftStack.disks);

    while(remainingPlays > 0) {
        showAll(&leftStack, &centerStack, &rightStack, remainingPlays, false);

        if(Jogada(&leftStack, &centerStack, &rightStack)) {
            remainingPlays--;
        } else {
            cout << "\nOpção inválida!" << endl;
            getchar();
        }

        if(overflow(&rightStack)) {
            showAll(&leftStack, &centerStack, &rightStack, remainingPlays, true);
            cout << "\nVocê venceu o jogo, Parabéns!!!!" << endl;
            break;
        } else {
            if(remainingPlays <= 0) {
                system("cls");
                cout << "\nVocê perdeu, tente novamente!" << endl;
                break;
            }
        }
    }

    return 0;
}
