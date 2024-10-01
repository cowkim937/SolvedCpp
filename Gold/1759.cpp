#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, c;
char alpha[16];
char vowel[] = {'a', 'e', 'i', 'o', 'u'};
vector<char> choose;

void combi(int idx, int level){
    if(level == n){
        c = 0;
        for(auto &u : choose)
            for(auto &l : vowel)
                if(u == l)
                    c++;
        if(c > 0){
            for(auto &u : choose)
                cout << u;
            cout << "\n";
        }
        return;
    }

    for(int i = idx; i<m; i++){
        choose.push_back(alpha[i]);
        combi(i + 1, level + 1);
        choose.pop_back();
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for(int i=0, t; i<m; i++)
        cin >> alpha[i];
    sort(alpha, alpha + m);
    combi(0, 0);
}
