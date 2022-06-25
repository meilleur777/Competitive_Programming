#include <iostream>
using namespace std;

string reverse(string::iterator& iter) {
	char head = *iter++;
	if (head == 'b' || head == 'w') return string(1, head);
	string upperLeft = reverse(iter);
	string upperRight = reverse(iter);
	string lowerLeft = reverse(iter);
	string lowerRight = reverse(iter);	
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		string compressed;
		cin >> compressed;
		string::iterator iter = compressed.begin();
		cout << reverse(iter) << '\n';
	}	
}

