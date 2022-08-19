#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int ccw(intp a, intp b, intp c) {
	return a.first*b.second+b.first*c.second+c.first*a.second-a.first*c.second-b.first*a.second-c.first*b.second;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int cnt=1;
	while (true) { 
		int n;
		cin >> n;
		if (!n) break;
		vector<intp> pos(n);
		rep(i, n) cin >> pos[i].first >> pos[i].second;
		sort(pos.begin(), pos.end());
		sort(pos.begin()+1, pos.end(), [&](const intp& p, const intp& q) {
			int tmp=ccw(pos[0], p, q);
			if (tmp) return tmp>0;
			return p<q;
		});

		stack<int> sk;
		sk.push(0);
		sk.push(1);
		for (int i=2; i<n; i++) {
			while ((int)sk.size()>=2) {
				auto p=sk.top();
				sk.pop();
				auto q=sk.top();
				if (ccw(pos[q], pos[p], pos[i])>0) {
					sk.push(p);
					break;
				}
			}
			sk.push(i);
		}
		vector<int> hull;
		while (!sk.empty()) {
			hull.push_back(sk.top());
			sk.pop();
		}

		ld ans=1e18;
		int num=(int)hull.size();
		for (int i=0; i<num; i++) {
			auto now=pos[hull[i]];
			auto nxt=pos[hull[(i+1)%num]];
			ld mx=0;
			function<ld(int)> sqr=[&](int a) {return a*a;};
			ld dis=sqrtl(sqr(now.first-nxt.first)+sqr(now.second-nxt.second));
			for (int j=0; j<num; j++) {
				auto top=pos[hull[j]];
				auto siz=abs(ccw(now, nxt, top));
				mx=max(mx, (ld)siz/dis);
			}
			ans=min(ans, mx);
		}

		ans*=100;
		if (ans-(ll)ans>1e-15) {
            ans+=1;
            ans=(ll)ans;
        }
		ans/=100;

        cout.precision(2);
        cout << fixed;
        cout << "Case " << cnt << ": " << ans << '\n';
        cnt++;
    }

	return 0;
}
