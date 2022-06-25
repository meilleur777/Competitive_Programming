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

vector<int> A;
map<int, int> cntFactor;
vector<map<int, int> > factor;

int main() {
	init_code();

	int N;
	cin >> N;
	A.resize(N);
	factor.resize(N);
	rep(i, N) cin >> A[i];	
	for (int i = 0; i < A.size(); i++) {
		for (int j = 2; j*j <= A[i]; j++) {
			while (A[i]%j == 0) {
				A[i] /= j;
				factor[i][j]++;
				cntFactor[j]++;
			}
		}
		if (A[i] != 1) {
			factor[i][A[i]]++;
			cntFactor[A[i]]++;
		}
	}
	vector<intp> need;
	int sco = 1;
	for (auto& [a, b] : cntFactor) {
		if (b >= N) {
			need.push_back({a, b/N});
		}
		sco *= (int)pow(a, b/N);
	}
	int ans = 0;
	for (auto& i : factor) {
		for (auto& j : need) {
			ans += max(0, j.second-i[j.first]);
		}
	}
	cout << sco << ' ' << ans;

	return 0;
}
