#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

#define INF 1e9

using namespace std;

int main(void){
    int n,m;
    vector< array<int, 3> > ed;
    vector<int> dist;

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        dist.push_back(INF);
    
    for(int i=0, t1, t2, w; i<m; i++){
        scanf("%d %d %d", &t1, &t2, &w);
        ed.push_back( { t1 - 1, t2 - 1, w } );
    }

    dist[0] = 0;
    for(int i=1; i<n; i++){
        for(auto [s, e, w] : ed){
            if(dist[s] == INF) continue;
            dist[e] = min(dist[e], dist[s] + w);
        }
    }

    for(int i=0; i<n; i++){
        printf("%d\n", dist[i]);
    }
}