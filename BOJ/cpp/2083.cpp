#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	while (true) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		if (s=="#") break;
		cout << s << ' ';
		if (a>17 || b>=80) cout << "Senior\n";
		else cout << "Junior\n";
	}

	return 0;
}
