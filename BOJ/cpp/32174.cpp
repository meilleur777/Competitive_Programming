#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	vector<int> v(m+1);
	v[0]=0;
	int now=0;
	for (int i=1; i<=m; i++) {
		long long a, b;
		cin >> a >> b;

		if (a==1) {
			now=(now+b)%n;
		}
		if (a==2) {
			now=(now+(b/n+1)*n-b)%n;
		}
		if (a==3) {
			now=v[b];
		}

		v[i]=now;
	}

	now=(now+1)%n;
	if (now==0) now=n;
	cout << now;

	return 0;
}
