#include <stdio.h>
#define SIZE 10

int adj[SIZE][SIZE], visited[SIZE];
int queue[SIZE], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");
    
    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int node, int n) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i])
            dfs(i, n);
    }
}

int main() {
    int n = 5;  // Minimum 5 nodes
    int edges = 6;
    int u, v, start = 0;

    // Adjacency matrix initialization
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            adj[i][j] = 0;

    // Hardcoded edges for 5-node undirected graph
    int edgeList[6][2] = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4}
    };

    for (int i = 0; i < edges; i++) {
        u = edgeList[i][0];
        v = edgeList[i][1];
        adj[u][v] = adj[v][u] = 1;
    }

    // BFS
    bfs(start, n);

    // DFS
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    dfs(start, n);
    printf("\n");

    return 0;
}
