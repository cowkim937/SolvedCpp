#include<iostream>
#include<queue>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    string str;
    queue<int> q;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> str;
        // push X: 정수 X를 큐에 넣는 연산이다.
        if(str.compare("push") == 0){
            int t;
            cin >> t;
            q.push(t);
        }
        // pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.
        //      만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else if(str.compare("pop") == 0){
            if(q.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        // size: 큐에 들어있는 정수의 개수를 출력한다.
        else if(str.compare("size") == 0){
            cout << q.size() << '\n';
        }
        // empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
        else if(str.compare("empty") == 0){
            if(q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        // front: 큐의 가장 앞에 있는 정수를 출력한다.
        //        만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else if(str.compare("front") == 0){
            if(q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
        }
        // back: 큐의 가장 뒤에 있는 정수를 출력한다.
        //       만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else if(str.compare("back") == 0){
            if(q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        }
    }
    return 0;
}