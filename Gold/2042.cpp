#include <bits/stdc++.h>

using namespace std;

const int MAX_TABLE =  4000004;

int n, m, k;
long long arr[MAX_TABLE];
long long segtree[2 * MAX_TABLE];

void init(){
    for (int i = 0; i < n; i++){
        segtree[n + i] = arr[i];
    }
    for (int i = n - 1; i >= 1; i--){
        // 부모 = 왼쪽 자식 구간 합 + 오른쪽 자식 구간 합.
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}
void update(int idx, int x){
    segtree[idx + n] = x;
    int i = ((idx + n) >> 1);
    for (; i >= 1; i>>=1){
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}
// 구간 [l,r) 까지의 합 return
long long find_x(int l, int r){
    l += n;
    r += n;
    long long result = 0;
    while(l!=r){
        if(l&1)
            result += segtree[l++];
        if(r&1)
            result += segtree[--r];
        l >>= 1;
        r >>= 1;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    init();

    while(m != 0 || k != 0){
        int temp;
        cin >> temp;
        
        if(temp == 1){
            int ch, va;
            cin >> ch >> va;
            update(ch - 1, va);
            m--;
        }
        else if(temp == 2){
            int l, r;
            cin >> l >> r;
            printf("%lld\n", find_x(l - 1, r));
            k--;
        }
    }

    return 0;
}