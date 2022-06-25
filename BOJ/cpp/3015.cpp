#include <stack>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	stack<pair<int, int> > s;
	int x, N; cin >> N; ll count = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> x; int temp = 1;
		while (!s.empty() && s.top().first <= x) {
			if (s.top().first == x) temp += s.top().second;
			count += (ll)s.top().second;
			s.pop();
		}
		if (!s.empty()) {
			count++;
			s.push({ x, temp });
		}
		else s.push({ x, temp });
	}
	cout << count << '\n';
}

