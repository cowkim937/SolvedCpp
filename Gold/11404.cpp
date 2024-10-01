#include<iostream>
#include<cstdio>
#include<algorithm>

#define INF 1e9

using namespace std;

int n, m;
int** arr;

int main(void){
    scanf("%d", &n);
    scanf("%d", &m);

    arr = (int**)malloc(sizeof(int*) * n + sizeof(int));
    for(int i=0; i<n; i++)
        arr[i] = (int*)malloc(sizeof(int) * n + sizeof(int));

    for(int i=0, t1, t2, w; i<m; i++){
        scanf("%d %d %d", &t1, &t2, &w);
        arr[t1 - 1][t2 - 1] = w;
        arr[t1 - 1][t1 - 1] = 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0 && i != j)
                arr[i][j] = INF;
        }
    }

    for(int mid = 0; mid < n; mid++){
        for(int start = 0; start < n; start++){
            for(int end = 0; end < n; end++){
                if(arr[start][mid] == INF || arr[mid][end] == INF) continue;
                arr[start][end] = min(arr[start][end], arr[start][mid] + arr[mid][end]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == INF) printf("0 ");
            else printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}