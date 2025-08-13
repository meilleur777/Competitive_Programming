#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	long long n, m, t, s;
	cin >> n >> m >> t >> s;

	long long zipTime=n+((n+7)/8-1)*s;

	long long dokTime=t+m+((m+7)/8-1)*(2*t+s);

	if (zipTime<dokTime) cout << "Zip\n";
	else cout << "Dok\n";
	cout << min(zipTime, dokTime);

	return 0;
}
