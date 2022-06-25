#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int A[200001];
int cnt[200001];
		int ans[200001]; 

bool compare(int a, int b) {
	return A[a] < A[b];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		
		memset(cnt, 0, sizeof(cnt));
		vector<int> v;
		for (int i = 0; i < n; i++)	{
			cin >> A[i];
			cnt[A[i]]++;
			if (cnt[A[i]] <= k) {
				v.push_back(i);
			}
		}
		sort(v.begin(), v.end());
		
		while (v.size() % k != 0) {
			v.pop_back();
		}
		
		for (int i = 0; i < v.size(); i++) {
			ans[v[i]] = i % k + 1;				
		}
		
		for (auto i : ans)	{
			cout << i << ' ';
		}
		cout << '\n';
	}
}

