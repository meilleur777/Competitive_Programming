#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	queue<int> q;
	rep(i, n) {
		q.push(i+1);
	}
	while ((int)q.size()>1) {
		cout << q.front() << ' ';
		q.pop();
		int t=q.front();
		q.pop();
		q.push(t);
	}
	cout << q.front();

	return 0;
}
