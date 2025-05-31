#include<iostream>
#include<vector>
#include<queue>

#define PX 0
#define PY 1
#define PZ 2
#define GEN 3

using namespace std;

int dir[4][2] = {
    {1,  0},
    {0,  1},
    {-1, 0},
    {0, -1},
};

int tom[1001][1001];
bool v[1001][1001];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    queue< array<int, 3> > q;
    int n, m, h;
    int ans = 0;
    cin >> n >> m >> h;

    for(int y=0; y<m; y++){
        for(int x=0; x<n; x++){
            int in;
            cin >> in;
            tom[x][y] = in;
            if(in  == 1){
                array<int, 3> temp = {x, y, 0};
                q.push( temp );
            }
        }
    }

    while(!q.empty()){
        array<int, 3> temp = q.front(); q.pop();
        //cout << "target: " << temp[PX] << " "<< temp[PY] << " "<< temp[PZ] << " " << temp[GEN] << "\n";
        if(v[temp[PX]][temp[PY]]) continue;
        v[temp[PX]][temp[PY]] = true;

        for(int z=0; z<h; z++){
            for(int y=0; y<m; y++){
                for(int x=0; x<n; x++){
                    cout << tom[x][y] << " ";
                }
                cout << "\n";
            }
        }
        // cout << temp[GEN] << "\n";
        cout << "\n";

        ans = ans > temp[GEN] ? ans : temp[GEN];

        for(int i = 0; i<4; i++){
            // skip over limit size
            if(temp[PX] + dir[i][0] < 0 || temp[PX] + dir[i][0] > n) continue;
            if(temp[PY] + dir[i][1] < 0 || temp[PY] + dir[i][1] > m) continue;

            if(tom[temp[PX] + dir[i][0]][temp[PY] + dir[i][1]] == 0 &&
                !v[temp[PX] + dir[i][0]][temp[PY] + dir[i][1]]){
                tom[temp[PX] + dir[i][0]][temp[PY] + dir[i][1]] = 1;                
                array<int, 3> input =
                    {temp[PX] + dir[i][0],
                    temp[PY] + dir[i][1],
                    temp[GEN] + 1};
                q.push( input );
            }
        }
    }

    // final check
    bool detect_zero = false;
    for(int y=0; y<m && !detect_zero; y++)
        for(int x=0; x<n && !detect_zero; x++)
            if(tom[x][y] == 0)
                detect_zero = true;

    ans = detect_zero ? -1 : ans;
    cout << ans << "\n";
    return 0;
}