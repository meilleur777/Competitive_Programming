#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    int i=1;
    while (true) {
        getline(cin, s, '\n');
        if (s=="0") break;
        cout << "Case " << i << ": Sorting... done!\n";
        i++;
    }

    return 0;
}
