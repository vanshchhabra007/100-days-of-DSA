// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;   // Directed graph
    }

    // Calculate indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) {
                indegree[j]++;
            }
        }
    }

    // Add nodes with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Ordering: ");

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // Reduce indegree of neighbors
        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // If count != n → cycle exists
    if (count != n) {
        printf("\nGraph has a cycle! Topological sort not possible.\n");
    }

    return 0;
}