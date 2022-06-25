#include <iostream>
#include <string.h> 
using namespace std;

int n;
bool areFriends[10][10];

int countPair(bool taken[10]) {
	int front = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) { front = i; break; }
	}	
	if (front == -1) return 1;
	int result = 0;
	for (int target = front + 1; target < n; target++) {
		if (!taken[target] && areFriends[front][target]) {
			taken[front] = taken[target] = true;
			result += countPair(taken);
			taken[front] = taken[target] = false;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int C; cin >> C;
	while (C--) {
		memset(areFriends, false, sizeof(areFriends));
		int m; cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			areFriends[a][b] = areFriends[b][a] = true;
		}
		bool taken[10] = { false };
		cout << countPair(taken) << '\n';
	}
}

