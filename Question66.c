// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (directed)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function to detect cycle
int dfs(int node, int visited[], int recStack[], struct Node* adj[]) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];
    while (temp) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack, adj))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

// Function to check cycle
int hasCycle(int n, struct Node* adj[]) {
    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[MAX];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v); // directed
    }

    if (hasCycle(n, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}