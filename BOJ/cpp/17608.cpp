#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;
	stack<int> s;
	for (int i=0; i<N; i++) {
		int h;
		cin >> h;
		while (!s.empty() && s.top() <= h) {
			s.pop();
		}
		s.push(h);
	}
	cout << s.size();
}

