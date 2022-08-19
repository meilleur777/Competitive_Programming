#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	int cnt=0;
	char fbi[22]="FBI";
	rep(i, 5) {
		char s[100];
		scanf("%s", s);
		if (strstr(s, fbi)!=NULL) {
			cout << i+1 << ' ';
			cnt++;
		}
	}
	if (!cnt) cout << "HE GOT AWAY!";

	return 0;
}
