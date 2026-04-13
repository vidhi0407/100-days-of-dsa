#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* exp) {
    struct Node* top = NULL;
    int i = 0;

    while (exp[i] != '\0') {

        if (exp[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(&top, num);
        }
        else {
            int val2 = pop(&top);
            int val1 = pop(&top);

            int result;

            switch (exp[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(&top, result);
            i++;
        }
    }

    return pop(&top);
}

int main() {
    char exp[100];

    fgets(exp, sizeof(exp), stdin);

    printf("%d", evaluatePostfix(exp));

    return 0;
}