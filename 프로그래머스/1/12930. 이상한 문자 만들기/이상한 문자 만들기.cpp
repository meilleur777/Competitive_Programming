#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    int ptr=0;
    int n=s.size();
    string ret=""; 
    
    while (ptr<n) {
        while (ptr<n && s[ptr]==' ') {
            ptr++;
            ret.push_back(' ');
        }
        
        int now=0;
        while (ptr<n && s[ptr]!=' ') {
            if (now%2==0) ret.push_back(toupper(s[ptr]));
            else ret.push_back(tolower(s[ptr]));
            ptr++;
            now++;
        }
    }
    
    return ret;
}