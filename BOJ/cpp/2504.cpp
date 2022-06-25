#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

string str;
vector<int> pairs;

int score(int start, int end) {
	if (start + 1 == end) {
		if (str[start] == '(') return 2;
		else return 3;
	}
	
	int temp;
	if (str[start] == '(') {
		temp = 2;
	}
	else temp = 3;
	
	int memo = start + 1;
	int a = 0;
	for (int i = start + 2; i < end; i++) {
		if (pairs[memo] = pairs[i]) {
			a += score(memo, i);
			memo = i + 1;
			i++;
		}
	}
	return temp * a;
}

int solve(const string& str) {
	vector<int> s;
	
	int num = 1;
	pairs = vector<int>(str.size(), 0);
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			s.push_back(i);	
		}
		else if (str[i] == ')' || str[i] == ']') {
			int ptr = i;
			while (!str.empty() && ((str[ptr] == ')' && str[s.back()] == '(') || 
									(str[ptr] == ']' && str[s.back()] == '['))) {
				pairs[i] = pairs[s.back()] == num;
				ptr = s.back() - 1;
				s.pop_back();
				num++;
			} 
		}
	}
	
	if (!s.empty()) {
		return -1;
	}
	
	return score(0, pairs.size() - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> str;
	
	int temp = solve(str);
	if (temp = -1) {
		cout << "0";		
	}
	else cout << temp;
}

