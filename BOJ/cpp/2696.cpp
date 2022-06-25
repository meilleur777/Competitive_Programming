#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		priority_queue<int> pq1;
		priority_queue<int, vector<int>, greater<int>> pq2;
		cout << (m+1)/2 << '\n';
		rep(i, m) {
			int a;
			cin >> a;
			pq2.push(a);
			while (!pq1.empty() && pq1.top()>pq2.top()) {
				int t=pq2.top();
				pq2.pop();
				pq2.push(pq1.top());
				pq1.pop();
				pq1.push(t);
			}
			if (i%20==0 && i!=0) cout << '\n';
			if (i%2==0) {
				while (pq1.size()<i/2+1) {
					pq1.push(pq2.top());
					pq2.pop();
				}
				cout << pq1.top() << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}

