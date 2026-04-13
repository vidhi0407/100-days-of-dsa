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

void dfs(int v, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(temp->data, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[++(*top)] = v; 
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

    int visited[100] = {0};
    int stack[100];
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stack, &top);
        }
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}