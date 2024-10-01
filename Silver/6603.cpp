#include<iostream>
#include<vector>

using namespace std;

int n, l[50];
vector<int> choose;

void combi(int idx, int level){
    if(level == 6){
        for(auto &u : choose){
            cout << u << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = idx; i<n; i++){
        choose.push_back(l[idx]);
        combi(i+1, level+1);
        choose.pop_back();
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    while(true){
        cin >> n;
        if(n != 0){
            for(int i=0; i<n; i++)
                cin >> l[i];
            combi(0, 0);
        }
    }
}
