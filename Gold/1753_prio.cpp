#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string>

#define INF -1

using namespace std;

int main()
{   
    int N, E, S;
    vector<vector<array<int,2>>> adj_list;
    vector<int> dist;

    scanf("%d %d\n%d", &N, &E, &S);

    for(int i=0; i<N; i++){
        adj_list.push_back(vector<array<int,2>>());
        dist.push_back(-1);
    }
    
    for(int i=1, v1, v2, w; i <= E; i++){
        scanf("%d %d %d", &v1, &v2, &w);
        adj_list[v1 - 1].push_back({v2 - 1, w});
    }

    priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>> pq;
    pq.push({0, S - 1});

    while (!pq.empty()) {
        int cur_dist = pq.top()[0];
        int cur_node = pq.top()[1];
        pq.pop();

        if (dist[cur_node] != -1) continue;
        dist[cur_node] = cur_dist;
        
        for (auto &adj_node : adj_list[cur_node]) {
            if (dist[adj_node[0]] != -1) continue;
            pq.push({cur_dist + adj_node[1], adj_node[0]});
        }
    }

    // Print result
    for (int i=0; i<N; i++) {
        //string ans = dist[i] == -1 ? "INF" : to_string(dist[i]); 
        cout << dist[i] << endl;
    }
    return 0;
}