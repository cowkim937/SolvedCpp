#include<bits/stdc++.h>

#define MAX 1000001

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, maxv = 0;
    int m[MAX], dp[MAX];

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> m[i];

    for(int i=1; i<=n; i++){
        dp[i] = m[i];
        for(int j=1; j<i; j++){
            if(m[j] < m[i] && dp[i] < dp[j] + m[i]){
                dp[i] = dp[j] + m[i];
            }
            maxv = max(maxv, dp[i]);
        }
    }

    maxv = max(maxv, dp[1]);
    cout << maxv;
}