#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int N;
int mp, mf, ms, mv;
int p[16], f[16], s[16], v[16], c[16];
bool sel[16] = { false };
vector<int> res;

int best = INT_MAX;

void solve(int now, int cp, int cf, int cs, int cv, int cc) {
	if (cp >= mp && cf >= mf && cs >= ms && cv >= mv && cc < best) {
		best = min(best, cc);
		res.clear();
		for (int i=0; i<N; i++) {
			if (sel[i]) {
				res.push_back(i);
			}
		}		
		return;
	}
	else if (now == N) return;
	
	sel[now] = true;
	solve(now + 1, cp + p[now], cf + f[now], cs + s[now], cv + v[now], cc + c[now]);
	sel[now] = false;
	solve(now + 1, cp, cf, cs, cv, cc);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	cin >> mp >> mf >> ms >> mv;
	for (int i=0; i<N; i++) {
		cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
	}
	
	solve(0, 0, 0, 0, 0, 0);	
	if (best == INT_MAX) {
		cout << -1;
		return 0;
	}
	
	cout << best << '\n';
	for (int i : res) {
		cout << i + 1 << ' ';
	}
	cout << '\n';
}

