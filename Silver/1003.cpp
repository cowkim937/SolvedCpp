#include<iostream>
#include<cstring>

using namespace std;

using ll = long long;

ll dp[51] = {0, 1, };

int fibonacci(int n) {
    if(n == 1 || n == 0)
        return dp[n];
    else if(dp[n] == 0)
        dp[n] = fibonacci(n-1) + fibonacci(n-2);
    return dp[n];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        if(n == 0)
            cout << "1 0\n";
        else
            cout << fibonacci(n-1) << " " << fibonacci(n) << "\n";
    }

    return 0;
}