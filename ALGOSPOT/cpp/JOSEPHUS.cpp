#include <queue>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		deque<int> dq;
		int N, K; cin >> N >> K;
		for (int i = 2; i <= N; i++) dq.push_back(i);
		
		int count = K - 1;
		while (dq.size() > 2) {
			while (count--) {
				dq.push_back(dq.front()); 
				dq.pop_front();
			}
			dq.pop_front();
			count = K - 1;
		}
		
		int a = dq.front(), b = dq.back();
		if (a < b) cout << a << ' ' << b << '\n';
		else cout << b << ' ' << a << '\n';	
	}	
}

