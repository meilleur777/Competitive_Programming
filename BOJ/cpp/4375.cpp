#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
		
	int n;
	while (cin >> n) {
		int cnt=1;
		int now=1%n;
		while (now) {
			now=(now*10+1)%n;
			cnt++;
		}
		cout << cnt << '\n'	;
	}

	return 0;
}
