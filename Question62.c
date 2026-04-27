// Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

// Input:
// - n (vertices)
// - m (edges)
// - edges (u, v)

// Output:
// - List of adjacency lists for each vertex

#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;

    // Input vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Create array of adjacency lists
    struct Node* adj[n];

    // Initialize all lists as empty
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add v to u's list
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // For undirected graph, also add u to v's list
        struct Node* newNode2 = createNode(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    // Print adjacency list
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        struct Node* temp = adj[i];

        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}