#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int cnt1=0, cnt2=0;
		int left=0, right=(int)s.size()-1;

		while (left<right) {
			if (s[left]==s[right]) {
				left++, right--;
			}
			else {
				left++;
				cnt1++;
			}
		}

		left=0, right=(int)s.size()-1;
		while (left<right) {
			if (s[left]==s[right]) {
				left++, right--;
			}
			else {
				right--;
				cnt2++;
			}
		}
		cout << min(min(cnt1, cnt2), 2) << '\n';
	}

	return 0;
}
