#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> llp;
typedef pair<int, int> intp;

llp operator -(const llp& p, const llp& q) {
	return make_pair(p.first-q.first, p.second-q.second);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<llp> pos(n);
		rep(i, n) cin >> pos[i].first >> pos[i].second;

		sort(pos.begin(), pos.end());
		function<ll(llp, llp, llp)> ccw=[&](llp a, llp b, llp c) {
			return a.first*b.second+b.first*c.second+c.first*a.second
				  -a.first*c.second-b.first*a.second-c.first*b.second;
		};
		sort(pos.begin()+1, pos.end(), [&](const llp& a, const llp& b) {
			ll tmp=ccw(pos[0], a, b);
			if (tmp!=0) return tmp>0;
			return a<b;
		});

		stack<pair<llp, int>> sk;
		sk.push({pos[0], 0});
		sk.push({pos[1], 1});
		for (int i=2; i<n; i++) {
			while (sk.size()>=2) {
				auto p=sk.top();
				sk.pop();
				auto q=sk.top();
				if (ccw(q.first, p.first, pos[i])>0) {
					sk.push(p);
					break;
				}
			}
			sk.push({pos[i], i});
		}

		vector<int> hull;
		while (!sk.empty()) {
			hull.push_back(sk.top().second);
			sk.pop();
		}
		int num=(int)hull.size();
		reverse(hull.begin(), hull.end());
		// for (auto i:hull) {
		// 	cout << pos[i].first << ' ' << pos[i].second << '\n';
		// }

		function<ll(ll)> sqr=[&](const ll& a) { return a*a; };
		function<ll(int, int)> dis=[&](const int& p, const int& q) {
			return sqr(pos[hull[p]].first-pos[hull[q]].first)+sqr(pos[hull[p]].second-pos[hull[q]].second);
		};
		function<ll(llp, llp)> cross=[&](const llp& p, const llp& q) {
			return p.first*q.second-q.first*p.second;
		};

		int left=0, right=0;
		for (int i=1; i<num; i++) {
			if (pos[hull[left]].first>pos[hull[i]].first) {
				left=i;
			}
			if (pos[hull[right]].first<pos[hull[i]].first) {
				right=i;
			}
		}

		intp ans={left, right};
		ll mx=dis(left, right);
		for (int i=0; i<2*num; i++) {
			ll tmp=cross(pos[hull[(left+1)%num]]-pos[hull[left]], pos[hull[right]]-pos[hull[(right+1)%num]]);
			if (tmp>0) {
				left=(left+1)%num;
			}
			else if (tmp==0) {
				left=(left+1)%num;
				right=(right+1)%num;
			}
			else {
				right=(right+1)%num;
			}
			tmp=dis(left, right);
			if (tmp>mx) {
				mx=tmp;
				ans={left, right};
			}
		}
		cout << pos[hull[ans.first]].first << ' ' << pos[hull[ans.first]].second << ' ';
		cout << pos[hull[ans.second]].first << ' ' << pos[hull[ans.second]].second << '\n';
	}

	return 0;
}
