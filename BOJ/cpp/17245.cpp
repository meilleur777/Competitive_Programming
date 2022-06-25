#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p;

int N;
ll all = 0;
int board[1001][1001];

bool chk(int h) {
	ll sum = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			sum += min(h, board[i][j]);
		}
	}
	return sum >= (all+1)/2;	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	
	int right = -1;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> board[i][j];
			all += board[i][j];
			right = max(right, board[i][j]);
		}
	}
	
	int ans, left = 0;
	while (left <= right) {
		int mid = (left+right)/2;
		
		if (chk(mid)) {
			ans = mid;
			right = mid-1;
		}
		else {
			left = mid+1;
		}
	} 
	cout << ans;
}

