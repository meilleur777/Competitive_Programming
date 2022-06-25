#include <vector>
#include <iostream>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int num = a * b * c;
    vector<int> mul, result(10, 0);
	while (num) {
		mul.push_back(num % 10);
		num /= 10;
	}    
	for (auto i : mul) result[i]++;
	for (auto i : result) cout << i << '\n';
}

