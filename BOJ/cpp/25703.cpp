#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    cout << "int a;\n";
    string rem="a";
    for (int i=1; i<=n; i++) {
        cout << string("int "+string(i, '*')+"ptr"+(i==1?"":to_string(i))+" = &"+rem+";") << '\n';
        rem="ptr"+(i==1?"":to_string(i));
    }

    return 0;
}
