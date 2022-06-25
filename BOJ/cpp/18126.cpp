#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

bool visit[5001] = { false };
vector<pair<int, ll> > edges[5001];

ll solve(int root) {
	ll ret = 0;
	visit[root] = true;
	for (auto i : edges[root]) if (!visit[i.first]) ret = max(ret, solve(i.first) + i.second);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;	
	for (int i = 0; i < N - 1; i++) {
		int A, B; ll C;
		cin >> A >> B >> C;
		edges[A].push_back({ B, C });
		edges[B].push_back({ A, C });
	}
	cout << solve(1) << '\n'; 
}

