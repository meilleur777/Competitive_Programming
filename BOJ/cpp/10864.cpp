#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

bool conn[1001][1001] = { false };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		conn[a][b] = true;
		conn[b][a] = true;
	}
	
	for (int i = 1; i <= N; i++) {
		int count = 0;
		for (int j = 1; j <= N; j++) {
			count += conn[i][j];
		}
		cout << count << '\n';
	}
}

