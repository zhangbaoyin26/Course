//
// Created by 张宝印 on 2022/11/6.
//

#include<cstdio>
#include<malloc.h>

const unsigned int INF = 32767;
const int MAXV = 100;
short visited[MAXV];
typedef char InfoType;

typedef struct ANode {
    int adjvex;
    struct ANode *nextarc;
    int weight;
} ArcNode;

typedef struct Vnode {
    InfoType info;
    int count;
    ArcNode *firstarc;
} VNode;

typedef struct {
    VNode adjlist[MAXV];
    int n, e;
} AdjGraph;


void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e) {
    int i, j;
    ArcNode *p;
    G = (AdjGraph *) malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++)
        G->adjlist[i].firstarc = nullptr;
    for (i = 0; i < n; i++)
        for (j = n - 1; j >= 0; j--)
            if (A[i][j] != 0 && A[i][j] != INF) {
                p = (ArcNode *) malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
    G->n = n;
    G->e = n;
}

void DFS(AdjGraph *G, int v)     //递归深度优先遍历
{
    ArcNode *p;
    printf("%3d", v);
    visited[v] = 1;
    p = G->adjlist[v].firstarc;
    while (p != nullptr) {
        if (visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

void BFS(AdjGraph *G, int v) {
    ArcNode *p;
    int queue[MAXV], front = 0, rear = 0;
    int visited[MAXV];
    int w, i;
    for (i = 0; i < G->n; i++) visited[i] = 0;
    printf("%3d", v);
    visited[v] = 1;
    rear = (rear + 1) % MAXV;
    queue[rear] = v;
    while (front != rear) {
        front = (front + 1) % MAXV;
        w = queue[front];
        p = G->adjlist[w].firstarc;
        while (p != nullptr) {
            if (visited[p->adjvex] == 0) {
                printf("%3d", p->adjvex);
                visited[p->adjvex] = 1;
                rear = (rear + 1) % MAXV;
                queue[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
    printf("\n");
}

int main() {
    AdjGraph *G;
    int A[MAXV][MAXV] = {
            {0,   5,   INF, 7,   INF, INF},
            {INF, 0,   4,   INF, INF, INF},
            {8,   INF, 0,   INF, INF, 9},
            {INF, INF, 5,   0,   INF, 6},
            {INF, INF, INF, 5,   0,   INF},
            {3,   INF, INF, INF, 1,   0}};
    int n = 6, e = 10;
    CreateAdj(G, A, n, e);
    printf("从顶点0开始的DFS:\n");
    DFS(G, 0);
    printf("\n");
    printf("从顶点0开始的BFS:\n");
    BFS(G, 0);
}