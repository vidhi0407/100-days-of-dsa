#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int empty() {
    return (front == -1);
}

int size() {
    if (front == -1) return 0;
    if (rear >= front)
        return rear - front + 1;
    return MAX - front + rear + 1;
}

void push_front(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    dq[front] = x;
}

void push_back(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    dq[rear] = x;
}

int pop_front() {
    if (empty()) return -1;

    int val = dq[front];

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }

    return val;
}

int pop_back() {
    if (empty()) return -1;

    int val = dq[rear];

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }

    return val;
}

int getFront() {
    if (empty()) return -1;
    return dq[front];
}

int getBack() {
    if (empty()) return -1;
    return dq[rear];
}

void display() {
    if (empty()) return;

    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char op[20];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') { 
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0] == 'p' && op[5] == 'b') { 
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0] == 'p' && op[4] == 'f') { 
            printf("%d\n", pop_front());
        }
        else if (op[0] == 'p' && op[4] == 'b') { 
            printf("%d\n", pop_back());
        }
        else if (op[0] == 'f') { 
            printf("%d\n", getFront());
        }
        else if (op[0] == 'b') { 
            printf("%d\n", getBack());
        }
        else if (op[0] == 'e') { 
            printf("%d\n", empty());
        }
        else if (op[0] == 's') { 
            printf("%d\n", size());
        }
    }

    display();

    return 0;
}