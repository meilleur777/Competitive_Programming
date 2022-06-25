#include <bits/stdc++.h>
using namespace std;

int main() {
	int w, h, x, y, p, ans=0;
	cin >> w >> h >> x >> y >> p;
	auto pp=[](int a) {return a*a;};
	while (p--) {
		int a, b;
		cin >> a >> b;
		bool c=a>=x && a<=x+w && b>=y && b<=y+h;
		bool d=pp(x-a)+pp(b-(y+h/2))<=pp(h/2);
		bool e=pp(x+w-a)+pp(b-(y+h/2))<=pp(h/2);
		ans+=c||d||e;
	}
	cout << ans;

	return 0;
}
