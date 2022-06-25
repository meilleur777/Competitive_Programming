#include <stack>
#include <iostream>
using namespace std;

const string opening("({["), closing(")}]");

bool mismatch(const string& temp) {
	stack<char> s;
	for (auto i : temp) {
		if (opening.find(i) != string::npos) s.push(i);		
		else if (s.empty() || opening.find(s.top()) != closing.find(i)) return true;
		else s.pop();
	}
	return !s.empty();	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		string temp; cin >> temp;
		if (!mismatch(temp)) cout << "YES\n";
		else cout << "NO\n";
	}
}

