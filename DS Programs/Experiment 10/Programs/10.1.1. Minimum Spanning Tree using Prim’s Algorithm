#include <stdio.h>
#include <stdbool.h>

#define V 100

// Function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[], int vertices) {
    int min = 1000000, min_index = -1;

    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's Algorithm
void prim(int graph[V][V], int vertices) {
    int parent[V];   // Stores constructed MST
    int key[V];      // Minimum weight edge
    bool mstSet[V];  // Included in MST or not

    // Initialize all keys as infinite and mstSet as false
    for (int i = 0; i < vertices; i++) {
        key[i] = 1000000;
        mstSet[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1;

    // MST will have vertices-1 edges
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;

        // Update key and parent for adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]);
    }
}

// Main function
int main() {
    int vertices;
    int graph[V][V];

    printf("No of vertices: ");
    scanf("%d", &vertices);

    printf("Adjacency matrix elements (row wise):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, vertices);

    return 0;
}
