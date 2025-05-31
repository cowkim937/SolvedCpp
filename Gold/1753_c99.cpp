#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct MinHeap {
    int *nodes;
    int *distances;
    int size;
} MinHeap;

typedef struct Edge {
    int node;
    struct MinHeap *next;
} Edge;

typedef struct Graph {
    Edge **edges;
    int *distance;
    int n;
} Graph;

void Graph_init(Graph *this, int n){
    this->n = n;
    this->edges = (Edge**)malloc(sizeof(Edge*) * (n + 1));
    this->distance = (int*)malloc(sizeof(int) * (n + 1));
    memset(this->edges, 0, sizeof(Edge*) * (n + 1));
    memset(this->distance, 0, sizeof(int) * (n + 1));
}

void MinHeap_init(MinHeap *this, int n){
}

void MinHeap_push(MinHeap *this, int node, int distance){
    int i = this->size++;
    while(i > 0){
        int parent = (i - 1) / 2;
        if(this->distances[parent] <= distance) break;
        this->nodes[i] = this->nodes[parent];
        this->distances[i] = this->distances[parent];
        i = parent;
    }
    this->nodes[i] = node;
    this->distances[i] = distance;
}

int DijicStra_pop(MinHeap *this){
    int node = this->nodes[0];
    int distance = this->distances[0];
    this->size--;
    int i = 0;
    while(i * 2 + 1 < this->size){
        int a = i * 2 + 1;
        int b = i * 2 + 2;
        int min = b < this->size && this->distances[b] < this->distances[a] ? b : a;
        if(this->distances[min] >= this->distances[this->size]) break;
        this->nodes[i] = this->nodes[min];
        this->distances[i] = this->distances[min];
        i = min;
    }
    this->nodes[i] = this->nodes[this->size];
    this->distances[i] = this->distances[this->size];
    return node;
}

int main(void){
    int n, m, start;
    scanf("%d %d\n%d", &n, &m, &start);
    Graph g;
    Graph_init(&g, n);
    while(m--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        Edge *edge = (Edge*)malloc(sizeof(Edge));
        edge->node = b;
        edge->next = g.edges[a];
        g.edges[a] = edge;
    }
    
    Dijickstra(&g, start);
    for (int i = 1; i <= n; i++) {
        if (g.distance[i] == 0) {
            printf("INF\n");
        } else {
            printf("%d\n", g.distance[i]);
        }
    }
    return 0;
}