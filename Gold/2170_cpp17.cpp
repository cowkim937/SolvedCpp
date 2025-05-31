#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    return a.first < b.first;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    pair<int, int> arr[1000001];

    for(int i=0; i<n; i++)
        cin >> arr[i].first >> arr[i].second;
        
    sort(arr, arr+n, cmp);

    int start = arr[0].first;
    int end = arr[0].second;
    int ans = 0;
    
    for(int i=1; i<n; i++){
        if(arr[i].first <= end){
            end = max(end, arr[i].second);
        }
        else{
            ans += end - start;
            start = arr[i].first;
            end = arr[i].second;
        }
    }
    ans += end - start;
    cout << ans;
    return 0;
}