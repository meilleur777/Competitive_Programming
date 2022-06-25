#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, K;
	cin >> N >> K;
	
	string A;
	for (int i=0; i<N; i++) {
		char x;
		cin >> x;
		A.push_back(x);
	}
	
	deque<int> dq;
	
	int cnt = 0;
	for (int i=0; i<N; i++) {
		while (!dq.empty() && i-dq.front() > K) {
			dq.pop_front();
		}
		
		if (A[i] ==	'H') {
			if (!dq.empty() && A[dq.front()] == 'P') {
				dq.pop_front();
				cnt++;
			}
			else {
				dq.push_back(i);
			}
		}
		else {
			if (!dq.empty() && A[dq.front()] == 'H') {
				dq.pop_front();
				cnt++;
			}	
			else {
				dq.push_back(i);
			}
		}
	}	
	
	cout << cnt;
}

