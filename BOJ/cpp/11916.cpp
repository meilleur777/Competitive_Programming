#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	int cnt=0;
	vector<int> base(4, 0);

	function<void(void)> set=[&]() {
		for (int j=0; j<3; j++) {
			if (base[j]>1) {
				base[j+1]++;
				base[j]=1;
			}
		}
	};

	for (int i=0; i<n; i++) {
		int ord;
		cin >> ord;

		if (ord==1) {
			cnt++;
			if (cnt==4) {
				cnt=0;
				base[0]++;
				set();
			}
		}
		else if (ord==2) {
			cnt=0;
			base[0]++;
			set();
		}
		else {
			cnt++;
			for (int j=2; j>=0; j--) {
				base[j+1]+=base[j];
				base[j]=0;
			}
			if (cnt==4) {
				cnt=0;
				base[0]++;
				set();
			}
		}
	}

	cout << base[3];

	return 0;
}
