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
const int MAX=1e5+1;

int main() {
	init_code();

	int N, K;
	cin >> N >> K;
	vector<int> vis(MAX, INF);
	vis[N]=0;
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int tmp;
		if ((tmp=now-1)>=0 && vis[tmp]>vis[now]+1) { 
			vis[tmp]=vis[now]+1;
			q.push(tmp);
		}
		if ((tmp=v+1)<MAX && vis[tmp]>vis[now]+1) { 
			vis[tmp]=vis[now]+1;
			q.push(tmp);
		}
		if ((tmp=v*2)<MAX && vis[tmp]>vis[now]) { 
			vis[tmp]=vis[now];
			q.push(tmp);
		}
 	}
 	cout << vis[K];

	return 0;
}
