#include<iostream>
#include<cstdio>

using namespace std;

int t, n;
long long int per[101];

int main(void){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

        per[1] = 1;
        per[2] = 1;
        per[3] = 1;
        per[4] = 2;
        per[5] = 2;
        for(int i=6; i<=n; i++)
            per[i] = per[i - 1] + per[i - 5];

        printf("%lld\n", per[n]);
    }
}