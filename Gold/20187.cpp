#include<iostream>

using namespace std;

vector<char> cmd;
int p[128][128];

int drawMap(int idx, int sx, int sy, int ex, int ey){
    switch (cmd[idx])
    {
        case 'R':
            drawMap(idx + 1, (sx + ex)/2, sy, ex, ey);
            break;

        case 'L':
            drawMap(idx + 1, (sx + ex)/2, sy, (ex - sx)/2, ey);
            break;

        case 'D':
            drawMap(idx + 1, x1, x2, y1, y2);
            break;
        
        default:
            drawMap(idx + 1, x1, x2, y1, y2);
            break;
    } 
}

int convert(int dir, int punch){
    if(dir){ // D, U 위아래
        switch(punch){
            case 0: return 2;
            case 1: return 3;
            case 2: return 0;
            case 3: return 1; 
        }
    }
    else{ // R, L 좌우
        switch(punch){
            case 0: return 1;
            case 1: return 0;
            case 2: return 3;
            case 3: return 2; 
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    char t;
    int k, i, stk = 2;
    char lasted[2];
    cin >> k;

    int w = pow(2,k);

    for(int j=0; j<w; j++){
        cin >> t;
        cmd.push_back(t);
    }

    cin >> i;
    p[w][w] = i;
    drawMap(0, 1, 1<<k, 1, 1<<k);
    
}