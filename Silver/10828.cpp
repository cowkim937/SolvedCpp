#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    stack<int> stk;
    string cmd;
    int n, x;
    cin >> n;

    while(n--){
        cin >> cmd;
        if(cmd == "push"){
            cin >> x;
            stk.push(x);
        }
        else if(cmd == "pop"){
            if(!stk.empty()){
                cout << stk.top() << "\n";
                stk.pop();
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(cmd == "size"){
            cout << stk.size() << '\n';
        }
        else if(cmd == "empty"){
            cout << stk.empty() << '\n';
        }
        else if(cmd == "top"){
            if(!stk.empty())
                cout << stk.top() << '\n';
            else
                cout << -1 << "\n";
        }
    }
    return 0;
}