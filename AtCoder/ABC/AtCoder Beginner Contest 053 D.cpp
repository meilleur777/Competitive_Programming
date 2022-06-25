#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int N;
	cin >> N;
	vector<int> cnt(1e5+1, 0);
	rep(i, N) {
		int x;
		cin >> x;
		cnt[x]++;
	}	
	int odd=0, even=0;
	for (auto& i : cnt) {
		if (i==0) continue;
		if (i>=3) {
			if (i%2) i=1;
			else i=2;
		}
		if (i%2) odd++;
		else even++;
	}
	if (even%2) {
		cout << odd+even-1;
	}
	else {
		cout << odd+even;
	}

	return 0;
}
