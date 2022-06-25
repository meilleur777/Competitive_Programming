#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int l, rch, dam, amm;
	cin >> l >> rch >> dam >> amm;
	queue<int> q;
	int now=0;
	bool flag=true;
	for (int i=0; i<l; i++) {
		int hp;
		cin >> hp;
		if (!q.empty() && q.front()==i) {
			q.pop();
			now-=dam;
		}
		if (hp==0) {
			q.push(i+rch);
			now+=dam;
		}
		else {
			if (now+dam<hp) {
				if (amm==0) {
					flag=false;
				}
				else amm--;
			}
			else {
				q.push(i+rch);
				now+=dam;
			}
		}
	}
	if (flag) cout << "YES";
	else cout << "NO";

	return 0;
}
