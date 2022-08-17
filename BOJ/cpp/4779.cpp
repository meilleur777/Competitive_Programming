#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int power(int a, int b) {
	if (b==0) return 1;
	if (b==1) return a;
	int t=power(a, b/2);
	t*=t;
	if (b%2) return t*a;
	return t;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	while (cin >> n) {
		string s(power(3, n), '-');
		function<void(int, int, int)> sol=[&](int start, int end, int size) {
			if (size==1) return;
			for (int i=start+size/3; i<start+size/3*2; i++) {
				s[i]=' ';
			}
			sol(start, start+size/3-1, size/3);
			sol(start+size/3*2, end, size/3);
		};
		sol(0, (int)s.size()-1, power(3, n));
		cout << s << '\n';
	}
	

	return 0;
}
