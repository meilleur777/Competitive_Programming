#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << fixed;
	cout.precision(3);

	ld x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	auto sqr=[&](ld x) { return x*x; };
	ld dis=sqrt(sqr(x1-x2)+sqr(y1-y2));
	if (r1+r2<=dis) cout << (ld)0;
	else if (dis+min(r1, r2)<=max(r1, r2)) cout << (ld)sqr(min(r1, r2))*4*atan(1);
	else {
		ld t1=acos((sqr(r1)+sqr(dis)-sqr(r2))/(2*r1*dis));
		ld t2=acos((sqr(r2)+sqr(dis)-sqr(r1))/(2*r2*dis));
		cout << t1*sqr(r1)+t2*sqr(r2)-sqr(r1)*cos(t1)*sin(t1)-sqr(r2)*cos(t2)*sin(t2);
	}

	return 0;
}
