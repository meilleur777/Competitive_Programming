#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k, t;
	cin >> n >> k >> t;
	vector<int> a;
	rep(i, n) {
		int b;
		cin >> b;
		if (b!=0) a.push_back(b);
	}
	if (a.empty()) {
		cout << "YES";
		return 0;
	}
	sort(a.begin(), a.end());
	int left=0, right=a.size()-1;
	while (left<right) {
		int need=k-a[right];
		if (need>t) {
			a[left]=1;
			break;
		}
		if (need<=a[left]) {
			a[left]-=need;
			t-=need;	
			right--;
		}
		else {
			t-=a[left];
			a[right]+=a[left];
			left++;
		}
	}
	if (a[left]>=k || a[left]==0) cout << "YES";
	else cout << "NO";

	return 0;
}
