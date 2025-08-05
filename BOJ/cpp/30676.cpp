#include <bits/stdc++.h>
using namespace std;

int main() {
	int lbd;
	cin >> lbd;

	if (lbd>=620) cout << "Red";
	else if (lbd>=590) cout << "Orange";
	else if (lbd>=570) cout << "Yellow";
	else if (lbd>=495) cout << "Green";
	else if (lbd>=450) cout << "Blue";
	else if (lbd>=425) cout << "Indigo";
	else cout << "Violet";

	return 0;
}