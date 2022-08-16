#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	vector<int> ans;
	vector<bool> chk(n, false);
	int now=0;
	int nxt=0;
	while ((int)ans.size()<n) {
		while (true) {
			if (nxt==0) {
				chk[now]=true;
				ans.push_back(now);
				nxt=a[now];
				break;
			}
			int tmp=(nxt>0)?1:-1;
			now=(now+n+tmp)%n;
			while (chk[now]==true) {
				now=(now+n+tmp)%n;
			}
			nxt-=tmp;
		}
	}

	for (auto i:ans) cout << i+1 << ' ';

	return 0;
}
