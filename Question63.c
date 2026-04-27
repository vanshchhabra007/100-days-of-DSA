// Problem: Perform DFS starting from a given source vertex using recursion.

// Input:
// - n
// - adjacency list
// - starting vertex s

// Output:
// - DFS traversal order

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function (recursive)
void DFS(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            DFS(adjVertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // For undirected graph
        struct Node* newNode2 = createNode(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int s;
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("\nDFS Traversal: ");
    DFS(s, adj, visited);

    return 0;
}