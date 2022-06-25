#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	priority_queue<int> upper;
	int one=0, zero=0, mone=0;
	priority_queue<int, vector<int>, greater<int>> lower;

	int n;
	cin >> n;
	rep(i, n) {
		int a;
		cin >> a;
		if (a>1) upper.push(a);
		else if (a==1) one++;
		else if (a==0) zero++;
		else if (a==-1) mone++;
		else lower.push(a);
	}
	int ans=0;
	while (upper.size()>1) {
		int a=upper.top();
		upper.pop();
		int b=upper.top();
		upper.pop();
		ans+=a*b;
	}
	if (!upper.empty()) ans+=upper.top();
	while (lower.size()>1) {
		int a=lower.top();
		lower.pop();
		int b=lower.top();
		lower.pop();
		ans+=a*b;
	}
	if (!lower.empty() && mone!=0) {
		ans+=-1*lower.top();
		lower.pop();
		mone--;
	}
	if (!lower.empty() && zero!=0) {
		zero--;
		lower.pop();
	}
	if (!lower.empty()) ans+=lower.top();
	ans+=one;
	ans+=mone/2;
	mone%=2;
	ans-=mone-min(zero, mone);
	cout << ans;

	return 0;
}
