#define TAM 8

/** Função Modificada para Pilhas */

struct Pilha {
    int discos;
    int tam;
    int topo;
    int base;
    int dados[TAM];
};

void Set(Pilha *p) {
    p -> tam  = TAM;
    p -> base = -1;
    p -> topo = p -> base;

    for(int i = 0; i < p -> tam; i++) {
        p -> dados[i] = NULL;
    }
}

bool Overflow(Pilha *p) {
    if (p -> topo == (p -> discos - 1)) {
        return true;
    } else {
        return false;
    }
}

bool Underflow(Pilha *p) {
    if (p -> topo == p -> base) {
        return true;
    } else {
        return false;
    }
}

void Push(Pilha *p, int num) {
    p -> topo = p -> topo + 1;
    p -> dados[p -> topo] = num;
}

int Pop(Pilha *p) {
    int valor = NULL;

    if (!Underflow(p)) {
        valor = p -> dados[p -> topo];
        p -> dados[p -> topo] = NULL;
        p -> topo--;
    }

    return valor;
}

int Peek(Pilha *p) {
    if(!Underflow(p))
        return (p -> dados[p -> topo]);
}
