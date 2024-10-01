#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input, output;
    istringstream ss;
    int cnt = 0;

    getline(cin, input);
    
    ss.str(input);
    while(ss >> output) cnt++;
    cout << cnt;
    return 0;
}