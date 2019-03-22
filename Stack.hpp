#define TAM 8

class Stack {
public:
    int disks;
    int sizeT;
    int top;
    int base;
    int data[TAM];

    Stack() {
        sizeT = TAM;
        base = -1;
        top = base;

        for(int i = 0; i < sizeT; i++) {
            data[i] = NULL;
        }
    }

    bool overflow() {
        return (top == (disks - 1)) ? true : false;
    }

    bool underflow() {
        return (top == base) ? true : false;
    }

    void push(int num) {
        top = top + 1;
        data[top] = num;
    }

    int pop() {
        int value = NULL;

        if (!underflow()) {
            value = data[top];
            data[top] = NULL;
            top--;
        }

        return value;
    }

    int peek() {
        return !underflow() ? data[top] : -1;
    }
};






