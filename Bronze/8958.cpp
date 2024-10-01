#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    string str;

    cin >> t;
    for(int i=0, cnt, sum;i<t;i++){
        cin >> str;
        sum = 0;
        cnt = 0;
        for(auto &x: str){
            if(x == 'O'){
                cnt++;
                sum += cnt;
            }
            else{
                cnt = 0;
            }
        }
        cout << sum << endl;
    }
    return 0;
}