#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll N;
	cin >> N;
	
	int i = 1;
	while (N > pow(10, i)) {
		N += (ll)pow(10, i - 1) * 5;
		N /= (ll)pow(10, i);
		N *= (ll)pow(10, i);
		i++;
	}
	cout << N;
}

