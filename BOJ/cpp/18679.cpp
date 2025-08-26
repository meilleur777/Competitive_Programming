#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	const string tgt=" = ";
	map<string, string> mp;

	cin.ignore();
	while (n--) {
		string str;
		getline(cin, str);

		int it=str.find(tgt);

		string a=str.substr(0, it);
		string b=str.substr(it+(int)tgt.size());

		mp[a]=b;
	}

	int m;
	cin >> m;
	while (m--) {
		int a;
		cin >> a;
		for (int i=0; i<a; i++) {
			string tmp;
			cin >> tmp;
			cout << mp[tmp] << ' ';
		}
		cout << '\n';
	}


	return 0;
}
