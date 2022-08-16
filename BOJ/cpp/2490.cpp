#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	rep(i, 3) {
		int cnt=0;
		rep(j, 4) {
			int a;
			cin >> a;
			cnt+=1-a;
		}
		if (!cnt) cout << "E\n";
		else cout << char('A'+cnt-1) << '\n';
	}

	return 0;
}
