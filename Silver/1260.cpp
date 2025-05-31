#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector <vector<int>> v, int s, int e){
    queue<int> q;
    bool *visit = new bool[e+1];

    q.push(s);
    while(!q.empty()){
        int c = q.front();
        q.pop();

        if(!visit[c]){
            cout << c << " ";
            visit[c] = true;
        }else{
            continue;
        }
        
        for(int i=1; i<=v[c].size(); i++){
            cout << "Test: " << i << "\n";
            q.push(i);
        }
    }
}

void dfs(vector <vector<int>> v, bool visit[], int s, int e){

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m, s;
    int i, j, k;

    cin >> n >> m >> s;
    vector <vector<int>> v(n+1, vector<int>(m+1, 0));
    
    while(i--){
        cin >> j >> k;
        v[j].push_back(k);
    }

    bfs(v, s, m);

    return 0; 
}