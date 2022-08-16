#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if ((int)s.size()>=6 && (int)s.size()<=9) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
