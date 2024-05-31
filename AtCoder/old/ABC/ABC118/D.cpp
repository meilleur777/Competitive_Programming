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

int N;
vector<int> cache;
vector<int> can;
vector<int> cost({0, 2, 5, 5, 4, 5, 6, 3, 7, 6});

const string NEGINF = "/";

string cmax(const string& a, const string& b) {
	if (a.size() > b.size()) {
		return a;
	}
	else if (a.size() == b.size()) {
		return (a > b) ? a : b;
	}
	else {
		return b;
	}
}

int main() {
	init_code();

	int M;
	cin >> N >> M;
	rep(i, M) {
		int x;
		cin >> x;
		can.push_back(x);
	}	
	vector<string> cache(N+100, NEGINF);
	cache[0] = "";
	for (int i = 0; i <= N; i++) {
		if (cache[i] == NEGINF) continue;
		for (auto j : can) {
			cache[i+cost[j]] = cmax(cache[i+cost[j]], cache[i]+char(j+'0'));
		}
	}
	cout << cache[N];

	return 0;
}
