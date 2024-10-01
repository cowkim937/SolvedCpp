#include <bits/stdc++.h>

using namespace std;

int main(void){
    string str;
    int ans = 0;
    int n, m;
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> str;

    for(int i = 0, l = 0; i <= m; i++){
        if(str[i] == 'O')
            continue;
        else{
            while (str[i + 1] == 'O' && str[i + 2] == 'I')
            {
                l++;
                if (l == n)
                {
                    l--; // 중복 카운트를 막기 위해 -1 해준다.
                    ans++;
                }
                i += 2; // O를 건너 뛴다.
            }
            l = 0;
        }
    }
    
    cout << ans;
}
    