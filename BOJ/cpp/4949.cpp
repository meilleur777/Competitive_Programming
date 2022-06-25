#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

const string opening("(["), closing(")]");

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while (1) {
    	string temp; getline(cin, temp);
        if (temp == ".") break;
        
        stack<int> s;
        bool flag = true;
        
        for (auto x : temp) {
	        if (x != '(' && x != ')' && x != '[' && x != ']') continue;
	        
		    if (opening.find(x) != string::npos) s.push(x);
		    else if (s.empty() || opening.find(s.top()) != closing.find(x)) {
		        flag = false;
		        break;
		    }
		    else s.pop();
		}
		
	    if (flag && s.empty()) cout << "yes\n";
	    else cout << "no\n";
    }
}

