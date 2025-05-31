#include<iostream>
#include<string>

using namespace std;

int main(void){
    int n, cnt = 0;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        bool alpha[26] = {false, };
        bool group = true;
        for(int i = 0; i < s.size(); i++){
            if (alpha[s[i] - 'a']){
                group = false;
                break;
            }
            if (s[i] != s[i+1]){
                alpha[s[i] - 'a'] = true;
            }
        }
        if(group) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}