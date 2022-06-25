#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	while (n--) {
		string temp;
		cin >> temp;
		
		if (temp.size()<=10) {
			cout << temp << '\n';
		} 
		else {
			cout << temp[0] << temp.size()-2 << *temp.rbegin() << '\n';
		}
	}	
}

