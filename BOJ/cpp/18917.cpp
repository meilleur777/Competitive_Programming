#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int m;
	cin >> m;
	ll sum=0;
	int t=0;
	while (m--) {
		int x, y;
		cin >> x;
		switch(x) {
			case 1:
				cin >> y;
				sum+=y;
				t^=y;
				break;
			case 2:
				cin >> y;
				sum-=y;
				t^=y;
				break;
			case 3:
				cout << sum << '\n';
				break;
			case 4:
				cout << t << '\n';
		}
	}

	return 0;
}
