#include <cstdio>

enum TYPE {
    ORIGIN,
    DESTINY,
    WORK,
};

void logic(Stack context, Stack helper1, Stack helper2) {


}

bool playLogic(Stack *leftStack, Stack *centerStack, Stack *rightStack) {
    string firstChoice;
    string secondChoice;
    int popValue;

    cout << "     [O]rigem        [T]rabalho        [D]estino" << endl;
    cout << "\nEscolha a pilha de onde deseja retirar um disco: ";
    getline(cin, firstChoice);
    fflush(stdin);



    if(firstChoice == "o" || firstChoice == "O") {
        if(underflow(leftStack)) {
            return false;
        }

        cout << "\nVocê escolheu remover um disco da ORIGEM!" << endl;
        cout << "\nEscolha para onde deseja enviar o disco: ";
        getline(cin, secondChoice);
        fflush(stdin);

        if(secondChoice == "t" || secondChoice == "T") {
            if(peek(leftStack) < peek(centerStack) || underflow(centerStack)) {
                popValue = pop(leftStack);
                push(centerStack, popValue);
                return true;
            } else {
                return false;
            }
        } else if(secondChoice == "d" || secondChoice == "D") {
            if(peek(leftStack) < peek(rightStack) || underflow(rightStack)) {
                popValue = pop(leftStack);
                push(rightStack, popValue);
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }

    } else if(firstChoice == "t" || firstChoice == "T") {
        if(underflow(centerStack))
            return false;

        cout << "\nVocê escolheu remover um disco do TRABALHO!" << endl;
        cout << "\nEscolha para onde deseja enviar o disco: ";
        getline(cin, secondChoice);
        fflush(stdin);

        if(secondChoice == "o" || secondChoice == "O") {
            if(peek(centerStack) < peek(leftStack) || underflow(leftStack)) {
                popValue = pop(centerStack);
                push(leftStack, popValue);
                return true;
            } else {
                return false;
            }
        } else if(secondChoice == "d" || secondChoice == "D") {
            if(peek(centerStack) < peek(rightStack) || underflow(rightStack)) {
                popValue = pop(centerStack);
                push(rightStack, popValue);
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    if(firstChoice == "d" || firstChoice == "D") {
        if(underflow(rightStack))
            return false;

        cout << "\nVocê escolheu remover um disco do DESTINO!" << endl;
        cout << "\nEscolha para onde deseja enviar o disco: ";
        getline(cin, secondChoice);
        fflush(stdin);

        if(secondChoice == "t" || secondChoice == "T") {
            if(peek(rightStack) < peek(centerStack)|| underflow(centerStack)) {
                popValue = pop(rightStack);
                push(centerStack, popValue);
                return true;
            } else {
                return false;
            }
        } else if(secondChoice == "o" || secondChoice == "O") {
            if(peek(rightStack) < peek(leftStack) || underflow(leftStack)) {
                popValue = pop(rightStack);
                push(leftStack, popValue);
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}
