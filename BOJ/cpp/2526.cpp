#include <iostream>
using namespace std;

bool check[100] = { false };

int main() {
	int N, P;
	cin >> N >> P;
	
	check[N] = true;
	int temp = N * N % P, count = 0;
	while (!check[temp]) {
		check[temp] = true;
		temp = N * temp % P;
	}
	while (check[temp]) {
		check[temp] = false;
		temp = N * temp % P;
		count++;
	}
	
	cout << count << '\n';
}

