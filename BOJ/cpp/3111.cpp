#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string A, T, leftS, rightS;
	cin >> A >> T;	
	bool turn = true;
	int left = 0, right = T.size() - 1;
	
	while (left <= right) {
		if (turn) {
			leftS.push_back(T[left++]);
			if (leftS.size() >= A.size()) {
				string temp(leftS.end() - A.size(), leftS.end());
				if (temp == A) {
					turn = !turn;
					for (int i = 0; i < A.size(); i++) leftS.pop_back();
				}
			}
		}
		else {
			rightS.push_back(T[right--]);
			if (rightS.size() >= A.size()) {
				string temp(rightS.end() - A.size(), rightS.end());
				reverse(temp.begin(), temp.end());
				if (temp == A) {
					turn = !turn;
					for (int i = 0; i < A.size(); i++) rightS.pop_back();
				}
			}
		}
	}
	reverse(rightS.begin(), rightS.end()); leftS += rightS;
	while(leftS.find(A) != string::npos) leftS.erase(leftS.find(A), A.size());
	cout << leftS << '\n';
}

