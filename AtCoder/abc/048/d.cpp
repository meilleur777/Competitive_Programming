#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;

    bool flag1=(int)s.size()%2==0;
    bool flag2=s.front()==s.back();
    if ((flag1+flag2)%2) cout << "Second";
    else cout << "First";

    return 0;
}
