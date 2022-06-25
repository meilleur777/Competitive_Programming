#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> cnt(1001, 0);
	rep(i, n) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	auto print=[&](int k) {
		rep(i, cnt[k]) cout << k << ' ';
		cnt[k]=0;
	};
	rep(i, 1001) {
		if (!cnt[i]) continue;
		if (i+1>1000 || cnt[i+1]==0) {
			print(i);
		}
		else {
			int memo=-1;
			bool flag=false;
			for (int j=i+2; j<1001; j++) {
				if (cnt[j]>0) {
					memo=j;
					flag=true;
					break;
				}
			}

			if (flag) {
				print(i);
				cout << memo << ' ';
				cnt[memo]--;
			}
			else {
				print(i+1);
				print(i);
			}
		}
	}

	return 0;
}
