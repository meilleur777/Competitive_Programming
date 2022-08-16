#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	function<int(int)> rev=[&](int a) {
		string aa=to_string(a);
		reverse(aa.begin(), aa.end());
		return stoi(aa);
	};

	int x, y;
	cin >> x >> y;
	cout << rev(rev(x)+rev(y));

	return 0;
}
