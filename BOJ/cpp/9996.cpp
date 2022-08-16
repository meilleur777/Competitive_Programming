#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;

	string front=s.substr(0, s.find('*'));
	string back=s.substr(s.find('*')+1);
	// cout << front << ' ' << back << '\n';

	while (n--) {
		string t;
		cin >> t;

		// cout << t.substr(0, (int)front.size()) << ' ' << t.substr((int)t.size()-(int)back.size()) << '\n';

		if ((int)t.size()>=(int)s.size()-1 && 
			t.substr(0, (int)front.size())==front && t.substr((int)t.size()-(int)back.size())==back) {
			cout << "DA\n";
		}
		else cout << "NE\n";
	}

	return 0;
}
