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

int ncr(int n, int r) {
	if (n<r) return 0;
	if (n==r) return 1;
	int ret=1;
	for (int i=0; i<r; i++) {
		ret*=n-i;
		ret/=i+1;
	}
	return ret;
}

int main() {
	init_code();

	string n;
	int k;
	cin >> n >> k;
	int siz=n.size();
	if (siz<k) {
		cout << 0;
		return 0;
	}
	ll ans=0;
	for (int i=1; i<siz; i++) {
		ans+=pow(9, k)*ncr(i-1, k-1);
	}
	if (k==1) {
		for (int i=1; i<10; i++) {
			string tmp;
			tmp.push_back(char(i+'0'));
			tmp+=string(siz-k, '0');
			if (tmp<=n) ans++;
		}
	}
	else if (k==2) {
		for (int i=1; i<10; i++) {
			for (int j=1; j<10; j++) {
				string tmp;
				tmp.push_back(char(i+'0'));
				tmp.push_back(char(j+'0'));
				tmp+=string(siz-k, '0');
				sort(tmp.begin()+1, tmp.end());
				do {
					if (tmp<=n) ans++;
				} while (next_permutation(tmp.begin()+1, tmp.end()));
			}
		}	
	}
	else if (k==3) {
		for (int i=1; i<10; i++) {
			for (int j=1; j<10; j++) {
				for (int l=j; l<10; l++) {
					string tmp;
					tmp.push_back(char(i+'0'));
					tmp.push_back(char(j+'0'));
					tmp.push_back(char(l+'0'));
					tmp+=string(siz-k, '0');	
					sort(tmp.begin()+1, tmp.end());
					do {
						if (tmp<=n) ans++;
					} while (next_permutation(tmp.begin()+1, tmp.end()));
				}
			}
		}
	}
	cout << ans;

	return 0;
}
