#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;	
	cin >> N;
	
	vector<int> X(N), Xd(N);
	for (int i=0; i<N; i++) {
		cin >> X[i];
		Xd[i] = X[i];
	}
	
	sort(Xd.begin(), Xd.end());
	Xd.erase(unique(Xd.begin(), Xd.end()), Xd.end());
		
	for (auto i:X)	{
		cout << lower_bound(Xd.begin(), Xd.end(), i) - Xd.begin() << ' ';
	}	
	cout << '\n';
}

