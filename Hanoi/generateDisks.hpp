#include <cmath>

/** Função que gera os discos e as jogadas */

int getDisks() {
    int disks = 1;

    cout << "O desafio deste jogo é mover todos os discos da haste de origem para a haste de destino \nutilizando uma haste auxiliar (haste trabalho) e atendendo a algumas regras: " << endl;
    cout << "\n- Somente um disco pode ser movido por vez" << endl;
    cout << "- Um disco maior nunca pode ser posicionado sobre um disco menor" << endl << endl;

    do {
        if(disks < 1 || disks > 8) {
            system("cls");
            cout << disks << " não é um número válido!" << endl << endl;
        }

        cout << "Escolha o número de discos (1 a 8): ";
        cin >> disks;
        fflush(stdin);

    } while(disks < 1 || disks > 8);

    return disks;
}

int getJogadas(Stack *stack, int disks) {
    for(int i = disks; i >= 1; i--) {
        push(stack, i);
    }

    int difficulty = 1;

    do {
        system("cls");
        if(difficulty < 0 || difficulty > 1) {
            cout << difficulty << " não é um número válido!" << endl << endl;
        }

        cout << "Selecione a difficulty: " << endl;
        cout << "[0] Fácil " << endl;
        cout << "[1] Normal " << endl;
        cin >> difficulty;
        fflush(stdin);

    } while(difficulty < 0 || difficulty > 1);

    if(difficulty == 1) {
        return (pow(2, disks) - 1);
    } else if(difficulty == 0) {
        return (pow(2, disks) - 1) * 2;
    }
}
