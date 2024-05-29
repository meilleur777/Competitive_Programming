#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    int num=1;
    while (true) {
        cin >> n;
        if (n==0) break;

        bool isEven=false;
        n*=3;
        if (n%2==0) isEven=true;

        if (isEven) n/=2;
        else n=(n+1)/2;

        n*=3;
        n/=9;

        cout << num << ". " << (isEven?"even ":"odd ") << n << '\n';
        num++;
    }

    return 0;
}
