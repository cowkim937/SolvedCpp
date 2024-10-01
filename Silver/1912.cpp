#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m[100001], dp[100001] = {0}, maxv = 0;

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> m[i];

    dp[0] = m[0];
    maxv = dp[0];
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i - 1] + m[i], m[i]);
        maxv = max(maxv, dp[i]);
    }

    cout << maxv;
    return 0;
}