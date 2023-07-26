#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	if (n==0) {
		cout << n;
		return 0;
	}
	vector<int> dif(n);
	for (int i=0; i<n; i++) {
		cin >> dif[i];
	}

	sort(dif.begin(), dif.end());
	int exc=(n*15+50)/100;
	int sum=0;
	for (int i=exc; i<n-exc; i++) {
		sum+=dif[i];
	}
	int ans=(sum+(n-2*exc)/2)/(n-2*exc);
	cout << ans;

	return 0;
}
