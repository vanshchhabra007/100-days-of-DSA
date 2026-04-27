// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];     // Adjacency matrix
int visited[MAX];      
int stack[MAX];
int top = -1;
int n;

// Push into stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    // Push after visiting all neighbors
    push(node);
}

int main() {
    int m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;   // Directed edge
    }

    // Call DFS for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print topological order
    printf("Topological Ordering: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}