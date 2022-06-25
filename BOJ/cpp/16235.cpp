#include <deque>
#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int A[11][11];
int food[11][11]; 
int dead[11][11] = { 0 };
int cnt[11][11] = { 0 };
deque<int> tree[11][11];	/*나이 적은 나무 먼저*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M, K;
	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[j][i];
			food[i][j] = 5;
		}
	}
	
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[y][x].push_back(z);
		if (z % 5 == 0) {
			cnt[y][x]++;
		}
	}
	
	while (K--) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				sort(tree[i][j].begin(), tree[i][j].end());
				
				for (int k = 0; k < tree[i][j].size(); k++) {
					int& temp = tree[i][j][k];
										
					if (temp <= food[i][j]) {
						food[i][j] -= temp;
						temp++;
						
						switch (temp % 5) {
							case 0: cnt[i][j]++; break;
							case 1: cnt[i][j]--;
						}
					}
					else {
						while (tree[i][j].size() > k) {
							if (tree[i][j].back() % 5 == 0) {
								cnt[i][j]--;
							}
							dead[i][j] += tree[i][j].back() / 2;
							tree[i][j].pop_back();
						}
						break;
					}
				}
			}
		}
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				food[i][j] += dead[i][j];	
				dead[i][j] = 0;
			}
		}
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int temp = cnt[i][j];
				while (temp--) {
					for (int dy = -1; dy < 2; dy++) {
						for (int dx = -1; dx < 2; dx++){
							if (!dy && !dx) continue;
							int ny = i + dy, nx = j + dx;
							if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
							
							tree[ny][nx].push_back(1);
						}
					}
				}
			}
		}
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				food[i][j] += A[i][j];
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += tree[i][j].size();
		}
	}
	cout << ans << '\n';
}

