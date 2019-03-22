#include <cstdlib>

/** Função que mostra as torres de Hanoi */

void showWhiteSpace(int value) {
    for(int j = 0; j < value; j++) {
        cout << " ";
    }
}

void showStackValue(int value) {
    string hifen = "";

    for(int j = 0; j < value; j++) {
        hifen += "-";
    }

    cout << hifen << "|" << hifen;
}

void showStackContext(Stack *stack, int value) {
    showWhiteSpace(stack->sizeT - stack->data[value]);
    showStackValue(stack->data[value]);
    showWhiteSpace(stack->sizeT - stack->data[value]);
}

void showAll(Stack *leftStack, Stack *centerStack, Stack *rightStack, int remainingPlays, bool hasWin) {
    system("cls");

    if(!hasWin && remainingPlays != 0) {
        cout << "Você possui " << remainingPlays << " jogadas!" << endl << endl;
    }

    for(int x = leftStack->sizeT-1; x > leftStack->base; x--) {
        showStackContext(leftStack, x);
        showStackContext(centerStack, x);
        showStackContext(rightStack, x);
        cout << endl;
    }

    cout << "---------------------------------------------------" << endl;
}
