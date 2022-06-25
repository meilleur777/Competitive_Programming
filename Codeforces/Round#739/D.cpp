#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

bool check(const string& num) {
	cout << num << '\n';
	ll n = stoll(num);
	
	while (n % 2 == 0) {
		n /= 2;
	} 
	
	if (n == 1) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		string num;
		cin >> num;
		
		queue<pair<string, int> > q;
		q.push({ num, 0 });
		
		while (!q.empty()) {
			string now = q.front().first;
			int time = q.front().second;
			q.pop();
			
			if (!now.empty() && now[0] != '0' && check(now)) {
				cout << time << '\n';
				break;
			}
			
			for (int i = 0; i < 10; i += 2) {
				string temp = now;
				temp.push_back(i + '0');
				q.push({ temp, time + 1 });
			}
			
			for (int i = 0; i < now.size(); i++) {
				string temp = now;
				temp.erase(temp.begin() + i);
				q.push({ temp, time + 1 });
			}
		}	
	}	
}

