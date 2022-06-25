#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;

	if (s.empty() || isupper(s[0]) || s[0]=='_' || s.back()=='_') {
		cout << "Error!";
		return 0;
	}

	bool isjava=true, iscpp=true;
	for (auto i:s) {
		if (i=='_') isjava=false;
		if (isupper(i)) iscpp=false;
	}
	if (!isjava && !iscpp) {
		cout << "Error!";
	}
	else if (isjava) {
		string t;
		for (auto i:s) {
			if (isupper(i)) {
				t.push_back('_');
				t.push_back(tolower(i));
			}
			else {
				t.push_back(i);
			}
		}
		cout << t;
	}
	else if (iscpp) {
		string t;
		bool flag=false;
		for (int i=0; i<(int)s.size(); i++) {
			if (flag) {
				if (s[i]=='_') {
					cout << "Error!";
					return 0;
				}
				else {
					t.push_back(toupper(s[i]));
					flag=false;
				}
			}
			else {
				if (s[i]=='_') {
					flag=true;
				}
				else {
					t.push_back(s[i]);
				}
			}
		}	
		cout << t;
	}

	return 0;
}
