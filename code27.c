#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }
    return head;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

void findIntersection(struct Node* l1, struct Node* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        while (diff--) l1 = l1->next;
    } else {
        while (diff--) l2 = l2->next;
    }

    while (l1 != NULL && l2 != NULL) {
        if (l1->data == l2->data) {
            printf("%d", l1->data);
            return;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* l1 = createList(n);

    scanf("%d", &m);
    struct Node* l2 = createList(m);

    findIntersection(l1, l2);

    return 0;
}