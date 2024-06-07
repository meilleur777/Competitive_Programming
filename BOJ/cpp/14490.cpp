#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a%b==0) return b;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;

    int ptr=s.find(':');
    int a=stoi(s.substr(0, ptr));
    int b=stoi(s.substr(ptr+1));
    int g=gcd(a, b);
    a/=g;
    b/=g;

    cout << a << ":" << b;

    return 0;
}
