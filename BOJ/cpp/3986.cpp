#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int ans=0;
	rep(i, n) {
		string s;
		cin >> s;
		stack<char> sk;
		for (auto c:s) {
			if (sk.empty()) sk.push(c);
			else {
				if (sk.top()==c) sk.pop();
				else sk.push(c);
			}
		}
		ans+=sk.empty();
	}
	cout << ans;

	return 0;
}
