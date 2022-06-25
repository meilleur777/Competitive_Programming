#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll solve(const vector<ll>& h, int left, int right) {
	if (left == right) return h[left];
	
	int mid = (left + right) / 2;
	ll result = max(solve(h, left, mid), solve(h, mid + 1, right));	
	
	int lo = mid, hi = mid + 1;
	ll height = min(h[lo], h[hi]);
	result = max(result, height * 2);
	while (left < lo || hi < right) {
		if (hi < right && (left == lo || h[lo - 1] < h[hi + 1])) 
			height = min(height, h[++hi]);
		else height = min(height, h[--lo]);
		result = max(result, height * (hi - lo + 1));
	}
	return result;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while (true) {
		int n; cin >> n;
		if (!n) break;
		vector<ll> h(n);
		for (int i = 0; i < n; i++) cin >> h[i];
		cout << solve(h, 0, n - 1) << '\n';
	}	
}

