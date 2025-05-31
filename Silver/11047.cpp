#include<bits/stdc++.h>

using namespace std;

int n, m, i, c = 0;
int mon[11];

int main(void){
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
        scanf("%d", &mon[i]);
    
    for(i-- ; i >= 0 && m > 0; c += int(m/mon[i]), m %= mon[i], i--);

    printf("%d", c);
}