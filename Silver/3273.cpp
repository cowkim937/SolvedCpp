#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x, c = 0;
    int m[100001];


    cin >> n;
    for(int i=0; i<n; i++) cin >> m[i];
    cin >> x;

    int left = 0;
    int right = n-1;

    sort(m, m + n);

    while (left < right) {
        int temp = m[left] + m[right];
        if (temp < x) {
            left++;
        } else if (temp > x) {
            right--;
        } else {
            left++; right--;
            c++;
        }
    }
        
    cout << c;
    return 0;
}