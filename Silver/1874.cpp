#include<bits/stdc++.h>

#define INF 987654321

using namespace std;

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);

    int n, t;
    stack<int> s, tmp;
    s.push(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t;
        while(t < s.top()){
            int temp = s.top();
            s.pop();
            cout << "-" << "\n";
            tmp.push(temp);
        }
        tmp.push(t);
        while(!tmp.empty()){
            int temp = tmp.top();
            tmp.pop();
            s.push(temp);
            cout << "+" << "\n";
        }
    }

    return 0;
}
