#include<iostream>

using namespace std;

int main(void){
    int T;
    int h, w, n;
    cin >> T;
    while(T--){
        cin >> h >> w >> n;
        cout << (n%h ? n%h : n) << "0" << (n-1)/h + 1 << "\n";
    }
    return 0;
}