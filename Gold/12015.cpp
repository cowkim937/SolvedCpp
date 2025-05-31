#include<iostream>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    vector<int> v;

    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        
        if(i != 0 && t <= v.back()){
            *(lower_bound(v.begin(), v.end(), t)) = t;
            continue;
        }
        v.push_back(t);
    }

    cout << v.size();
}