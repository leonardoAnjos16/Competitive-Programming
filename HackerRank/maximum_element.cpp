#include <iostream>

using namespace std;

struct Node {
    int element;
    Node *next;
};

Node *create_node(int element, Node *next) {
    Node *newNode = new Node();
    newNode->element = element;
    newNode->next = next;
    return newNode;
}

struct Stack {
    Node *top;
    int size, max;
};

Stack *create_stack() {
    Stack *stack = new Stack();
    stack->top = NULL;
    stack->size = stack->max = 0;
    return stack;
}

void clear(Stack *stack) {
    while (stack->top != NULL) {
        Node *newTop = stack->top->next;
        delete stack->top;
        stack->top = newTop;
    }

    stack->top = NULL;
    stack->size = 0;
}

void push(Stack *stack, int element) {
    stack->top = create_node(element, stack->top);
    stack->size++;

    if (element > stack->max) stack->max = element;
}

int get_max(Stack *stack) {
    Node *curr = stack->top;
    int maxValue = 0;

    while (curr != NULL) {
        if (curr->element > maxValue) maxValue = curr->element;
        curr = curr->next;
    }

    return maxValue;
}

void pop(Stack *stack) {
    int topValue = stack->top->element;
    Node *newTop = stack->top->next;
    delete stack->top;
    stack->top = newTop;
    stack->size--;

    if (topValue == stack->max) stack->max = get_max(stack);
}

int main() {
    int numOps;
    cin >> numOps;

    Stack *stack = create_stack();
    for (int i = 0; i < numOps; i++) {
        int op, element;
        cin >> op;

        switch(op) {
            case 1:
                cin >> element;
                push(stack, element);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                cout << stack->max << endl;
                break;
        }
    }

    clear(stack);
    delete stack;
    return 0;
}