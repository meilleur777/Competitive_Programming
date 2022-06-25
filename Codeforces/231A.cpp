#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	int res=0;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		
		if (a+b+c>=2) res++;
	}	
	cout << res << '\n';
}

