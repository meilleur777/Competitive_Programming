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

	int M, N;
	cin >> M >> N;
	int k;
	cin >> k;
	vector<int> X, Y;
	X.push_back(0);
	Y.push_back(0);
	X.push_back(M);
	Y.push_back(N);
	rep(i, k) {
		int a, b;
		cin >> a >> b;
		if (a==1) {
			X.push_back(b);
		}
		else {
			Y.push_back(b);
		}
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	int mx=-1, my=-1;
	for (int i=0; i<X.size()-1; i++) {
		mx=max(mx, X[i+1]-X[i]);
	}
	for (int i=0; i<Y.size()-1; i++) {
		my=max(my, Y[i+1]-Y[i]);
	}
	cout << mx*my;

	return 0;
}
