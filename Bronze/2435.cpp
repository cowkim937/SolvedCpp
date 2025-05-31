#include<cstdio>

#define INF -987654321

int main(void){
    int n, k, ans = INF;

    scanf("%d %d", &n, &k);
    int day[n + 1];
    int add[n + 1];
    day[0] = 0;
    add[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &day[i]);
        add[i] = add[i - 1] + day[i];
    }

    for(int i=0; i<=n-k; i++){
        int temp = add[i+k] - add[i];
        // printf("%d %d %d\n", add[i+k] , add[i], temp);
        if(temp > ans) ans = temp;
    }

    printf("%d", ans);
    return 0;
}   