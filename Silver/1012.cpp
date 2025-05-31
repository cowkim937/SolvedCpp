#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t;
    int dir[4][2] = {
        {1,  0},    // 오른쪽
        {0,  1},    // 위쪽
        {-1, 0},    // 왼쪽
        {0, -1}     // 아래쪽
    };

    cin >> t;
    
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;

        vector< pair<int, int> > p;
        int bug = 0;
        bool visit[51][51] = {0};
        int beachu[51][51] = {0};

        // 배추 위치 및 bfs 초기화
        while(k--){
            int x, y;
            cin >> x >> y;
            beachu[x][y] = 1;
            pair<int, int> w = make_pair(x, y);
            p.push_back(w);
        }

        for(vector< pair<int, int> >::iterator iter = p.begin(); iter != p.end(); iter++){
            queue< pair<int, int> > q;
            int excute = 0;   
            q.push(*iter);
            while(!q.empty()){
                pair<int, int> w = q.front(); q.pop();
                if(visit[w.first][w.second]) continue;
                excute++;
                visit[w.first][w.second] = true;
                for(int i = 0; i<4; i++){
                    // skip limited size
                    if(w.first + dir[i][0] < 0 && w.first + dir[i][0] > n) continue;
                    if(w.second + dir[i][1] < 0 && w.second + dir[i][1] > m) continue;

                    if(beachu[w.first + dir[i][0]][w.second + dir[i][1]] == 1 &&
                    !visit[w.first + dir[i][0]][w.second + dir[i][1]]){
                        q.push(make_pair(w.first + dir[i][0], w.second + dir[i][1]));
                    }
                }
            }
            if(excute > 0)
                bug++;
        }

        cout << bug << "\n";
    }
}