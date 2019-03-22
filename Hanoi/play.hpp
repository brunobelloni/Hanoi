#include <cstdio>

enum TYPE {
    ORIGIN,
    WORK,
    DESTINY,
};

bool logic(Stack *toPop, Stack *toPush) {
    if(toPop->peek() < toPush->peek() || toPush->underflow()) {
        int popValue = toPop->pop();
        toPush->push(popValue);
        return true;
    }

    return false;
}

bool playLogic(Stack *leftStack, Stack *centerStack, Stack *rightStack) {
    string firstChoice;
    string secondChoice;
    int popValue;

    cout << "     Origem[O]       Trabalho[T]      Destino[D]" << endl;
    cout << "\nEscolha a pilha de onde deseja retirar um disco: ";
    getline(cin, firstChoice);
    fflush(stdin);

    if(firstChoice == "o" || firstChoice == "O") {
        if(leftStack->underflow()) {
            return false;
        }

        cout << "\nVocê escolheu remover um disco da ORIGEM!" << endl;
        cout << "\nEscolha para onde deseja enviar o disco: ";
        getline(cin, secondChoice);
        fflush(stdin);


        if(secondChoice == "t" || secondChoice == "T") {
            return logic(leftStack, centerStack);
        } else if(secondChoice == "d" || secondChoice == "D") {
            return logic(leftStack, rightStack);
        } else {
            return false;
        }

    } else if(firstChoice == "t" || firstChoice == "T") {
        if(centerStack->underflow()) {
            return false;
        }

        cout << "\nVocê escolheu remover um disco do TRABALHO!" << endl;
        cout << "\nEscolha para onde deseja enviar o disco: ";
        getline(cin, secondChoice);
        fflush(stdin);

        if(secondChoice == "o" || secondChoice == "O") {
            return logic(centerStack, leftStack);
        } else if(secondChoice == "d" || secondChoice == "D") {
            return logic(centerStack, rightStack);
        } else {
            return false;
        }
    }
    if(firstChoice == "d" || firstChoice == "D") {
        if(rightStack->underflow()) {
            return false;
        }

        cout << "\nVocê escolheu remover um disco do DESTINO!" << endl;
        cout << "\nEscolha para onde deseja enviar o disco: ";
        getline(cin, secondChoice);
        fflush(stdin);

        if(secondChoice == "t" || secondChoice == "T") {
            return logic(rightStack, centerStack);
        } else if(secondChoice == "o" || secondChoice == "O") {
            return logic(rightStack, leftStack);
        } else {
            return false;
        }
    } else {
        return false;
    }
}
