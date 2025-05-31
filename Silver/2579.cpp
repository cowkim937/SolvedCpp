#include<iostream>
#include<algorithm>

using namespace std;    

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    int dp[n+1];
    int s[n+1];

    for(int i=1; i<=n; i++)
        cin >> s[i];

    dp[0] = 0;
    dp[1] = s[1];
    dp[2] = s[1] + s[2];
    for(int i=3; i<=n; i++)
        dp[i] = max(s[i] + s[i - 1] + dp[i - 3], s[i] + dp[i - 2]);
    
    cout << dp[n] << '\n';
    return 0;
}