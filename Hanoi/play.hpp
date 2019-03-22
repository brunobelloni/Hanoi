#include <cstdio>

/** Função que executa as jogadas */

bool Jogada(Stack *H1, Stack *H2, Stack *H3) {
    string escolha;
    string enviar;
    int popValue;

    cout << "     [O]rigem        [T]rabalho        [D]estino" << endl;
    cout << "\nEscolha a pilha de onde deseja retirar um disco: ";
    getline(cin, escolha);
    fflush(stdin);


    if(escolha == "o" || escolha == "O") {
        if(underflow(H1))
            return false;

        cout << "\nVocê escolheu remover um disco da ORIGEM!" << endl;
        cout << "\nEscolha para onde deseja enviar o disco: ";
        getline(cin, enviar);
        fflush(stdin);

        if(enviar == "t" || enviar == "T") {
            ///Pop na H1 e PUSH na H2
            if(peek(H1) < peek(H2) || underflow(H2)) {
                popValue = pop(H1);
                push(H2, popValue);
                return true;
            } else {
                return false;
            }
        } else if(enviar == "d" || enviar == "D") {
            ///Pop na H1 e PUSH na H3
            if(peek(H1) < peek(H3) || underflow(H3)) {
                popValue = pop(H1);
                push(H3, popValue);
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }

    } else if(escolha == "t" || escolha == "T") {
        if(underflow(H2))
            return false;

        cout << "\nVocê escolheu remover um disco do TRABALHO!" << endl;
        cout << "\nEscolha para onde deseja enviar o disco: ";
        getline(cin, enviar);
        fflush(stdin);

        if(enviar == "o" || enviar == "O") {
            ///Pop na H2 e PUSH na H1
            if(peek(H2) < peek(H1) || underflow(H1)) {
                popValue = pop(H2);
                push(H1, popValue);
                return true;
            } else {
                return false;
            }
        } else if(enviar == "d" || enviar == "D") {
            ///Pop na H2 e PUSH na H3
            if(peek(H2) < peek(H3) || underflow(H3)) {
                popValue = pop(H2);
                push(H3, popValue);
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    if(escolha == "d" || escolha == "D") {
        if(underflow(H3))
            return false;

        cout << "\nVocê escolheu remover um disco do DESTINO!" << endl;
        cout << "\nEscolha para onde deseja enviar o disco: ";
        getline(cin, enviar);
        fflush(stdin);

        if(enviar == "t" || enviar == "T") {
            ///Pop na H2 e PUSH na H2
            if(peek(H3) < peek(H2)|| underflow(H2)) {
                popValue = pop(H3);
                push(H2, popValue);
                return true;
            } else {
                return false;
            }
        } else if(enviar == "o" || enviar == "O") {
            ///Pop na H2 e PUSH na H1
            if(peek(H3) < peek(H1) || underflow(H1)) {
                popValue = pop(H3);
                push(H1, popValue);
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
