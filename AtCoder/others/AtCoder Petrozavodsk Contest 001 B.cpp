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
	vector<ll> a(n), b(n);
	ll suma=0, sumb=0;
	rep(i, n) {
		cin >> a[i];
		suma+=a[i];
	}
	rep(i, n) {
		cin >> b[i];
		sumb+=b[i];
	}
	if (suma>sumb) {
		cout << "No";
		return 0;
	}
	if (suma==sumb) {
		if (a==b) {
			cout << "Yes";
		}
		else {
			cout << "No";
		}
		return 0;
	}
	ll needa=0, needb=0;
	for (int i=0; i<n; i++) {
		if (a[i]<b[i]) {
			if ((b[i]-a[i])%2) {
				b[i]++;
				a[i]+=2;
				needa+=(b[i]-a[i])/2;
			}
			else {
				needa+=(b[i]-a[i])/2;
			}
		}
		else if (a[i]>b[i]) {
			needb+=a[i]-b[i];
		}
	}
	if (needa>=needb) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
