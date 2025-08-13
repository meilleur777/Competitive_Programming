#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	long double v, w, d;
	cin >> v >> w >> d;
	
	long double t=w/v;
	long double sum=0;

	int cnt=0;
	while (true) {
		sum+=5*t*t;
		t=t*1.25;

		if (sum<d) cnt++;
		else break;
	}

	cout << cnt;	

	return 0;
}
