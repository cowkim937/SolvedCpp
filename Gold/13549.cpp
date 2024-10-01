#include<cstdio>
#include<queue>

#define MAXSIZE 100000

using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;

int main(void){
    int n, m;
    bool visit[MAXSIZE + 6];
    scanf("%d %d", &n, &m);
    
    pq.push(make_pair(0, n));

    while(!pq.empty()){
		int time = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		visit[x] = 1;
		
		if(x == m){
            printf("%d", time);
			break;
		}

		if(x-1 >= 0 && !visit[x-1])
			pq.push(make_pair(time+1,x-1));
		if(x+1 <= MAXSIZE && !visit[x+1])
			pq.push(make_pair(time+1,x+1));
		if(x*2 <= MAXSIZE && !visit[x*2])
			pq.push(make_pair(time,x*2));
    }
    return 0;
}