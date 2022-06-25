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

int main() {
	init_code();

	int N, d, k, c;
	cin >> N >> d >> k >> c;
	vector<int> A(N);
	rep(i, N) cin >> A[i];
	int now = 0;
	vector<int> cnt(d+1, 0);
	int ans = -1;
	int left = 0, right = 0;
	cnt[c] = 1;
	now++;
	while (right-left < k-1) {
		if (cnt[A[right]] == 0) {
			now++;
		} 
		cnt[A[right]]++;
		right++;
	}
	while (true) {
		if (cnt[A[right]] == 0) {
			now++;
		}
		cnt[A[right]]++;
		right++;
		if (right == N) {
			right = 0;
		}
		ans = max(ans, now);
		if (right == k-1) {
			break;
		}
		if (cnt[A[left]] == 1) {
			now--;
		}
		cnt[A[left]]--;
		left++;
		if (left == N) {
			left = 0;
		}
	}
	cout << ans;

	return 0;
}
