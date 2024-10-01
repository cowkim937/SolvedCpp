#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int cnt[42] = {0}, ans=0;
    for(int i=0, t; i<10; i++){
        cin >> t;
        cnt[t%42] = 1;
    }

    for(auto &x: cnt) ans += x;

    printf("%d", ans);

    return 0;
}