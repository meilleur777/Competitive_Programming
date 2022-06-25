#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int sum=0;
	int siz=0;
	int now=0;
	int ans=INT_MIN;
	while (now<n) {
		while (siz<k) {
			sum+=a[now];
			now++;
			siz++;
		}
		ans=max(ans, sum);
		sum-=a[now-k];
		siz--;
	}
	cout << ans;

	return 0;
}
