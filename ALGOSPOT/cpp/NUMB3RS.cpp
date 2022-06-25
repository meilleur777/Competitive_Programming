#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int p;
vector<int> edges[101];
double cache[101][51]; 

/*d일 후 q에 있을 확률 반환*/
double solve(int d, int q) {
	double& ret = cache[d][q];
	if (ret != -1) return ret;
	
	ret = 0;
	for (auto i : edges[q]) ret += solve(d - 1, i) / edges[i].size();
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cout << fixed;
	cout.precision(15);
	
	int C; cin >> C;
	while (C--) {
		int n, d, t, q;
		cin >> n >> d >> p;
		
		memset(edges, false, sizeof(edges));
		fill(&cache[0][0], &cache[0][0] + 101 * 51 + 1, -1);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x; cin >> x;
				if (x == 1) edges[i].push_back(j);
			}
		}
		
		for (auto i : edges[p]) cache[1][i] = 1 / (double)edges[p].size();
		
		cin >> t;
		for (int i = 0; i < t - 1; i++) {
			cin >> q;
			cout << solve(d, q) << ' ';
		}
		cin >> q;
		cout << solve(d, q) << '\n';
	}	
}

