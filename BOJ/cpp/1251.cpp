#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	cin >> s;
	int num=(int)s.size();
	set<string> st;
	for (int i=1; i<=num-2; i++) {
		for (int j=1; j<=num-i-1; j++) {
			string a=s.substr(0, i);
			string b=s.substr(i, j);
			string c=s.substr(i+j);
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			reverse(c.begin(), c.end());
			st.insert(a+b+c);
		}
	}
	cout << *st.begin();

	return 0;
}
