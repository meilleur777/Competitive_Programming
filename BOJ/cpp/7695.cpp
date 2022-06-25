#include <string.h>
#include <iostream>
using namespace std;

string str;
int cache[101][101]; 

/*str[begin]~str[end]의 가장 긴 regular brackets subsequence의 길이 반환*/
int solve(int begin, int end) {
	if (begin >= end) return 0;
	
	int& ret = cache[begin][end];
	if (ret != -1) return ret;
		
	ret = 0;
	if ((str[begin] == '(' && str[end] == ')') || (str[begin] == '[' && str[end] == ']'))
		ret = solve(begin + 1, end - 1) + 2;
	for (int i = begin; i < end; i++) ret = max(ret, solve(begin, i) + solve(i + 1, end));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while (1) {
		memset(cache, -1, sizeof(cache));
		cin >> str; if (str == "end") break;
		cout << solve(0, str.size() - 1) << '\n';
	}	
}

