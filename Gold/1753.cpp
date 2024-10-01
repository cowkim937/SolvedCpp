#include<iostream>
#include<cstdio>

#define INF 987654321

using namespace std;

int g[201][201] = {INF};
int v, e, s;

bool vis[201] = {false};
int dist[201] = {0};
int min_node;

int getSmall(){
    int min = INF;
    int minpos = 0;
    for(int i = 1; i <= v; i++){
        if(dist[i] < min && !vis[i]){
            min = dist[i];
            minpos = i;
        }
    }
    return minpos;
}

void dijkstra(int start){
    for(int i = 1; i <= v; i++){
        dist[i] = g[start][i];
    }

    vis[start] = true;
    for(int r = 1; r < v; r++){
        min_node = getSmall();
        vis[min_node] = true;
        for(int i = 1; i <= v; i++){
            if(!vis[i])
                if(dist[min_node] + g[min_node][i] < dist[i])
                    dist[i] = dist[min_node] + g[min_node][i];
        }
    }
}

int main(void){
    scanf("%d %d", &v, &e);
    scanf("%d", &s);

    for(int i=0, t1, t2, w; i<e; i++){
        scanf("%d %d %d", &t1, &t2, &w);
        g[t1][t2] = w;
        g[t1][t1] = 0;
    }
    dijkstra(s);
    printf("%d", min_node);
}