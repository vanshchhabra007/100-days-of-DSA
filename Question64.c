// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Create queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

// Enqueue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue
int dequeue(struct Queue* q) {
    if (isEmpty(q))
        return -1;

    int item = q->items[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// BFS function
void bfs(int n, struct Node* adj[], int s) {
    int visited[MAX] = {0};
    struct Queue* q = createQueue();

    visited[s] = 1;
    enqueue(q, s);

    printf("BFS Traversal: ");

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);

        struct Node* temp = adj[current];
        while (temp) {
            int adjNode = temp->data;
            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                enqueue(q, adjNode);
            }
            temp = temp->next;
        }
    }
}

// Add edge
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // For undirected graph
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
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
        addEdge(adj, u, v);
    }

    int s;
    printf("Enter source vertex: ");
    scanf("%d", &s);

    bfs(n, adj, s);

    return 0;
}