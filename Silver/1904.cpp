#include<bits/stdc++.h>

using namespace std;

int n;
int til[1000001];

int tile(int n){
    if(n == 1 || n == 2)
        return n;
    if(til[n] != 0)
        return til[n];
    else
        til[n] = (tile(n - 1) + tile(n - 2))%15746;
    return til[n];
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cout << tile(n);
    return 0;
}