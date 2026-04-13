#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    scanf("%d", &n); 
    scanf("%d", &m); 

    struct Node* adj[100];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int indegree[100] = {0};

    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        while (temp) {
            indegree[temp->data]++;
            temp = temp->next;
        }
    }

    int queue[100];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        struct Node* temp = adj[curr];
        while (temp) {
            indegree[temp->data]--;

            if (indegree[temp->data] == 0)
                queue[rear++] = temp->data;

            temp = temp->next;
        }
    }

    if (count != n) {
        printf("\nCycle exists");
    }

    return 0;
}