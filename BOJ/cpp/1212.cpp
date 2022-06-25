#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

string octobi(int x) {
	string ret;
	
	for (int i = 2; i >= 0; i--) {
		char temp = (x & (1 << i)) ? '1' : '0';
		ret.push_back(temp);	
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string num;
	cin >> num;
	
	vector<string> res;
	
	int a = num[0] - '0';
	if (!a) {
		cout << '0';
		return 0;
	}
	else {
		string temp = octobi(a);
		while (temp[0] == '0') {
			temp.erase(temp.begin());
		}
		res.push_back(temp);
	}
	for (int i = 1; i < num.size(); i++) {
		res.push_back(octobi(num[i] - '0'));
	}			
	
	for (auto i : res) {
		cout << i;
	}
}

