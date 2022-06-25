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

vector<vector<int> > c, D;

int main() {
	init_code();

	int N, C;
	cin >> N >> C;
	c = vector<vector<int> >(N, vector<int>(N));
	D = vector<vector<int> >(C, vector<int>(C));
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			cin >> D[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c[i][j];
		}
	}
	vector<vector<intp> > wrong(3, vector<intp>(C, {0, 0}));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < C; j++) {
			wrong[i][j].second = j;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {	
			for (int k = 0; k < C; k++) {
				wrong[(i+j)%3][k].first += D[c[i][j]-1][k];
			}
		}
	}
	vector<vector<intp> > cand(3);
	for (int i = 0; i < 3; i++) {
		sort(wrong[i].begin(), wrong[i].end(), greater<intp>());
		for (int j = 0; j < 3; j++) {
			cand[i].push_back(wrong[i].back());
			wrong[i].pop_back();
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				intp A = cand[0][i];
				intp B = cand[1][j];
				intp D = cand[2][k];
				if (A.second == B.second || B.second == D.second || D.second == A.second) continue;
				ans = min(ans, A.first+B.first+D.first);
			}
		}
	}
	cout << ans;

	return 0;
}
