#include<bits/stdc++.h>

#define R 0
#define G 1
#define B 2

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false);

    int n, m[1001][3], vis[1001][3] = {0}, dp[1001];
    /*
    1번 집의 색은 2번 집의 색과 같지 않아야 한다.
    N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
    i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
    */

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> m[i][R] >> m[i][G] >> m[i][B];

    for(int i=0; i<n; i++){
        
    }

    

    return 0;
}