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
	
	int N;
	cin >> N;
	
	if (N <= 125) cout << 4;
	else if (N <= 211) cout << 6;
	else cout << 8;
}

