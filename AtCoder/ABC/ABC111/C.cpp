#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	init_code();

	int n;
	cin >> n;
	vector<int> cntEven(1e5+1, 0), cntOdd(1e5+1, 0);
	rep(i, n) {
		int x;
		cin >> x;
		if (i%2) {
			cntOdd[x]++;
		}
		else {
			cntEven[x]++;

		}
	}
	int ei = max_element(cntEven.begin(), cntEven.end())-cntEven.begin();
	int oi = max_element(cntOdd.begin(), cntOdd.end())-cntOdd.begin();
	if (ei != oi) {
		cout << n-cntEven[ei]-cntOdd[oi];
	}
	else {
		int em = cntEven[ei];
		cntEven[ei] = -1;
		int nei = max_element(cntEven.begin(), cntEven.end())-cntEven.begin();
		int om = cntOdd[oi];
		cntOdd[oi] = -1;
		int noi = max_element(cntOdd.begin(), cntOdd.end())-cntOdd.begin();
		int ecan = n-em-cntOdd[noi];
		int ocan = n-om-cntEven[nei];
		cout << min(ecan, ocan);
	}

	return 0;
}
