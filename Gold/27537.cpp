#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<ll,ll>> seg(N);
    for(int i = 0; i < N; i++){
        ll X, E;
        cin >> X >> E;
        seg[i].first  = X - E;  // L_i
        seg[i].second = X + E;  // R_i
    }

    // L 오름차순, L 같으면 R 내림차순 정렬
    sort(seg.begin(), seg.end(), [](auto &a, auto &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    ll maxR = LLONG_MIN;
    int answer = 0;
    for(auto &s : seg){
        ll R = s.second;
        // 이전에 본 구간 중 R이 더 크거나 같으면
        // 이 구간은 이미 어떤 큰 구간에 포함되므로 skip
        if(R <= maxR) {
            continue;
        }
        // 그렇지 않으면 이 구간은 새로운 “최상위 구간” → 기증 필요
        answer++;
        maxR = R;
    }

    cout << answer << "\n";
    return 0;
}
