#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m=0;
    cin >> n;

    int t[n+2], p[n+2], dp[n+2];

    dp[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> t[i] >> p[i];
        dp[i] = 0;
    }
    dp[n+1] = 0;
    
    for(int i=1; i<=n; i++){
        if(dp[i] < dp[i - 1])
            dp[i] = dp[i - 1];
        else
            dp[i] = max(dp[i], dp[i - 1]);
            
        if(dp[i + t[i]] == 0)
            dp[i + t[i]] = dp[i] + p[i];
        else
            dp[i + t[i]] = max(dp[i] + p[i], dp[i + t[i]]); 
    }
    
    cout << max(dp[n], dp[n+1]) << '\n';

    return 0;
}