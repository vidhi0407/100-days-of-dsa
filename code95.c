#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* curr = *head;
        while (curr->next != NULL && curr->next->data < value) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void bucketSort(float arr[], int n) {
    struct Node* buckets[n];
    for(int i = 0; i < n; i++)
        buckets[i] = NULL;

    for(int i = 0; i < n; i++) {
        int index = n * arr[i];  
        insertSorted(&buckets[index], arr[i]);
    }

    int k = 0;
    for(int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while(curr != NULL) {
            arr[k++] = curr->data;
            curr = curr->next;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}