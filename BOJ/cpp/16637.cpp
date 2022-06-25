#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	int mx=INT_MIN;
	auto cal=[&](int left, int right) {
		ll ret=s[left]-'0';
		left+=2;
		while (left<=right) {
			ll kind=s[left-1];
			if (kind=='+') ret+=s[left]-'0';
			else if (kind=='-') ret-=s[left]-'0';
			else ret*=s[left]-'0';
			left+=2;
		}
		return ret;
	};
	for (int i=0; i<(1<<((n+1)/2)); i++) {
		queue<ll> q;
		int left=0;
		int right=0;
		bool flag=false;
		while (right<n) {
			while (right-left<4 && right<n && (i&(1<<(left/2)))==(i&(1<<(right/2)))) {
				right+=2;
			}
			if (left-1>0) q.push(s[left-1]+1e12);
			q.push(cal(left, right-2));
			left=right;
		}
		ll temp=0;
		temp+=q.front();
		q.pop();
		while (!q.empty()) {
			ll kind=q.front()-1e12;
			q.pop();
			if (kind=='+') temp+=q.front();
			else if (kind=='-') temp-=q.front();
			else temp*=q.front();
			q.pop();
		}
		mx=max(mx, (int)temp);
	}
	cout << mx;

	return 0;
}
