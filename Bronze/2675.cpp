#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string str;
    int t;

    cin >> t;
    for(int i=0, tmp; i<t; i++){
        cin >> tmp >> str;
        for(auto &x: str){
            for(int j=0; j<tmp; j++){
                cout << x;
            }
        }
        cout << "\n";
    }
    
    return 0;
}