#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for an adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define the structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    bool* visited;
} Graph;

// Queue structure for BFS
typedef struct Queue {
    int* items;
    int front;
    int rear;
    int size;
} Queue;

// Function to create a node
Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Function to add an edge
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (because it's undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to create a queue
Queue* createQueue(int size) {
    Queue* queue = malloc(sizeof(Queue));
    queue->items = malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Enqueue function
void enqueue(Queue* queue, int value) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }

    if (queue->front == -1)
        queue->front = 0;

    queue->rear++;
    queue->items[queue->rear] = value;
}

// Dequeue function
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    int item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    return item;
}

// BFS function
void bfs(Graph* graph, int startVertex) {
    Queue* queue = createQueue(graph->numVertices);

    graph->visited[startVertex] = true;
    enqueue(queue, startVertex);

    printf("BFS traversal: ");

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(queue->items);
    free(queue);
}

// Main function
int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    bfs(graph, 0);

    // Free allocated memory
    for (int i = 0; i < vertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    free(graph->adjLists);
    free(graph->visited);
    free(graph);

    return 0;
}
