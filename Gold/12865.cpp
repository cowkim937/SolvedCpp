#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;
    int w[n+1], v[n+1];
    int dp[n+1][k+1];
    for(int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j < w[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}