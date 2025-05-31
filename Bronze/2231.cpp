#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, i;
    cin >> n;
    for(i=1; i<=n; i++){
        s = i;
        for(int j=i; j>0; j/=10)
            s += j%10;
        if(s == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}