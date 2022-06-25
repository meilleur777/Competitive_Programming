#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, result; cin >> a >> b >> c;
	if (a == b && b == c) result = 10000 + a * 1000;
	else if (a == b) result = 1000 + a * 100;
	else if (b == c) result = 1000 + b * 100;
	else if (c == a) result = 1000 + c * 100;
	else result = max({ a, b, c }) * 100;
	cout << result << '\n';
}

