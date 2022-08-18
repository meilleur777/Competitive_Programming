#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;
	if (M<m+T) cout << -1;
	else {
		int now=m;
		int cnt=0;
		while (N>0) {
			cnt++;
			if (now+T<=M) {
				now+=T;
				N--;
			}
			else {
				now=max(m, now-R);
			}
		}
		cout << cnt;
	}

	return 0;
}
