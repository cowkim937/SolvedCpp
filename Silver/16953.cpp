#include<iostream>
#include<queue>

#define ll long long
#define INF 987654321

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, m, ans = INF;
    queue< pair<ll, ll> > q;

    cin >> n >> m;

    q.push(make_pair(n, 0));
    while(!q.empty()){
        pair<ll, ll> t = q.front(); q.pop();

        //cout << t.first << " " << t.second << '\n';

        if(t.first > m) continue;

        if(t.first * 2 == m)
            ans = min(ans, t.second + 1);
        else
            q.push(make_pair(t.first * 2, t.second + 1));

        if((t.first * 10) + 1 == m)
            ans = min(ans, t.second + 1);
        else
            q.push(make_pair((t.first * 10) + 1, t.second + 1));
    }
    
    if(ans == INF)
        cout << -1;
    else
        cout << ans + 1;
    
    return 0;
}
