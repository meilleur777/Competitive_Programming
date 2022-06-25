#include <math.h>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	string password;
	cin >> N >> password;
	
	ll result = 0;	
	for (int i = 0; i < password.size(); i++) {
		ll temp = (pow(26, N - i) - 1) / 25;
		result += (password[i] - 'a') * temp + 1; 
	}	
	cout << result << '\n';
}

