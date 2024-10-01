#include<iostream>
#include<cstdio>

using namespace std;

int fibomem[41];
int ans1, ans2;
int n;

int fibo1(int f){
    if (f == 1 || f == 2){
        ans1++;
        return 1;
    }
    else return (fibo1(f - 1) + fibo1(f - 2));
}

int fibo2(int f){
    fibomem[1] = fibomem[2] = 1;
    for(int i = 3; i <= f; i++, ans2++)
        fibomem[i] = fibomem[i - 1] + fibomem[i - 2];
    return fibomem[f];
}

int main(void){
    scanf("%d", &n);
    ans1 = 0;
    ans2 = 0;
    fibo1(n);
    fibo2(n);
    printf("%d %d", ans1, ans2);
}