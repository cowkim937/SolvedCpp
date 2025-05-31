#include<bits/stdc++.h>

#define PX 0
#define PY 1
#define PZ 2
#define GEN 3

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int dir[6][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
        {-1, 0, 0},
        {0, -1, 0},
        {0, 0, -1},
    };

    queue< array<int, 4> > q;
    int tom[101][101][101] = {0};
    bool v[101][101][101] = {0};
    int n, m, h;
    int ans = 0;
    cin >> n >> m >> h;

    for(int z=0; z<h; z++){
        for(int y=0; y<m; y++){
            for(int x=0; x<n; x++){
                int in;
                cin >> in;
                tom[x][y][z] = in;
                if(in  == 1){
                    array<int, 4> temp = {x, y, z, 0};
                    q.push( temp );
                }
            }
        }
    }

    while(!q.empty()){
        array<int, 4> temp = q.front(); q.pop();
        //cout << "target: " << temp[PX] << " "<< temp[PY] << " "<< temp[PZ] << " " << temp[GEN] << "\n";
        if(v[temp[PX]][temp[PY]][temp[PZ]]) continue;
        v[temp[PX]][temp[PY]][temp[PZ]] = true;

        for(int z=0; z<h; z++){
            for(int y=0; y<m; y++){
                for(int x=0; x<n; x++){
                    cout << tom[x][y][z] << " ";
                }
                cout << "\n";
            }
        }
        cout << temp[GEN] << "\n";
        cout << "\n";

        ans = ans > temp[GEN] ? ans : temp[GEN];

        for(int i = 0; i<6; i++){
            // skip over limit size
            if(temp[PX] + dir[i][0] < 0 || temp[PX] + dir[i][0] > n) continue;
            if(temp[PY] + dir[i][1] < 0 || temp[PY] + dir[i][1] > m) continue;
            if(temp[PZ] + dir[i][2] < 0 || temp[PZ] + dir[i][2] > h) continue;

            if(tom[temp[PX] + dir[i][0]][temp[PY] + dir[i][1]][temp[PZ] + dir[i][2]] == 0 &&
                !v[temp[PX] + dir[i][0]][temp[PY] + dir[i][1]][temp[PZ] + dir[i][2]]){
                tom[temp[PX] + dir[i][0]][temp[PY] + dir[i][1]][temp[PZ] + dir[i][2]] = 1;                
                array<int, 4> input =
                    {temp[PX] + dir[i][0],
                    temp[PY] + dir[i][1],
                    temp[PZ] + dir[i][2],
                    temp[GEN] + 1};
                q.push( input );
            }
        }
    }

    // final check
    bool detect_zero = false;
    for(int z=0; z<h && !detect_zero; z++)
        for(int y=0; y<m && !detect_zero; y++)
            for(int x=0; x<n && !detect_zero; x++)
                if(tom[x][y][z] == 0)
                    detect_zero = true;

    ans = detect_zero ? -1 : ans;
    cout << ans << "\n";
    return 0;
}