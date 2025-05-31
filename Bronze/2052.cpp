#include<iostream>
#include<cmath>

using namespace std;

int main(void){
    int n;
    double m;
    cin >> n;
    m = pow(0.5, n);
    printf("%.*f",n,m);
    return 0;
}