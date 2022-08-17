#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, k, q, m;
	cin >> n >> k >> q >> m;
	vector<bool> sleep(n+3, false);
	vector<bool> chk(n+3, false);
	vector<int> presum(n+3, 0);

	while (k--) {
		int a;
		cin >> a;
		sleep[a]=true;
	}
	while (q--) {
		int a;
		cin >> a;
		if (sleep[a]) continue;
		for (int i=a; i<=n+2; i+=a) {
			if (sleep[i]) continue;
			chk[i]=true;
		}
	}
	for (int i=1; i<=n+2; i++) {
		presum[i]=presum[i-1]+chk[i];
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << b-a+1-(presum[b]-presum[a-1]) << '\n';
	}

	return 0;
}
