#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int v, e, ans=0;
    vector< pair < int, pair<int, int> > > g;
    
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pair<int, pair<int, int> >  p = make_pair(c, make_pair(a, b));
        g.push_back(p);
    }
    sort(g.begin(), g.end());
    vector<int> parent(v + 1);
    for(int i=0; i<=v; i++) parent[i] = i;

    cout << g.size();
    return 0;
}