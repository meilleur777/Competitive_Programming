#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	queue<int> q;
	while (true) {
		int a;
		cin >> a;
		if (a==-1) break;
		else if (a==0) q.pop();
		else {
			if (q.size()>=n) continue;
			q.push(a);
		}
	}
	if (q.empty()) cout << "empty";
	else {
		while (!q.empty()) {
			cout << q.front() << ' ';
			q.pop();
		}
	}

	return 0;
}
