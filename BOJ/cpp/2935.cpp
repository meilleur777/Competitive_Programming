#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string a, b;
    char ope;
    cin >> a >> ope >> b;

    if (ope=='*') {
        cout << 1 << string((int)a.size()+(int)b.size()-2, '0');
    }
    else {
        int aa=a.size();
        int bb=b.size();
        if (aa<bb) {
            swap(a, b);
            aa=a.size();
            bb=b.size();
        }

        if (aa==bb) {
            cout << 2 << string(aa-1, '0');
        }
        else {
            cout << a.substr(0, aa-bb) << b;
        }
    }

    return 0;
}
