#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> tpq, dpq;

	long double time=0;
	long double now=0;
	long double slow=1;

	for (int i=0; i<n; i++) {
		char c;
		int a;
		cin >> c >> a;
		if (c=='T') {
			tpq.push(a);
		}
		if (c=='D') {
			dpq.push(a);
		}
	}

	const long double inf=LDBL_MAX;
	while (now<=1000) {
		if (tpq.empty() && dpq.empty()) {
			time+=(1000-now)*slow;
			break;
		}

		long double tTime;
		if (tpq.empty()) tTime=inf;
		else tTime=tpq.top()-time;

		long double dTime;
		if (dpq.empty()) dTime=inf;
		else dTime=(dpq.top()-now)*slow;

		if (tTime>dTime) {
			time+=dTime;
			now=dpq.top();
			dpq.pop();
			slow++;
		}
		else {
			now+=tTime/slow;
			time=tpq.top();
			tpq.pop();
			slow++;
		}
	}	

	cout << (long long)(time+0.5);

	return 0;
}
