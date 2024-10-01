#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x, c = 2000000001, a, b;
    int m[100001];

    cin >> n;
    for(int i=0; i<n; i++) cin >> m[i];

    int left = 0;
    int right = n-1;

    sort(m, m + n);

    while (left < right) {
        int temp = m[left] + m[right];
       
        if (c > abs(temp)) {
            c = abs(temp);
            a = m[left];
            b = m[right]; 
            if (temp == 0)
                break;
        }

        if (temp < 0) 
            left++;
        else 
            right--;
    }
    
    cout << a << " " << b;
    return 0;
}