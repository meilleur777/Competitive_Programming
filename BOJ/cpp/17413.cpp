#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	getline(cin, s);
	string t;
	bool flag=false;
	for (int i=0; i<(int)s.size(); i++) {
		if (flag) {
			if (s[i]=='>') {
				t+=s[i];
				flag=false;
				cout << t;
				t="";
			}
			else {
				t+=s[i];
			}
		}
		else {
			if (s[i]=='<') {
				reverse(t.begin(), t.end());
				cout << t;
				t="<";
				flag=true;
			}	
			else if (s[i]==' ') {
				reverse(t.begin(), t.end());
				cout << t << ' ';
				t="";
			}
			else {
				t+=s[i];
			}
		}
	}
	reverse(t.begin(), t.end());
	cout << t;

	return 0;
}
