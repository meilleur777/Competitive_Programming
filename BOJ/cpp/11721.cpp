#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string n;
	cin >> n;
	for (int i=0; i<(int)n.size(); i++) {
		if (i && i%10==0) cout << '\n';
		cout << n[i];
	}

	return 0;
}
