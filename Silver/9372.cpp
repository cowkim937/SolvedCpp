#include<iostream>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t, n, m;
    
    cin >> t;
    while(t--){
        int a, b;
        cin >> n >> m;
        for(int i=0; i < m ; i++){
            cin >> a >> b;
        }
        cout << n-1 <<endl; //연결된 그래프에서 엣지 수는 노드수 -1일때 가장 작다.
    }

    return 0;
}