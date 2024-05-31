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

int main() {
	init_code();

	int n;
	cin >> n;
	vector<int> cnt(3, 0);
	rep(i, n) {
		int a;
		cin >> a;
		if (a%4==0) cnt[2]++;
		else if (a%2==0) cnt[1]++;
		else cnt[0]++;
	}
	if (cnt[0]==0) {
		cout << "Yes";
	}
	else {
		if (cnt[1]==0) {
			if (cnt[2]+1<cnt[0]) {
				cout << "No";
			}
			else cout << "Yes";
		}
		else {
			if (cnt[2]<cnt[0]) {
				cout << "No";
			}
			else {
				cout << "Yes";
			}
		}
	}

	return 0;
}
