#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
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

	string S;
	cin >> S;
	char memo=S[0];
	int row=1;
	vector<int> clu;
	for (int i=1; i<S.size(); i++) {
		if (memo==S[i]) {
			row++;
		}
		else {
			clu.push_back(row);
			memo=S[i];
			row=1;
		}
	}
	clu.push_back(row);
	int sum0=0, sum1=0;
	for (int i=0; i<clu.size(); i++) {
		if (i%2) {
			sum0++;
		}
		else {
			sum1++;
		}
	}
	cout << min(sum0, sum1);

	return 0;
}
