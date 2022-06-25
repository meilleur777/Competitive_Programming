#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, w, L;
	cin >> n >> w >> L;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	queue<int> q;
	int now=0;
	int nxt=0;
	int ans=0;
	while (1) {
		while (!q.empty() && q.size()>w-1) {
			if (q.front()!=-1) {
				now-=a[q.front()];
			}
			q.pop();
		}
		if (nxt>=n) break;
		ans++;
		if (a[nxt]>L) {
			q.push(-1);
			nxt++;
		}
		else {
			if (now+a[nxt]>L) {
				q.push(-1);
			}
			else {
				q.push(nxt);
				now+=a[nxt];
				nxt++;
			}
		}
	}
	cout << ans+w;

	return 0;
}
