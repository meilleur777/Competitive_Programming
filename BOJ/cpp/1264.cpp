#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	while (true) {
		string s;
		getline(cin, s);
		if (s=="#") break;

		int cnt=0;
		for (auto c:s) {
			cnt+=c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
		}
		cout << cnt << '\n';
	}

	return 0;
}
