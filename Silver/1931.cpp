#include<iostream>
#include<cstdio>

#define INF 1e9

using namespace std;

int main(void){
    int n;
    vector<pair<int, int>> rooms;

    scanf("%d", &n);

    for(int i=0, t1, t2; i<n; i++){
        scanf("%d %d", &t1, &t2);
        rooms.push(make_pair(t1, t2));
    }

    
}