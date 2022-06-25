#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

int N;
vector<int> cnt;
vector<vector<int> > cache;

int solve(int now, int use) {
	if (now==N+1) {
		if (use==75) return 1;
		else return 0;
	}
	int& ret=cache[now][use];
	if (ret!=-1) return ret;
	ret=0;
	for (int i=0; i<=cnt[now]; i++) {
		if (use*(i+1)<=75) {
			ret+=solve(now+1, use*(i+1));
		}
	}
	return ret;
}

int main() {
	init_code();

	cin >> N;
	cnt=vector<int>(N+1, 0);
	for (int i=1; i<=N; i++) {
		int tmp=i;
		for (int j=2; j*j<=tmp; j++) {
			while (tmp%j==0) {
				cnt[j]++;
				tmp/=j;
			}
		}
		if (tmp!=1) {
			cnt[tmp]++;
		}
	}
	cache=vector<vector<int> >(N+1, vector<int>(76, -1));
	cout << solve(0, 1);

	return 0;
}
