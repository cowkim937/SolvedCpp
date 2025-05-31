#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, t;
    int ans=0;
    vector<int> v;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    for(int i=1; i<=n; i++){
        v[i] += v[i-1];
        ans += v[i-1];
    }

    cout << ans;

    return 0;
}