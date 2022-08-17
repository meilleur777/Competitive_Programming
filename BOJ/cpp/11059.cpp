#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	cin >> s;
	int ans=-1;
	for (int i=0; i<(int)s.size()-1; i++) {
		for (int j=i+1; j<(int)s.size(); j+=2) {
			int size=j-i+1;
			string front=s.substr(i, size/2);
			string back=s.substr(i+size/2, size/2);

			function<int(string)> sum=[&](string k) {
				int ret=0;
				for (auto c:k) {
					ret+=c-'0';
				}
				return ret;
			};
			if (sum(front)==sum(back)) {
				ans=max(ans, size);
			}
		}
	}
	cout << ans;

	return 0;
}
