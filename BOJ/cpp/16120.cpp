#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	int now=0;
	auto ret=[]() {cout << "NP"; exit(0);};
	for (int i=0; i<(int)s.size(); i++) {
		if (s[i]=='P') now++;
		else if (s[i]=='A' && now>=2 && s[i+1]=='P') {
			now--;
			i++;
		}
		else ret();
	}
	if (now==1) cout << "PPAP";
	else ret();

	return 0;
}
