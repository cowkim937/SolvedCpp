#include<iostream>
#include<vector>

using namespace std;

class DisjointSet {
public:
    explicit DisjointSet( int numElements );
    int find( int x ) const;
    int find( int x );
    void unionSets( int root1, int root2 );
private:
    vector<int> s;
};

DisjointSet::DisjointSet( int numElements ) : s( numElements, -1 ) {}

int DisjointSet::find( int x ) const {
    if( s[x] < 0 )
        return x;
    else
        return find( s[x] );
}

int DisjointSet::find( int x ) {
    if( s[x] < 0 )
        return x;
    else
        return s[x] = find( s[x] );
}

void DisjointSet::unionSets( int root1, int root2 ) {
    if( s[root2] < s[root1] ) {
        s[root1] = root2;
    } else {
        if( s[root1] == s[root2] )
            --s[root1];
        s[root2] = root1;
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, i, x, y;
    bool ans = false;
    cin >> n >> m;
    DisjointSet ds(n);
    i = 0;
    while(i++ < n){
        x = n;
        while(x--){
            cin >> y;
            ds.unionSets(x, y);
        }
    }
    x = n;
    while(x--){
        cin >> y;
        if (ds.find(y) == ds.find(m))
            ans = true;
        else
            ans = false;
    }
    
    if(ans)
        cout << "YES";
    else
        cout << "NO";
}