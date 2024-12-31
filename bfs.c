#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Queue structure for BFS
typedef struct {
    int items[MAX_NODES];
    int front, rear;
} Queue;

// Graph structure
typedef struct Graph {
    int vertices;
    int** adjMatrix;
} Graph;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isQueueEmpty(Queue* q);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void bfs(Graph* graph, int startVertex);
void freeGraph(Graph* graph);

int main() {
    int vertices, edges, src, dest, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source and destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);
    bfs(graph, startVertex);

    freeGraph(graph);
    return 0;
}

// Create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }

    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For an undirected graph
}

// BFS implementation
void bfs(Graph* graph, int startVertex) {
    int visited[MAX_NODES] = {0}; // Keep track of visited vertices
    Queue* q = createQueue();

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isQueueEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        // Enqueue all adjacent unvisited vertices
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }

    free(q); // Free the queue
    printf("\n");
}

// Create a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Add an element to the queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full!\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;
    q->items[q->rear] = value;
}

// Remove an element from the queue
int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int item = q->items[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return item;
}

// Check if the queue is empty
int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

// Free memory allocated for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}
