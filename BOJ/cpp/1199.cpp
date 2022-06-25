#include <vector>
#include <iostream>
using namespace std;

int N, adj[1001][1001], ptr[1001] = { 0 };

void solve(int s) {
	for (int& i = ptr[s]; i < N; i++) {
		while (adj[s][i]) {
			adj[s][i]--;
			adj[i][s]--;
			solve(i);
		}
	}
	cout << s + 1 << ' ';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
			cnt += adj[i][j];
		}
		if (cnt & 1) {
			cout << -1;
			return 0;
		}
	}
	solve(0);	
}

