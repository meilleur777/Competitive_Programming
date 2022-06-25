#include <stack>
#include <iostream>
using namespace std;

typedef pair<int, int> p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	stack<p> s;
	int N, x; cin >> N >> x;
	s.push({ 1, x });
	cout << "0 ";
	for (int i = 2; i <= N; i++) {
		cin >> x;
		while (!s.empty() && s.top().second < x) s.pop();
		if (s.empty()) cout << "0 ";
		else cout << s.top().first << ' ';
		s.push({ i, x });
	}	
	cout << '\n';
}

