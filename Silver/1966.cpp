#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, n, m, ans;
    queue<int> q;

    cin >> t;

    for(int tc=0, temp; tc<t; tc++){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> temp;
            q.push(temp);
        }
        ans = 0;
        while(!q.empty()){
            int mq = q.front();
            bool c = false;
            for(int j = 1; j < q.size(); j++)
                if(mq > q[j]) c = true; 
        }
    }

}