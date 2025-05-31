#include<iostream>
#include<string>

using namespace std;

int isPalindrome(string s, int left, int right, bool del){
    while(left < right){
        if(s[left] != s[right]){
            if(del) return 2;
            return min(isPalindrome(s, left+1, right, true), isPalindrome(s, left, right-1, true));
        }
        left++;
        right--;
    }
    return del;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string s;
        int del = 0;
        cin >> s;
        int l=0, r=s.size()-1;
        while(l < r){
            if(s[l] != s[r]){
                if(del){
                    del = 2;
                    break;
                }
                else
                    del = 1;

                if(s[l+1] != s[r] && s[l] != s[r-1] && s[l+1] != s[r-1]){
                    del = 2;
                    break;
                }

                if(s[l+1] == s[r])
                    l++;
                else if(s[l] == s[r-1])
                    r--;
            }
            else{
                l++;
                r--;
            }
        }
        cout << del << '\n';
    }
    return 0;
}