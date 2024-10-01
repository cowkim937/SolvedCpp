#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, mav = 0;
    short m[10001] = {0}, t;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t;
        mav = mav < t ? t : mav;
        m[t]++;
    }

    for(int i=1; i<mav; i++)
        while(m[i]--) cout << i << "\n";
    
    return 0;
}