#include<iostream>
#include<cstdio>

using namespace std;

int m[101][101][101];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;

    if(m[a][b][c] != 0)
        return m[a][b][c];

    if(a > 20 || b > 20 || c > 20)
        m[a][b][c] = w(20, 20, 20);
    else if(a < b && b < c)
        m[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else
        m[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);

    return m[a][b][c];
}

int main(void){
    while(true){
        int a,b,c,ans;
        scanf("%d %d %d", &a, &b, &c);
        
        ans = 0;
        if(a == -1 && b == -1 && c == -1)
            break;

        ans = w(a, b, c);

        printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
    }
}