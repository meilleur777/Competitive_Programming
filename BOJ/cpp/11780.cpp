#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define INF 0x3F3F3F3F3F3F3F3F
using namespace std;

typedef long long ll;

ll dist[102][102];
vector<int> trace[102][102];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	memset(dist, 0x3F, sizeof(dist));
	
	int n, m; cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
			
			trace[i][j].push_back(i);
			trace[i][j].push_back(j);
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (dist[a][b] > c) dist[a][b] = c;
	} 	
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k]) {
					dist[j][k] = dist[j][i] + dist[i][k];
					
					trace[j][k] = trace[j][i];
					trace[j][k].pop_back();
					for (auto l : trace[i][k]) trace[j][k].push_back(l);
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF || !dist[i][j]) cout << 0 << '\n';
			else {
				cout << trace[i][j].size() << ' ';
 				for (auto k : trace[i][j]) cout << k << ' ';
				cout << '\n';
			}
		}
	}
}

