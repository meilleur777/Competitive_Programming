#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	
	int e, s, m;
	cin >> e >> s >> m;

    for (int year=1;; year++) {
        if (year%15==e%15 && year%28==s%28 && year%19==m%19) {
            cout << year;
            break;
        }
    }

    return 0;
}

