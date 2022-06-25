#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int dy[]={0, 1, 0, -1};
int dx[]={1, 0, -1, 0};

int main() {
	init_code();

	int n, k;
	cin >> n >> k;
	set<intp> app;
	rep(i, k) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		app.insert({a, b});
	}
	int l;
	cin >> l;
	map<int, char> cha;
	rep(i, l) {
		int x;
		char c;
		cin >> x >> c;
		cha[x]=c;	
	}
	int ans=1;
	int dir=0;
	set<intp> sna;
	deque<intp> dq;
	intp head={0, 0};
	sna.insert(head);
	dq.push_back(head);
	while (true) {
		head.first+=dy[dir], head.second+=dx[dir];
		if (head.first>=n || head.first<0 || head.second>=n || head.second<0) {
			cout << ans;
			return 0;
		}
		if (sna.find(head)!=sna.end()) {
			cout << ans;
			return 0;
		}
		sna.insert(head);
		dq.push_front(head);
		if (app.find(head)==app.end()) {
			sna.erase(sna.find(dq.back()));
			dq.pop_back();
		}
		else {
			app.erase(app.find(head));
		}
		if (cha.find(ans)!=cha.end()) {
			char nd=cha[ans];
			if (nd=='D') dir++;
			else dir--;
			if (dir==4) dir=0;
			if (dir==-1) dir=3;
		}
		ans++;
	}

	return 0;
}
