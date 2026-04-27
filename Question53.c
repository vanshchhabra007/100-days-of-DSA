// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i >= n) break;

        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Pair for queue (node + HD)
struct Pair {
    struct Node* node;
    int hd;
};

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct Pair queue[1000];
    int front = 0, rear = 0;

    // To store result
    int map[2000][100];   // map[hd][nodes]
    int count[2000] = {0};

    int offset = 1000; // to handle negative HD

    // push root
    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = curr->data;

        if (curr->left)
            queue[rear++] = (struct Pair){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (struct Pair){curr->right, hd + 1};
    }

    // Print from leftmost to rightmost
    for (int i = 0; i < 2000; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}