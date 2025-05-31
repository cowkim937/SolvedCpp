#include<iostream>
#include<stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, temp;
    char cmd;
    stack<int> s;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> cmd;

        if(cmd == '1'){
            cin >> temp;
            s.push(temp);
        }
        else if(cmd == '2'){
            if(!s.empty()){
                cout << s.top() << "\n";
                s.pop();
            }
            else{
                cout << "-1" << "\n";
            }
        }
        else if(cmd == '3'){
            cout << s.size() << "\n";
        }
        else if(cmd == '4'){
            if(s.empty())
                cout << "1" << "\n";
            else
                cout << "0" << "\n";
        }
        else if(cmd == '5'){
            if(!s.empty())
                cout << s.top() << "\n";
            else
                cout << "-1" << "\n";
        }
    }

    return 0;
}