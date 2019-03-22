#define TAM 8

struct Stack {
    int disks;
    int sizeT;
    int top;
    int base;
    int data[TAM];
};

void set(Stack *stack) {
    stack->sizeT = TAM;
    stack->base = -1;
    stack->top = stack->base;

    for(int i = 0; i < stack->sizeT; i++) {
        stack->data[i] = NULL;
    }
}

bool overflow(Stack *stack) {
    return (stack->top == (stack->disks - 1)) ? true : false;
}

bool underflow(Stack *stack) {
    return (stack->top == stack->base) ? true : false;
}

void push(Stack *stack, int num) {
    stack->top = stack->top + 1;
    stack->data[stack->top] = num;
}

int pop(Stack *stack) {
    int value = NULL;

    if (!underflow(stack)) {
        value = stack->data[stack->top];
        stack->data[stack->top] = NULL;
        stack->top--;
    }

    return value;
}

int peek(Stack *stack) {
    if(!underflow(stack))
        return (stack->data[stack->top]);
}
