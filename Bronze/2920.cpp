#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string strs[3] = {"ascending", "descending", "mixed"};
    int sod[9] = {0}, s = -1;

    for(int i=0; i<8; i++)
        cin >> sod[i];

    for(int i=1; i<8; i++)
        if((sod[i-1] - sod[i]) == -1 && s != 1 && s != 2) s = 0;
        else if((sod[i-1] - sod[i]) == 1 && s != 0 && s != 2) s = 1;
        else s = 2;

    cout << strs[s];

    return 0;
}