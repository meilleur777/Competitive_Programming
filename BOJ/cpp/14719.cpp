#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int h, w;
	cin >> h >> w;
	vector<int> a(w);
	rep(i, w) cin >> a[i];

	int ans=0;
	for (int i=1; i<=500; i++) {
		int start=w, end=-1;
		for (int j=0; j<w; j++) {
			if (a[j]>=i) {
				start=j;
				break;
			}
		}
		for (int j=w-1; j>=0; j--) {
			if (a[j]>=i) {
				end=j;
				break;
			}
		}
		int cnt=end-start-1;
		for (int j=start+1; j<=end-1; j++) {
			if (a[j]>=i) cnt--;
		}
		ans+=max(0, cnt);
	}
	cout << ans;

	return 0;
}
