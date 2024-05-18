#include <bits/stdc++.h>
using namespace std;

vector<string> word={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    string ret="";
    int n=s.size();
    
    for (int i=0; i<n; i++) {
        cout << i << ' ';
        if (!isalpha(s[i])) ret.push_back(s[i]);
        else {
            for (int j=0; j<10; j++) {
                int m=word[j].size();
                if (i+m-1<n && s.substr(i, m)==word[j]) {
                    ret.push_back(char('0'+j));
                    i=i+m-1;
                }
            }
        }
    }
    
    return stoi(ret);
}
