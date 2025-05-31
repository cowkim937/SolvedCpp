#include <iostream>

using namespace std;

template<typename E>
class Stack{
public:
    Stack(int cap = 100);
    int size() const;
    bool empty() const;
    const E& top() const;
    void push(const E& e);
    void pop();
private:
    E* S;
    int max;
    int ptr;
};

template<typename E> Stack<E>::Stack(int cap)
    : S(new E[cap]), max(cap), ptr(-1) { }

template<typename E> int Stack<E>::size() const
{ return (ptr + 1); }

template<typename E> bool Stack<E>::empty() const
{ return (ptr < 0); }

template<typename E> const E& Stack<E>::top() const{
    return S[ptr];
}

template<typename E> void Stack<E>::push(const E& e){
    S[++ptr] = e;
}

template<typename E> void Stack<E>::pop(){
    --ptr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, cmd, x;
    Stack<int> s(1000001);

    cin >> n;

    while(n--){
        cin >> cmd;
        switch (cmd) {
            case 1:
                cin >> x;
                s.push(x);
                break;
            case 2:
                if(s.empty())
                    cout << "-1" << "\n";
                else{
                    cout << s.top() << "\n";
                    s.pop();
                }
                break;
            case 3:
                cout << s.size() << "\n";
                break;
            case 4:
                if(s.empty())
                    cout << "1" << "\n";
                else
                    cout << "0" << "\n";
                break;
            case 5:
                if(s.empty())
                    cout << "-1" << "\n";
                else
                    cout << s.top() << "\n";
                break;       
        }
    }
    
    return 0;
}